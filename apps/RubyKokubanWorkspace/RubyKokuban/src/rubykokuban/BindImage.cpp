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

mrb_value draw(mrb_state *mrb, mrb_value self)
{
    mrb_int x, y;
    mrb_get_args(mrb, "ii", &x, &y);
    
    ofImage* obj = (ofImage*)DATA_PTR(self);
    obj->draw(x, y);
    return mrb_nil_value();
}
}

//--------------------------------------------------------------------------------
void BindImage::Bind(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Image", mrb->object_class);
    mrb_define_class_method(mrb , cc, "load", load, MRB_ARGS_REQ(1));
    mrb_define_method(mrb, cc, "draw", draw, MRB_ARGS_REQ(2));}

}

