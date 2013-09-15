#include "rubykokuban/BindImage.hpp"

#include "mruby.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "ofMain.h"

namespace rubykokuban {

namespace {
void free(mrb_state *mrb, void *p)
{
    if (p) {
        delete ((ofImage*)p);
    }
}

struct mrb_data_type data_type = { "rubykokuban_image", free };

mrb_value load(mrb_state *mrb, mrb_value self)
{
    ofImage* obj = new ofImage();

    mrb_value str;
    mrb_get_args(mrb, "S", &str);

    string filename(mrb_string_value_ptr(mrb, str));
    obj->loadImage(filename);

    struct RData *data = mrb_data_object_alloc(mrb, mrb_class_ptr(self), obj, &data_type);
    return mrb_obj_value(data);
}

mrb_value grab_screen(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value save(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value color(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value set_color(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value resize(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value set_image_type(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value crop_bang(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value crop(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value rotate90(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value mirror(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value update(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value set_anchor_percent(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value set_anchor_point(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value reset_anchor(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value draw(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y;
    mrb_get_args(mrb, "ii", &x, &y);
    
    ofImage* obj = (ofImage*)DATA_PTR(self);
    obj->draw(x, y);

    return mrb_nil_value();
}

mrb_value draw_sub(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value height(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value width(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

}

//--------------------------------------------------------------------------------
void BindImage::Bind(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Image", mrb->object_class);
    
    mrb_define_class_method(mrb , cc, "load",               load,               MRB_ARGS_REQ(1));
    mrb_define_class_method(mrb , cc, "grab_screen",        grab_screen,        MRB_ARGS_REQ(4));
                                                             
    mrb_define_method(mrb, cc,        "save",               save,               MRB_ARGS_ARG(2, 1));
    mrb_define_method(mrb, cc,        "color",              color,              MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "set_color",          set_color,          MRB_ARGS_REQ(3));
    mrb_define_method(mrb, cc,        "resize",             resize,             MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "set_image_type",     set_image_type,     MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,        "crop",               crop,               MRB_ARGS_REQ(5));
    mrb_define_method(mrb, cc,        "crop!",              crop_bang,          MRB_ARGS_REQ(4));
    mrb_define_method(mrb, cc,        "rotate90",           rotate90,           MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,        "mirror",             mirror,             MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "update",             update,             MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,        "set_anchor_percent", set_anchor_percent, MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "set_anchor_point",   set_anchor_point,   MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "reset_anchor",       reset_anchor,       MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "draw",               draw,               MRB_ARGS_ARG(2, 3));
    mrb_define_method(mrb, cc,        "draw_sub",           draw_sub,           MRB_ARGS_ARG(6, 2));
    mrb_define_method(mrb, cc,        "height",             height,             MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,        "width",              width,              MRB_ARGS_NONE());
}

}
