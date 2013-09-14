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

    const char* rootDir    = argv[1];
    const char* scriptPath = argv[2];

    if (isDebugMode(argc, argv)) {
        rootDir    = "/Users/ongaeshi/Documents/rubykokuban-osx/apps/RubyKokubanWorkspace/RubyKokuban/src/"; // dirty code
        scriptPath = "sample.rb";
    }

    // printf("rootDir: %s, scriptPath: %s\n", rootDir, scriptPath);

    ofAppGlutWindow window;                       // create a window
    ofSetupOpenGL(&window, 1024, 768, OF_WINDOW); // set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
    ofRunApp(new testApp(rootDir, scriptPath));   // start the app
}
