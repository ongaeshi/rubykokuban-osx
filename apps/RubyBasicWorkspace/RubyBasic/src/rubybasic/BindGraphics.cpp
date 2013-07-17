#include "rubybasic/BindGraphics.hpp"

#include "mruby.h"
#include "mrubybind.h"
#include "ofGraphics.h"

namespace {
    static void set_fill()                                                           { ofFill(); }
    static void set_no_fill()                                                        {  ofNoFill(); }
    static bool is_fill()                                                            { return ofGetFill() == OF_FILLED; }
    static void set_line_width(float width)                                          { ofSetLineWidth(width); }
    static void set_color(int r, int g, int b)                                       { ofSetColor(r, g, b); }
    static void set_background(int r, int g, int b)                                  { ofBackground(r, g, b); }
    static void triangle(float x1, float y1, float x2, float y2, float x3, float y3) { ofTriangle(x1, y1, x2, y2, x3, y3); }
    static void circle(float x, float y, float radius)                               { ofCircle(x, y, radius); }
    static void ellipse(float x, float y, float width, float height)                 { ofEllipse(x, y, width, height); }
    static void line(float x1, float y1, float x2, float y2)                         { ofLine(x1, y1, x2, y2); }
    static void rect(float x, float y, float w, float h)                             { ofRect(x, y, w, h); }
    static void rect_rounded(float x, float y, float w, float h, float r)            { ofRectRounded(x, y, w, h, r); }
    static void text(string str, float x, float y)                                   { ofDrawBitmapString(str, x, y); }
}

//--------------------------------------------------------------------------------
void BindGraphics::Bind(mrb_state* mrb)
{
    mrubybind::MrubyBind b(mrb);
    b.bind("set_fill", set_fill);
    b.bind("set_no_fill", set_no_fill);
    b.bind("is_fill", is_fill);
    b.bind("set_line_width", set_line_width);
    b.bind("set_color", set_color);
    b.bind("set_background", set_background);
    b.bind("triangle", triangle);
    b.bind("circle", circle);
    b.bind("ellipse", ellipse);
    b.bind("line", line);
    b.bind("rect", rect);
    b.bind("rect_rounded", rect_rounded);
    b.bind("text", text);
}

//EOF
