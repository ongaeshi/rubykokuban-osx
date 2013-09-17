#pragma once

#include "ofColor.h"

struct mrb_state;
struct mrb_value;

//----------------------------------------------------------
namespace rubykokuban {

class BindColor {
public:
    static void Bind(mrb_state* aMrb);
    static mrb_value ToMrb(mrb_state* aMrb, ofColor* aPtr);
    static ofColor* ToPtr(mrb_state* aMrb, mrb_value aValue);
};

}
