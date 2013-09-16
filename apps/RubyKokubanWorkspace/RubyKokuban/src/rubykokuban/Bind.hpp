#pragma once

struct mrb_state;

//----------------------------------------------------------
namespace rubykokuban {

class Bind {
public:
    static void Color(mrb_state* mrb);
};

}
