#include "rubybasic/BindMath.hpp"

#include "mruby.h"
#include "mrubybind.h"
#include "ofMath.h"

namespace {
    static mrb_value srand(mrb_state *mrb, mrb_value self)
    {
        // support srand(int)
        ofSeedRandom();

        return mrb_nil_value();
    }

    static mrb_value rand(mrb_state *mrb, mrb_value self)
    {
        mrb_float max;
    
        if (mrb_get_args(mrb, "|f", &max) == 0) {
            return mrb_float_value(mrb, ofRandomuf());
        } else {
            return mrb_float_value(mrb, ofRandom(max));
        }
    }
}

//--------------------------------------------------------------------------------
void BindMath::Bind(mrb_state* mrb)
{
    mrb_define_method(mrb, mrb->kernel_module, "srand", srand, MRB_ARGS_REQ(0));
    mrb_define_method(mrb, mrb->kernel_module, "rand", rand, MRB_ARGS_OPT(1));
}

//EOF
