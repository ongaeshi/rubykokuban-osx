#include "Input.hpp"

namespace rubybasic {
//------------------------------------------------------------
Input::Input()
: mMouse()
{
}

//------------------------------------------------------------
void Input::update()
{
    mMouse.update();
}

}
