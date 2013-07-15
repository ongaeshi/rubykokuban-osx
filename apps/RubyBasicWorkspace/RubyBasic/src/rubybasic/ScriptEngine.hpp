#pragma once

#include "mruby.h"

//--------------------------------------------------------------------------------
namespace rubybasic {

class ScriptEngine {
public:
    ScriptEngine(const char* aFilename);
    ~ScriptEngine();

    mrb_state* mrb() { return mMrb; }

    void setup();

    // Create need function only
    mrb_value funcallIf(const char* aName);
    mrb_value funcallIf(const char* aName, mrb_value aArg1, mrb_value aArg2);
    mrb_value funcallIf(const char* aName, mrb_value aArg1, mrb_value aArg2, mrb_value aArg3);

    void reload();

private:
    void open();
    void load(const char* aFilename);
    void close();
    void reopen();
    
    struct RClass* kernel_module() { return mMrb->kernel_module; }
    mrb_value      kernel_obj()    { return mrb_obj_value(kernel_module()); }

    bool isExistFunction(mrb_value aSelf, const char* aFuncName);
    void closeOnException();

    const char* mFilename;
    mrb_state*  mMrb;
};

}
