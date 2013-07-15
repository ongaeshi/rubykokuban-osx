#pragma once

struct mrb_state;

//--------------------------------------------------------------------------------
class BindApplication {
public:
    static void Bind(mrb_state* mrb);
};

//EOF

