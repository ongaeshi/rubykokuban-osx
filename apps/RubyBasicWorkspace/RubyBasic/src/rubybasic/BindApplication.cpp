#include "rubybasic/BindApplication.hpp"

#include "mruby.h"
#include "mrubybind.h"
#include "ofAppRunner.h"

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
}

//EOF
