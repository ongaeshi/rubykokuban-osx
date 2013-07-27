#include "rubybasic/BindMath.hpp"

#include "mruby.h"
#include "mrubybind.h"
#include "ofMath.h"

namespace {
    static mrb_value srand(mrb_state *mrb, mrb_value self)
    {
        mrb_int seed;

        if (mrb_get_args(mrb, "|i", 
                         &seed) == 1) {
            ofSeedRandom(seed);
        } else {
            ofSeedRandom();
        }

        return mrb_nil_value();
    }

    static mrb_value rand(mrb_state *mrb, mrb_value self)
    {
        mrb_float max;
    
        if (mrb_get_args(mrb, "|f", &max) == 1) {
            return mrb_float_value(mrb, ofRandom(max));
        } else {
            return mrb_float_value(mrb, ofRandomuf());
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