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

float LIMIT = 255;

mrb_value initialize(mrb_state *mrb, mrb_value self)
{
    mrb_int r, g, b, a = LIMIT;
    mrb_get_args(mrb, "iii|i", &r, &g, &b, &a);

    ofColor* obj = new ofColor(r, g, b, a);

    return BindColor::ToMrb(mrb, mrb_class_ptr(self), obj);
}

mrb_value hex(mrb_state *mrb, mrb_value self)
{
    mrb_int h, a = LIMIT;
    mrb_get_args(mrb, "i|f", &h, &a);

    ofColor* obj = new ofColor(ofColor::fromHex(h, a));

    return BindColor::ToMrb(mrb, mrb_class_ptr(self), obj);
}

mrb_value hsb(mrb_state *mrb, mrb_value self)
{
    mrb_float hue, saturation, brightness, alpha = LIMIT;
    mrb_get_args(mrb, "fff|f", &hue, &saturation, &brightness, &alpha);

    ofColor* obj = new ofColor(ofColor::fromHsb(hue, saturation, brightness, alpha));

    return BindColor::ToMrb(mrb, mrb_class_ptr(self), obj);
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

mrb_value r_set(mrb_state *mrb, mrb_value self)
{
    mrb_int r;
    mrb_get_args(mrb, "i", &r);
    obj(self).r = r;
    return mrb_nil_value();
}

mrb_value g(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(obj(self).g);
}

mrb_value g_set(mrb_state *mrb, mrb_value self)
{
    mrb_int g;
    mrb_get_args(mrb, "i", &g);
    obj(self).g = g;
    return mrb_nil_value();
}

mrb_value b(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(obj(self).b);
}

mrb_value b_set(mrb_state *mrb, mrb_value self)
{
    mrb_int b;
    mrb_get_args(mrb, "i", &b);
    obj(self).b = b;
    return mrb_nil_value();
}

mrb_value a(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(obj(self).a);
}

mrb_value a_set(mrb_state *mrb, mrb_value self)
{
    mrb_int a;
    mrb_get_args(mrb, "i", &a);
    obj(self).a = a;
    return mrb_nil_value();
}

mrb_value clone(mrb_state *mrb, mrb_value self)
{
    return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self)));
}

mrb_value to_hex(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(obj(self).getHex());
}

mrb_value clamp(mrb_state *mrb, mrb_value self)
{
    return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self).getClamped()));
}

mrb_value invert(mrb_state *mrb, mrb_value self)
{
    return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self).getInverted()));
}

mrb_value normalize(mrb_state *mrb, mrb_value self)
{
    return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self).getNormalized()));
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

//----------------------------------------------------------
mrb_value BindColor::ToMrb(mrb_state* mrb, ofColor* aPtr)
{
    return ToMrb(mrb, mrb_class_get(mrb, "Color"), aPtr);
}

//----------------------------------------------------------
mrb_value BindColor::ToMrb(mrb_state* mrb, struct RClass* aClass, ofColor* aPtr)
{
    struct RData *data = mrb_data_object_alloc(mrb, aClass, aPtr, &data_type);
    return mrb_obj_value(data);
}

//----------------------------------------------------------
ofColor* BindColor::ToPtr(mrb_state* mrb, mrb_value aValue)
{
    if (!mrb_obj_is_instance_of(mrb, aValue, mrb_class_get(mrb, "Color"))) {
        mrb_raise(mrb, E_TYPE_ERROR, "wrong argument class");
    }

    return static_cast<ofColor*>(DATA_PTR(aValue));
}

//----------------------------------------------------------
void BindColor::Bind(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Color", mrb->object_class);

    mrb_define_class_method(mrb, cc, "new"               , initialize          , MRB_ARGS_ARG(3, 1));
    mrb_define_class_method(mrb, cc, "hex"               , hex                 , MRB_ARGS_ARG(1, 1));
    mrb_define_class_method(mrb, cc, "hsb"               , hsb                 , MRB_ARGS_ARG(3, 1));
    mrb_define_class_method(mrb, cc, "white"             , white               , MRB_ARGS_NONE());
    mrb_define_class_method(mrb, cc, "black"             , black               , MRB_ARGS_NONE());

    mrb_define_method(mrb, cc,       "r"                 , r                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "r="                , r_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "g"                 , g                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "g="                , g_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "b"                 , b                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "b="                , b_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "a"                 , a                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "a="                , a_set               , MRB_ARGS_REQ(1));
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
    mrb_define_method(mrb, cc,       "+"                 , add                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "-"                 , sub                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "*"                 , mul                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "/"                 , div                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "[]"                , aref                , MRB_ARGS_REQ(1));
}

}
