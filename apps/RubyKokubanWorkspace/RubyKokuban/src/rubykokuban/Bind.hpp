#pragma once

#include "rubykokuban/BindInput.hpp"
#include "rubykokuban/BindColor.hpp"
#include "rubykokuban/BindImage.hpp"

struct mrb_state;
struct mrb_value;

namespace rubykokuban {
    class Input;
}

//----------------------------------------------------------
namespace rubykokuban {

class Bind {
public:
    static void All(mrb_state* mrb)
    {
        Application(mrb);
        BindColor::Bind(mrb);
        Graphics(mrb);
        BindImage::Bind(mrb);
        BindInput::Bind(mrb);
        Math(mrb);
    }

    static void Application(mrb_state* mrb);
    static void Color(mrb_state* mrb);
    static void Graphics(mrb_state* mrb);
    static void Image(mrb_state* mrb);
    static void Input(mrb_state* mrb);
    static void Math(mrb_state* mrb);
};

}
