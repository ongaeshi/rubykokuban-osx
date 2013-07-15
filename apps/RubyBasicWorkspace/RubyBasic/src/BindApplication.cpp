#include "BindApplication.hpp"

#include "mruby.h"
#include "ofAppRunner.h"

namespace {
    static mrb_value get_frame_rate(mrb_state *mrb, mrb_value self)
    {
        return mrb_float_value(mrb, ofGetFrameRate());
    }
}

//--------------------------------------------------------------------------------
void BindApplication::Bind(mrb_state* mrb)
{
    mrb_define_method(mrb, mrb->kernel_module, "get_frame_rate", get_frame_rate, MRB_ARGS_REQ(0));
}

//EOF
