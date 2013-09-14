#pragma once

#include "ofMain.h"
#include "rubykokuban/ScriptEngine.hpp"
#include "rubykokuban/Input.hpp"

struct mrb_state;

//--------------------------------------------------------------------------------
class testApp : public ofBaseApp {
public:
    testApp(const char* aRootDir, const char* aScriptPath);

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

private:
    const char*               mRootDir;
    rubykokuban::Input        mInput;
    rubykokuban::ScriptEngine mScriptEngine;
};

//EOF
