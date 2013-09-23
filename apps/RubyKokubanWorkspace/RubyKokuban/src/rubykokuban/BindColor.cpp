#include "rubykokuban/BindColor.hpp"

#include "mruby/array.h"
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

mrb_value set(mrb_state *mrb, mrb_value self)
{
    mrb_value *argv;
    int argc;

    mrb_get_args(mrb, "*", &argv, &argc);

    switch (argc) {
    case 1:
        // set(color)
        obj(self).set(*BindColor::ToPtr(mrb, mrb_obj_class(mrb, self), argv[0]));
        break;
    case 3:
        // set(r, g, b)
        obj(self).set(
            mrb_fixnum(mrb_Integer(mrb, argv[0]))
            , mrb_fixnum(mrb_Integer(mrb, argv[1]))
            , mrb_fixnum(mrb_Integer(mrb, argv[2]))
            );
        break;
    case 4:
        // set(r, g, b, a)
        obj(self).set(
            mrb_fixnum(mrb_Integer(mrb, argv[0]))
            , mrb_fixnum(mrb_Integer(mrb, argv[1]))
            , mrb_fixnum(mrb_Integer(mrb, argv[2]))
            , mrb_fixnum(mrb_Integer(mrb, argv[3]))
            );
        break;
    default:
        mrb_raise(mrb, E_TYPE_ERROR, "wrong number of arguments");
        break;
    }

    return mrb_nil_value();
}

mrb_value to_hex(mrb_state *mrb, mrb_value self)
{
    return mrb_fixnum_value(obj(self).getHex());
}

mrb_value set_hex(mrb_state *mrb, mrb_value self)
{
    mrb_int hex;
    mrb_float alpha = LIMIT;
    mrb_get_args(mrb, "i|f", &hex, &alpha);
    obj(self).setHex(hex, alpha);
    return mrb_nil_value();
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
    mrb_value targetValue;
    mrb_float amount;
    mrb_get_args(mrb, "of", &targetValue, &amount);
    ofColor& target = *BindColor::ToPtr(mrb, targetValue);

    return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self).getLerped(target, amount)));
}

mrb_value hue(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, obj(self).getHue());
}

mrb_value saturation(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, obj(self).getSaturation());
}

mrb_value brightness(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, obj(self).getBrightness());
}

mrb_value lightness(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, obj(self).getLightness());
}

mrb_value to_hsb(mrb_state *mrb, mrb_value self)
{
    float hue, saturation, brightness; // Because can't use mrb_float
    obj(self).getHsb(hue, saturation, brightness); 

    mrb_value array = mrb_ary_new(mrb);
    mrb_ary_push(mrb, array, mrb_float_value(mrb, hue));
    mrb_ary_push(mrb, array, mrb_float_value(mrb, saturation));
    mrb_ary_push(mrb, array, mrb_float_value(mrb, brightness));
    
    return array;
}

mrb_value hue_set(mrb_state *mrb, mrb_value self)
{
    mrb_float value;
    mrb_get_args(mrb, "f", &value);
    obj(self).setHue(value);
    return mrb_nil_value();
}

mrb_value saturation_set(mrb_state *mrb, mrb_value self)
{
    mrb_float value;
    mrb_get_args(mrb, "f", &value);
    obj(self).setSaturation(value);
    return mrb_nil_value();
}

mrb_value brightness_set(mrb_state *mrb, mrb_value self)
{
    mrb_float value;
    mrb_get_args(mrb, "f", &value);
    obj(self).setBrightness(value);
    return mrb_nil_value();
}

mrb_value set_hsb(mrb_state *mrb, mrb_value self)
{
    mrb_float hue, saturation, brightness, alpha = LIMIT;
    mrb_get_args(mrb, "fff|f", &hue, &saturation, &brightness, &alpha);
    obj(self).setHsb(hue, saturation, brightness, alpha);
    return mrb_nil_value();
}

mrb_value equal(mrb_state *mrb, mrb_value self)
{
    mrb_value targetValue;
    mrb_get_args(mrb, "o", &targetValue);
    ofColor& target = *BindColor::ToPtr(mrb, targetValue);

    return mrb_bool_value(obj(self) == target);
}

mrb_value add(mrb_state *mrb, mrb_value self)
{
    mrb_value *argv;
    int argc;

    mrb_get_args(mrb, "*", &argv, &argc);

    if (argc != 1) {
        mrb_raise(mrb, E_TYPE_ERROR, "wrong number of arguments");
    }

    if (mrb_obj_is_instance_of(mrb, argv[0], mrb_obj_class(mrb, self))) {
        ofColor& target = *static_cast<ofColor*>(DATA_PTR(argv[0]));
        return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self) + target));

    } else {
        mrb_value value = mrb_Float(mrb, argv[0]);
        return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self) + mrb_float(value)));
    }
}

