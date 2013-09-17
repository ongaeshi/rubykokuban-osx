#include "rubykokuban/BindColor.hpp"

#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/value.h"
#include "ofColor.h"

namespace rubykokuban {

namespace {
ofColor& obj(mrb_value self)
{
    return *((ofColor*)DATA_PTR(self));
}

void free(mrb_state *mrb, void *p)
{
    if (p) {
        delete ((ofColor*)p);
    }
}

struct mrb_data_type data_type = { "rubykokuban_color", free };

mrb_value initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int r, g, b, a = 255;
    mrb_get_args(mrb, "iii|i", &r, &g, &b, &a);

    ofColor* obj = new ofColor(r, g, b, a);

    return BindColor::ToMrb(mrb, mrb_class_ptr(self), obj);
}

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

mrb_value r(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(obj(self).r);
}

mrb_value g(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(obj(self).g);
}

mrb_value b(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(obj(self).b);
}

mrb_value a(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(obj(self).a);
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

mrb_value add(mrb_state *mrb, mrb_value self)
{
    // return self;
    return mrb_nil_value();
}

mrb_value sub(mrb_state *mrb, mrb_value self)
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

mrb_value BindColor::ToMrb(mrb_state* aMrb, ofColor* aPtr)
{
    return ToMrb(aMrb, mrb_class_get(aMrb, "Color"), aPtr);
}

mrb_value BindColor::ToMrb(mrb_state* aMrb, struct RClass* aClass, ofColor* aPtr)
{
    struct RData *data = mrb_data_object_alloc(aMrb, aClass, aPtr, &data_type);
    return mrb_obj_value(data);
}

ofColor* BindColor::ToPtr(mrb_state* aMrb, mrb_value aValue)
{
    return NULL;
}

void BindColor::Bind(mrb_state* aMrb)
{
    struct RClass *cc = mrb_define_class(aMrb, "Color", aMrb->object_class);

    mrb_define_class_method(aMrb, cc, "new"               , initialize          , MRB_ARGS_ARG(3, 1));
    mrb_define_class_method(aMrb, cc, "hex"               , hex                 , MRB_ARGS_ARG(1, 1));
    mrb_define_class_method(aMrb, cc, "hsb"               , hsb                 , MRB_ARGS_ARG(3, 1));
    mrb_define_class_method(aMrb, cc, "white"             , white               , MRB_ARGS_NONE());
    mrb_define_class_method(aMrb, cc, "black"             , black               , MRB_ARGS_NONE());

    mrb_define_method(aMrb, cc,       "r"                 , r                   , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "g"                 , g                   , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "b"                 , b                   , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "a"                 , a                   , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "clone"             , clone               , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "to_hex"            , to_hex              , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "clamp"             , clamp               , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "invert"            , invert              , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "normalize"         , normalize           , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "lerp"              , lerp                , MRB_ARGS_REQ(2));
    mrb_define_method(aMrb, cc,       "hue"               , hue                 , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "saturation"        , saturation          , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "brightness"        , brightness          , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "lightness"         , lightness           , MRB_ARGS_NONE());
    mrb_define_method(aMrb, cc,       "=="                , equal               , MRB_ARGS_REQ(1));
    mrb_define_method(aMrb, cc,       "!="                , not_equal           , MRB_ARGS_REQ(1));
    mrb_define_method(aMrb, cc,       "+"                 , add                 , MRB_ARGS_REQ(1));
    mrb_define_method(aMrb, cc,       "-"                 , sub                 , MRB_ARGS_REQ(1));
    mrb_define_method(aMrb, cc,       "*"                 , mul                 , MRB_ARGS_REQ(1));
    mrb_define_method(aMrb, cc,       "/"                 , div                 , MRB_ARGS_REQ(1));
    mrb_define_method(aMrb, cc,       "[]"                , aref                , MRB_ARGS_REQ(1));
}


}
