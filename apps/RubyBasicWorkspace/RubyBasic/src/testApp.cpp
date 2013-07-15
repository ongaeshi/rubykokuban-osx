#include "testApp.hpp"

#include "BindInput.hpp"
#include "mruby.h"
#include "mruby/class.h"
#include "mruby/compile.h"
#include <stdio.h>
#include <unistd.h>

//--------------------------------------------------------------
testApp::testApp(const char* aFilename)
: mInput()
, mScriptEngine(aFilename)
{
    rubybasic::BindInput::Setup(mInput);
}

//--------------------------------------------------------------
void testApp::setup()
{
    // setup openFrameworks
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    // ofBackground(255, 255, 255);

    // bind & call function
    mScriptEngine.setup();
}

//--------------------------------------------------------------
void testApp::update()
{
    mInput.update();
    mScriptEngine.funcallIf("update");
}

//--------------------------------------------------------------
void testApp::draw()
{
    mScriptEngine.funcallIf("draw");
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    if (key == 18) // Ctrl+R
        mScriptEngine.reload();

    // cout << "keyPressed " << key << endl;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
    // cout << "keyReleased " << key << endl;
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{
    mInput.mouse().setInternalPos(x, y);

    mScriptEngine.funcallIf("mouse_moved", mrb_fixnum_value(x), mrb_fixnum_value(y));
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{
    mInput.mouse().setInternalPos(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    mInput.mouse().setInternalPos(x, y);
    mInput.mouse().setInternalPress(button);
    
    mScriptEngine.funcallIf("mouse_pressed", mrb_fixnum_value(x), mrb_fixnum_value(y), mrb_fixnum_value(button));
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
    mInput.mouse().setInternalPos(x, y);
    mInput.mouse().setInternalRelease(button);

    mScriptEngine.funcallIf("mouse_released", mrb_fixnum_value(x), mrb_fixnum_value(y), mrb_fixnum_value(button));
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{
}

//EOF
