#pragma once

namespace rubykokuban {
    class Input;
}

struct mrb_state;

//----------------------------------------------------------
namespace rubykokuban {

class Bind {
public:
    static void All(mrb_state* mrb)
    {
        Application(mrb);
        Color(mrb);
        Graphics(mrb);
        Image(mrb);
        Input(mrb);
        Math(mrb);
    }

    static void Application(mrb_state* mrb);
    static void Color(mrb_state* mrb);
    static void Graphics(mrb_state* mrb);
    static void Image(mrb_state* mrb);
    static void Input(mrb_state* mrb);
    static void Math(mrb_state* mrb);

    static void InputSetup(::rubykokuban::Input& aInput);
};

}
