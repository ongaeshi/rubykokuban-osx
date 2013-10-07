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
    // printf("argc: %d\n", argc);
    // for (int i = 0; i < argc; ++i) {
    //     printf("argv[%d]: \"%s\"\n", i, argv[i]);
    // }

    const char* scriptPath;

    if (!isDebugMode(argc, argv)) {
        scriptPath = argv[1];
    } else {
        scriptPath = "/Users/ongaeshi/Documents/rubykokuban-osx/apps/RubyKokubanWorkspace/RubyKokuban/src/sample.rb"; // Need full path (Dirty code)
    }

    ofAppGlutWindow window;                       // create a window
    ofSetupOpenGL(&window, 1024, 768, OF_WINDOW); // set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
    ofRunApp(new testApp(scriptPath));            // start the app
}
