#include <iostream>
#include "Protocol.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    try {
        auto buffer = StartRequest().
                putCredits(10000).
                putNumberOfBalls(4).
                putGameName("Game57").
                putState(101).
                putState100(StartRequest::State100Request().putFoo("Quuuz")).
                putState101(StartRequest::State101Request().putBar(43)).
                getBuffer();

        StartResponse sr;

        auto freeBuffer = FreeRequest().
                getBuffer();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}