#include <iostream>
#include "Protocol.h"

using namespace std;

int main() {
    try {
        auto startServerRequest = StartServerRequest().
                putCredits(10000).
                putNumberOfBalls(4).
                putGameName("Game57").
                putState(100).
                putState100(State100ServerRequest().putFoo("Quuuz")).
                putState101(State101ServerRequest().putBar(43));
        cout << "Start Server Request" << startServerRequest << endl;

        auto startClientResponse = StartClientResponse(startServerRequest.getBuffer());
        cout << "Start Server Response" << startClientResponse << endl;

        auto freeServerRequest = FreeServerRequest().
                putBall(8);
        cout << "Free Server Request" << freeServerRequest << endl;

        auto freeClientResponse = FreeClientResponse(freeServerRequest.getBuffer());
        cout << "Free Client Response" << freeClientResponse << endl;

        cout << endl;

    } catch (const exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}