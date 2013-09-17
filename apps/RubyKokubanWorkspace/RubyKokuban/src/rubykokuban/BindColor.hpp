#pragma once

#include "mruby.h"
#include "ofColor.h"

//----------------------------------------------------------
namespace rubykokuban {

class BindColor {
public:
    static mrb_value ToMrb(mrb_state* aMrb, ofColor* aPtr);
    static mrb_value ToMrb(mrb_state* aMrb, struct RClass* aClass, ofColor* aPtr);
    static ofColor* ToPtr(mrb_state* aMrb, mrb_value aValue);
    static void Bind(mrb_state* aMrb);
};

}
