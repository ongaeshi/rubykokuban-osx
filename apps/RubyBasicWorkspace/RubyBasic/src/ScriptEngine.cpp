#include "ScriptEngine.hpp"

#include "BindApplication.hpp"
#include "BindGraphics.hpp"
#include "BindInput.hpp"
#include "mruby.h"
#include "mruby/class.h"
#include "mruby/compile.h"

namespace rubybasic {

//--------------------------------------------------------------------------------
ScriptEngine::ScriptEngine(const char* aFilename)
: mFilename(aFilename)
, mMrb(NULL)
{
    open();
    load(mFilename);
}

//--------------------------------------------------------------------------------
ScriptEngine::~ScriptEngine()
{
    close();
}

//--------------------------------------------------------------------------------
void ScriptEngine::setup()
{
    // bind
    BindGraphics::Bind(mMrb);
    BindApplication::Bind(mMrb);
    BindInput::Bind(mMrb);

    // call setup
    funcallIf("setup");
}

//--------------------------------------------------------------------------------
mrb_value ScriptEngine::funcallIf(const char* aName)
{
    if (mMrb && isExistFunction(kernel_obj(), aName)) {
        int ai = mrb_gc_arena_save(mMrb);
        mrb_value value = mrb_funcall(mMrb, kernel_obj(), aName, 0);
        mrb_gc_arena_restore(mMrb, ai);
        closeOnException();
        return value;
    }

    return mrb_nil_value();
}

//--------------------------------------------------------------------------------
mrb_value ScriptEngine::funcallIf(const char* aName, mrb_value aArg1, mrb_value aArg2)
{
    if (mMrb && isExistFunction(kernel_obj(), aName)) {
        int ai = mrb_gc_arena_save(mMrb);
        mrb_value value = mrb_funcall(mMrb, kernel_obj(), aName, 2, aArg1, aArg2);
        mrb_gc_arena_restore(mMrb, ai);
        closeOnException();
        return value;
    }

    return mrb_nil_value();
}

//--------------------------------------------------------------------------------
mrb_value ScriptEngine::funcallIf(const char* aName, mrb_value aArg1, mrb_value aArg2, mrb_value aArg3)
{
    if (mMrb && isExistFunction(kernel_obj(), aName)) {
        int ai = mrb_gc_arena_save(mMrb);
        mrb_value value = mrb_funcall(mMrb, kernel_obj(), aName, 3, aArg1, aArg2, aArg3);
        mrb_gc_arena_restore(mMrb, ai);
        closeOnException();
        return value;
    }

    return mrb_nil_value();
}

//--------------------------------------------------------------------------------
void ScriptEngine::reload()
{
    reopen();  // comment out?
    load(mFilename);
    setup();
}

//--------------------------------------------------------------------------------
void ScriptEngine::open()
{
    mMrb = mrb_open();
}

//--------------------------------------------------------------------------------
void ScriptEngine::load(const char* aFilename)
{
    FILE *fd = fopen(mFilename, "r");
    mrb_load_file(mMrb, fd);
    fclose(fd);
}
    
//--------------------------------------------------------------------------------
void ScriptEngine::close()
{
    if (mMrb) {
        mrb_close(mMrb);
        mMrb = NULL;
    }
}

//--------------------------------------------------------------------------------
void ScriptEngine::reopen()
{
    close();
    open();
}

//--------------------------------------------------------------------------------
bool ScriptEngine::isExistFunction(mrb_value aSelf, const char* aFuncName)
{
    struct RClass *c = mrb_class(mMrb, aSelf);
    struct RProc *p = mrb_method_search_vm(mMrb, &c, mrb_intern(mMrb, aFuncName));
    return p != NULL;
}

//--------------------------------------------------------------------------------
void ScriptEngine::closeOnException()
{
    if (mMrb->exc) {
        mrb_p(mMrb, mrb_obj_value(mMrb->exc));
        mrb_close(mMrb);
        mMrb = NULL;
    }
}

}
