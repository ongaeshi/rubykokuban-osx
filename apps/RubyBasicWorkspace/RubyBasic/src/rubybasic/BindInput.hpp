#pragma once

namespace rubybasic {
    class Input;
}

struct mrb_state;

//--------------------------------------------------------------------------------
namespace rubybasic {
class BindInput {
public:
    static void Setup(Input& aInput);
    static void Bind(mrb_state* mrb);
};

}

//EOF

