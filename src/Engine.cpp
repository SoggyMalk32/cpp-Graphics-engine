#include "Engine.h"
#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

namespace proto {

struct Engine::Impl {
    EngineConfig cfg;
    std::atomic<bool> running{false};
    std::atomic<bool> exitRequested{false};

    Impl(const EngineConfig& c): cfg(c) {}
};

Engine::Engine(const EngineConfig& cfg)
: impl_(std::make_unique<Impl>(cfg))
{
    // Initialize logging, platform, renderer, etc. (deferred)
    std::cout << "Engine: init (title=" << cfg.windowTitle << ")\n";
}

Engine::~Engine() {
    requestExit();
    // Join / cleanup
    std::cout << "Engine: shutdown\n";
}

void Engine::run() {
    impl_->running = true;
    using clock = std::chrono::steady_clock;
    auto last = clock::now();
    while (!impl_->exitRequested) {
        auto now = clock::now();
        std::chrono::duration<double> dt = now - last;
        last = now;
        double delta = dt.count();

        // TODO: poll platform events, update scene, render frame
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // placeholder
    }
    impl_->running = false;
}

void Engine::requestExit() {
    impl_->exitRequested = true;
}

} // namespace proto
