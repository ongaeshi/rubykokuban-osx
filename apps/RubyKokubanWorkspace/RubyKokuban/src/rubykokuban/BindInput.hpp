#pragma once

namespace rubykokuban {
    class Input;
}

struct mrb_state;

//--------------------------------------------------------------------------------
namespace rubykokuban {
class BindInput {
public:
    static void Setup(Input& aInput);
    static void Bind(mrb_state* mrb);
};

}

//EOF

