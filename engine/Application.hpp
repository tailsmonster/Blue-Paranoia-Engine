#pragma once

class Application {
public:
    bool init();
    int run();         // Returns 0 to continue, non-zero to exit
    void shutdown();
};
