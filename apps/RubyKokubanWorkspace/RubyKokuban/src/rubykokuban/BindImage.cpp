#include "rubykokuban/BindImage.hpp"

#include "mruby.h"
#include "mruby/class.h"
#include "mruby/data.h"
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
    obj->loadImage("a.png");
    // error handling ...
    struct RData *data = mrb_data_object_alloc(mrb, mrb_class_ptr(self), obj, &data_type);
    return mrb_obj_value(data);
}

mrb_value draw(mrb_state *mrb, mrb_value self)
{
    ofImage* obj = (ofImage*)DATA_PTR(self);
    obj->draw(100, 100);
    return mrb_nil_value();
}
}

//--------------------------------------------------------------------------------
void BindImage::Bind(mrb_state* mrb)
{
    struct RClass *cc = mrb_define_class(mrb, "Image", mrb->object_class);
    mrb_define_class_method(mrb , cc, "load", load, ARGS_NONE());
    mrb_define_method(mrb, cc, "draw", draw, ARGS_NONE());}

}

