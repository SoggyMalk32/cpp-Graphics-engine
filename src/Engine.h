#pragma once
#include <memory>
#include <string>

namespace proto {

struct EngineConfig {
    std::string windowTitle = "ProtoEngine";
    int windowWidth = 1280;
    int windowHeight = 720;
    bool enableValidation = true;
};

class Engine {
public:
    explicit Engine(const EngineConfig& cfg);
    ~Engine();

    // Non-copyable, but movable if you want
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    // Main loop control
    void run();            // blocking main loop
    void requestExit();    // signal to exit next frame

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace proto
