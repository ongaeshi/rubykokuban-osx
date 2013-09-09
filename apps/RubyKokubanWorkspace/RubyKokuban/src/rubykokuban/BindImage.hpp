#pragma once

struct mrb_state;

//----------------------------------------------------------
namespace rubykokuban {

class BindImage {
public:
    static void Bind(mrb_state* mrb);
};

}