mrb_value sub(mrb_state *mrb, mrb_value self)
{
    mrb_value *argv;
    int argc;

    mrb_get_args(mrb, "*", &argv, &argc);

    if (argc != 1) {
        mrb_raise(mrb, E_TYPE_ERROR, "wrong number of arguments");
    }

    if (mrb_obj_is_instance_of(mrb, argv[0], mrb_obj_class(mrb, self))) {
        ofColor& target = *static_cast<ofColor*>(DATA_PTR(argv[0]));
        return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self) - target));

    } else {
        mrb_value value = mrb_Float(mrb, argv[0]);
        return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self) - mrb_float(value)));
    }
}

mrb_value mul(mrb_state *mrb, mrb_value self)
{
    mrb_value *argv;
    int argc;

    mrb_get_args(mrb, "*", &argv, &argc);

    if (argc != 1) {
        mrb_raise(mrb, E_TYPE_ERROR, "wrong number of arguments");
    }

    if (mrb_obj_is_instance_of(mrb, argv[0], mrb_obj_class(mrb, self))) {
        ofColor& target = *static_cast<ofColor*>(DATA_PTR(argv[0]));
        return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self) * target));

    } else {
        mrb_value value = mrb_Float(mrb, argv[0]);
        return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self) * mrb_float(value)));
    }
}

mrb_value div(mrb_state *mrb, mrb_value self)
{
    mrb_value *argv;
    int argc;

    mrb_get_args(mrb, "*", &argv, &argc);

    if (argc != 1) {
        mrb_raise(mrb, E_TYPE_ERROR, "wrong number of arguments");
    }

    if (mrb_obj_is_instance_of(mrb, argv[0], mrb_obj_class(mrb, self))) {
        ofColor& target = *static_cast<ofColor*>(DATA_PTR(argv[0]));
        return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self) / target));

    } else {
        mrb_value value = mrb_Float(mrb, argv[0]);
        return BindColor::ToMrb(mrb, mrb_obj_class(mrb, self), new ofColor(obj(self) / mrb_float(value)));
    }
}

mrb_value aref(mrb_state *mrb, mrb_value self)
{
    mrb_int n;
    mrb_get_args(mrb, "i", &n);

    return mrb_fixnum_value(obj(self)[n]);
}

mrb_value aref_set(mrb_state *mrb, mrb_value self)
{
    mrb_int n, value;
    mrb_get_args(mrb, "ii", &n, &value);

    obj(self)[n] = value;

    return mrb_nil_value();
}

mrb_value inspect(mrb_state *mrb, mrb_value self)
{
    char buff[30];

    if (obj(self).a == LIMIT)
        sprintf(buff, "(%d,%d,%d)", obj(self).r, obj(self).g, obj(self).b);
    else
        sprintf(buff, "(%d,%d,%d,%d)", obj(self).r, obj(self).g, obj(self).b, obj(self).a);
        
    return mrb_str_new_cstr(mrb, buff);
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
    return ToPtr(mrb, mrb_class_get(mrb, "Color"), aValue);
}

//----------------------------------------------------------
ofColor* BindColor::ToPtr(mrb_state* mrb, struct RClass* aClass, mrb_value aValue)
{
    if (!mrb_obj_is_instance_of(mrb, aValue, aClass)) {
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

    mrb_define_method(mrb, cc,       "r"                 , r                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "r="                , r_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "g"                 , g                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "g="                , g_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "b"                 , b                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "b="                , b_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "a"                 , a                   , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "a="                , a_set               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "clone"             , clone               , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "set"               , set                 , MRB_ARGS_ARG(3, 1));
    mrb_define_method(mrb, cc,       "to_hex"            , to_hex              , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "set_hex"           , set_hex             , MRB_ARGS_ARG(1, 1));
    mrb_define_method(mrb, cc,       "clamp"             , clamp               , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "invert"            , invert              , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "normalize"         , normalize           , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "lerp"              , lerp                , MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,       "hue"               , hue                 , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "saturation"        , saturation          , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "brightness"        , brightness          , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "lightness"         , lightness           , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "to_hsb"            , to_hsb              , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "hue="              , hue_set             , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "saturation="       , saturation_set      , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "brightness="       , brightness_set      , MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,       "set_hsb"           , set_hsb             , MRB_ARGS_ARG(3, 1));
    mrb_define_method(mrb, cc,       "=="                , equal               , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "+"                 , add                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "-"                 , sub                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "*"                 , mul                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "/"                 , div                 , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "[]"                , aref                , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "[]="               , aref_set            , MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,       "inspect"           , inspect             , MRB_ARGS_NONE());
}

}
