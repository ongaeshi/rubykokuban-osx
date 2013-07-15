#include "BindGraphics.hpp"

#include "mruby.h"
#include "ofGraphics.h"

namespace {
    static mrb_value circle(mrb_state *mrb, mrb_value self)
    {
        mrb_float x, y, radius;
        mrb_get_args(mrb, "fff", &x, &y, &radius);
        // printf("%f, %f, %f\n", x, y, radius);
        ofCircle(x, y, radius);
        return mrb_nil_value();
    }

    static mrb_value set_color(mrb_state *mrb, mrb_value self)
    {
        mrb_int r, g, b;
        mrb_get_args(mrb, "iii", &r, &g, &b);
        ofSetColor(r, g, b);
        return mrb_nil_value();
    }

    static mrb_value text(mrb_state *mrb, mrb_value self)
    {
        const char* str;
        mrb_float x, y;
        mrb_get_args(mrb, "zff", &str, &x, &y);
        ofDrawBitmapString(str, x, y);
        return mrb_nil_value();
    }
}

//--------------------------------------------------------------------------------
void BindGraphics::Bind(mrb_state* mrb)
{
    mrb_define_method(mrb, mrb->kernel_module, "circle",    circle,    MRB_ARGS_REQ(3));
    mrb_define_method(mrb, mrb->kernel_module, "set_color", set_color, MRB_ARGS_REQ(3));
    mrb_define_method(mrb, mrb->kernel_module, "text",      text,      MRB_ARGS_REQ(3));
}

//EOF
