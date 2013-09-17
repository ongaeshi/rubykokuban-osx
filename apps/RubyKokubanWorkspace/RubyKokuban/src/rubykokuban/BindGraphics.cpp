#include "rubykokuban/Bind.hpp"

#include "mruby.h"
#include "mrubybind.h"
#include "ofGraphics.h"

namespace rubykokuban {

namespace {
    static mrb_value set_fill(mrb_state *mrb, mrb_value self)
    {
        mrb_bool is_fill;

        if (mrb_get_args(mrb, "|b", &is_fill) == 0) {
            ofFill();
            return mrb_bool_value(true);
        } else {
            if (is_fill)
                ofFill();
            else
                ofNoFill();
            return mrb_bool_value(is_fill);
        }
    }

    static void set_no_fill()                                                        { ofNoFill(); }
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

//----------------------------------------------------------
void BindGraphics(mrb_state* mrb)
{
    mrubybind::MrubyBind b(mrb);

    mrb_define_method(mrb, mrb->kernel_module, "set_fill", set_fill, MRB_ARGS_OPT(1));
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

}
