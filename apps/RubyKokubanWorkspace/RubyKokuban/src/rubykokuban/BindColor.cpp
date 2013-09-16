#include "rubykokuban/Bind.hpp"

#include "mruby.h"
#include "mruby/value.h"

namespace rubykokuban {

namespace {
mrb_value hex(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value hsb(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value white(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value black(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value clone(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value to_hex(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value clamp(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value invert(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value normalize(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value lerp(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value hue(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value saturation(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value brightness(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value lightness(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value equal(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value not_equal(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value plus(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value minus(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value mul(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value div(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value aref(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

}

void Bind::Color(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Color", mrb->object_class);

    mrb_define_class_method(mrb, cc, "hex"               , hex                 , MRB_ARGS_ARG(1, 1));
    mrb_define_class_method(mrb, cc, "hsb"               , hsb                 , MRB_ARGS_ARG(3, 1));
    mrb_define_class_method(mrb, cc, "white"             , white               , MRB_ARGS_NONE());
    mrb_define_class_method(mrb, cc, "black"             , black               , MRB_ARGS_NONE());

    mrb_define_method(mrb, cc,       "clone"             , clone               , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "to_hex"            , to_hex              , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "clamp"             , clamp               , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "invert"            , invert              , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "normalize"         , normalize           , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "lerp"              , lerp                , MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,       "hue"               , hue                 , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "saturation"        , saturation          , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "brightness"        , brightness          , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "lightness"         , lightness           , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "=="                , equal               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "!="                , not_equal           , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "+"                 , plus                , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "-"                 , minus               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "*"                 , mul                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "/"                 , div                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "[]"                , aref                , MRB_ARGS_REQ(1));
}

}
