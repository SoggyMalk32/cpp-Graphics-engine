#include "Engine.h"
#include <iostream>

int main(int argc, char** argv) {
    proto::EngineConfig cfg;
    cfg.windowTitle = "ProtoEngine - Early Build";
    proto::Engine engine(cfg);
    std::cout << "Starting engine...\n";
    engine.run();
    std::cout << "Engine stopped.\n";
    return 0;
}
