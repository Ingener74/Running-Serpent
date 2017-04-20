#include <iostream>
#include "Protocol.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    try {
        auto startServerRequest = StartServerRequest().
                putCredits(10000).
                putNumberOfBalls(4).
                putGameName("Game57").
                putState(100).
                putState100(State100ServerRequest().putFoo("Quuuz")).
                putState101(State101ServerRequest().putBar(43));

        auto buffer = startServerRequest.getBuffer();

        cout << "Start Server Request " << endl << startServerRequest << endl;

        StartServerResponse sr;

        auto freeBuffer = FreeServerRequest().
                putBall(8).
                getBuffer();

    } catch (const exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}