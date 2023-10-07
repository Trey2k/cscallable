#ifndef EXAMPLECALLABLECUSTOM_H
#define EXAMPLECALLABLECUSTOM_H

#include "core/object/ref_counted.h"
#include "core/variant/callable.h"

#include "exampleRefCounted.h"

#ifdef LAPI_GDEXTENSION
using namespace godot;
#endif

class ExampleCallableCustom : public CallableCustom {
  static bool compare_equal(const CallableCustom *p_a,
                            const CallableCustom *p_b);
  static bool compare_less(const CallableCustom *p_a,
                           const CallableCustom *p_b);
  uint32_t h;

public:
  uint32_t hash() const override;
  String get_as_text() const override;
  CompareEqualFunc get_compare_equal_func() const override;
  CompareLessFunc get_compare_less_func() const override;
  ObjectID get_object() const override;
  void call(const Variant **p_argument, int p_argcount, Variant &r_return_value,
            Callable::CallError &r_call_error) const override;

  ExampleCallableCustom(Ref<ExampleRefCounted> obj);
  ~ExampleCallableCustom() override;

private:
  int funcRef;
  Ref<ExampleRefCounted> obj;
};

#endif