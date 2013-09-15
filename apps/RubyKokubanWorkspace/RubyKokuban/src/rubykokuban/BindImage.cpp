#include "rubykokuban/BindImage.hpp"

#include "mruby.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "ofMain.h"

namespace rubykokuban {

namespace {
ofImage& obj(mrb_value self)
{
    return *((ofImage*)DATA_PTR(self));
}

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

mrb_value clone(mrb_state *mrb, mrb_value self)
{
    ofImage* newObj = new ofImage();

    newObj->clone(obj(self));

    struct RData *data = mrb_data_object_alloc(mrb, mrb_obj_class(mrb, self), newObj, &data_type);
    return mrb_obj_value(data);
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
    mrb_int width, height;
    mrb_get_args(mrb, "ii", &width, &height);

    obj(self).resize(width, height);

    return self;
}

mrb_value set_image_type(mrb_state *mrb, mrb_value self)
{
    return mrb_nil_value();
}

mrb_value crop_bang(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y, w, h;
    mrb_get_args(mrb, "iiii", &x, &y, &w, &h);
    
    obj(self).crop(x, y, w, h);

    return self;
}

mrb_value crop(mrb_state *mrb, mrb_value self)
{
    ofImage* newObj = new ofImage();

    mrb_int x, y, w, h;
    mrb_get_args(mrb, "iiii", &x, &y, &w, &h);

    newObj->cropFrom(obj(self), x, y, w, h);
        
    struct RData *data = mrb_data_object_alloc(mrb, mrb_obj_class(mrb, self), newObj, &data_type);
    return mrb_obj_value(data);
}

mrb_value rotate90(mrb_state *mrb, mrb_value self)
{
    mrb_int rotation = 1;
    mrb_get_args(mrb, "|i", &rotation);
    
    obj(self).rotate90(rotation);

    return self;
}

mrb_value mirror(mrb_state *mrb, mrb_value self)
{
    mrb_bool vertical, horizontal;
    mrb_get_args(mrb, "bb", &vertical, &horizontal);
    
    obj(self).mirror(vertical, horizontal);
    
    return self;
}

mrb_value update(mrb_state *mrb, mrb_value self)
{
    obj(self).update();
    return self;
}

mrb_value set_anchor_percent(mrb_state *mrb, mrb_value self)
{
    mrb_float xpct, ypct;
    mrb_get_args(mrb, "ff", &xpct, &ypct);
    
    obj(self).setAnchorPercent(xpct, ypct);
    
    return self;
}

mrb_value set_anchor_point(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y;
    mrb_get_args(mrb, "ff", &x, &y);
    
    obj(self).setAnchorPoint(x, y);
    
    return self;
}

mrb_value reset_anchor(mrb_state *mrb, mrb_value self)
{
    obj(self).resetAnchor();
    return self;
}

mrb_value draw(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y, w, h;
    int argNum = mrb_get_args(mrb, "ff|ff", &x, &y, &w, &h);

    if (argNum == 4)
        obj(self).draw(x, y, w, h);
    else 
        obj(self).draw(x, y);

    return self;
}

mrb_value draw_sub(mrb_state *mrb, mrb_value self)
{
    mrb_float x, y, w, h, sx, sy, sw, sh;
    int argNum = mrb_get_args(mrb, "ffffff|ff", &x, &y, &w, &h, &sx, &sy, &sw, &sh);

    if (argNum == 8)
        obj(self).drawSubsection(x, y, w, h, sx, sy, sw, sh);
    else 
        obj(self).drawSubsection(x, y, w, h, sx, sy);

    return self;
}

mrb_value height(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, obj(self).getHeight());
}

mrb_value width(mrb_state *mrb, mrb_value self)
{
    return mrb_float_value(mrb, obj(self).getWidth());
}

}

//--------------------------------------------------------------------------------
void BindImage::Bind(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Image", mrb->object_class);
    
    mrb_define_class_method(mrb , cc, "load",               load,               MRB_ARGS_REQ(1));
    mrb_define_class_method(mrb , cc, "grab_screen",        grab_screen,        MRB_ARGS_REQ(4));
                                                             
    mrb_define_method(mrb, cc,        "clone",              clone,              MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,        "save",               save,               MRB_ARGS_ARG(2, 1));
    mrb_define_method(mrb, cc,        "color",              color,              MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "set_color",          set_color,          MRB_ARGS_REQ(3));
    mrb_define_method(mrb, cc,        "resize",             resize,             MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "set_image_type",     set_image_type,     MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc,        "crop",               crop,               MRB_ARGS_REQ(4));
    mrb_define_method(mrb, cc,        "crop!",              crop_bang,          MRB_ARGS_REQ(4));
    mrb_define_method(mrb, cc,        "rotate90",           rotate90,           MRB_ARGS_OPT(1));
    mrb_define_method(mrb, cc,        "mirror",             mirror,             MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "update",             update,             MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,        "set_anchor_percent", set_anchor_percent, MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "set_anchor_point",   set_anchor_point,   MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "reset_anchor",       reset_anchor,       MRB_ARGS_REQ(2));
    mrb_define_method(mrb, cc,        "draw",               draw,               MRB_ARGS_ARG(2, 2));
    mrb_define_method(mrb, cc,        "draw_sub",           draw_sub,           MRB_ARGS_ARG(6, 2));
    mrb_define_method(mrb, cc,        "height",             height,             MRB_ARGS_NONE());
    mrb_define_method(mrb, cc,        "width",              width,              MRB_ARGS_NONE());
}

}
