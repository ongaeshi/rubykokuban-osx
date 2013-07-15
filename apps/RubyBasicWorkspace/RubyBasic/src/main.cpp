#include "testApp.hpp"
#include "ofAppGlutWindow.h"

namespace {
    bool isDebugMode(int argc, const char* argv[])
    {
        return argc == 3
            && string(argv[1]) == "-NSDocumentRevisionsDebugMode"
            && string(argv[2]) == "YES";
    }
}

//--------------------------------------------------------------
int main(int argc, const char* argv[])
{
#if 0
    printf("argc: %d\n", argc);

    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]: \"%s\"\n", i, argv[i]);
    }
#endif

    const char* filename = argv[1];

    if (isDebugMode(argc, argv))
        filename = "../src/sample.rb";

    ofAppGlutWindow window; // create a window
    // set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
    ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);
    ofRunApp(new testApp(filename)); // start the app
}
