#include "rubybasic/BindApplication.hpp"

#include "mruby.h"
#include "mrubybind.h"
#include "ofAppRunner.h"
#include "ofMath.h"

namespace {
    static mrb_value get_frame_rate(mrb_state *mrb, mrb_value self)
    {
        return mrb_float_value(mrb, ofGetFrameRate());
    }

    static void set_window_pos(int x, int y) { ofSetWindowPosition(x, y); }
    static void set_window_size(int width, int height) { ofSetWindowShape(width, height); }
    static int window_pos_x() { return ofGetWindowPositionX(); }
    static int window_pos_y() { return ofGetWindowPositionY(); }
    static int window_width() { return ofGetWidth(); }
    static int window_height() { return ofGetHeight(); }

    static mrb_value srand(mrb_state *mrb, mrb_value self)
    {
        // support srand(int)
        ofSeedRandom();

        return mrb_nil_value();
    }

// 動かなかった
// static float rand(float max) { return ofRandom(max); }

static mrb_value rand(mrb_state *mrb, mrb_value self)
{
    mrb_float max;

    if (mrb_get_args(mrb, "|f", &max) == 0) {
        return mrb_float_value(mrb, ofRandomuf());
    } else {
        return mrb_float_value(mrb, ofRandom(max));
    }

    // return mrb_float_value(mrb, 100.0f);
}

}

//--------------------------------------------------------------------------------
void BindApplication::Bind(mrb_state* mrb)
{
    mrubybind::MrubyBind b(mrb);

    mrb_define_method(mrb, mrb->kernel_module, "get_frame_rate", get_frame_rate, MRB_ARGS_REQ(0));
    b.bind("set_window_pos", set_window_pos);
    b.bind("set_window_size", set_window_size);
    b.bind("window_pos_x", window_pos_x);
    b.bind("window_pos_y", window_pos_y);
    b.bind("window_width", window_width);
    b.bind("window_height", window_height);

    mrb_define_method(mrb, mrb->kernel_module, "srand", srand, MRB_ARGS_REQ(0));
    mrb_define_method(mrb, mrb->kernel_module, "rand", rand, MRB_ARGS_OPT(1));
}

//EOF
