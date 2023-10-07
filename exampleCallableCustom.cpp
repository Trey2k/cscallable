#include "exampleCallableCustom.h"

#include "core/templates/hashfuncs.h"

// I used "GDScriptLambdaCallable" as a template for this
ExampleCallableCustom::ExampleCallableCustom(Ref<ExampleRefCounted> p_obj) {
  obj = p_obj;
  h = (uint32_t)hash_djb2_one_64((uint64_t)this);
  print_line("ExampleCallableCustom::ExampleCallableCustom()");
}

ExampleCallableCustom::~ExampleCallableCustom() {
  print_line("ExampleCallableCustom::~ExampleCallableCustom()");
}

bool ExampleCallableCustom::compare_equal(const CallableCustom *p_a,
                                          const CallableCustom *p_b) {
  // Lua callables are only compared by reference.
  return p_a == p_b;
}

bool ExampleCallableCustom::compare_less(const CallableCustom *p_a,
                                         const CallableCustom *p_b) {
  // Lua callables are only compared by reference.
  return p_a < p_b;
}

CallableCustom::CompareEqualFunc
ExampleCallableCustom::get_compare_equal_func() const {
  return compare_equal;
}

CallableCustom::CompareLessFunc
ExampleCallableCustom::get_compare_less_func() const {
  return compare_less;
}

ObjectID ExampleCallableCustom::get_object() const {
  return obj->get_instance_id();
}

String ExampleCallableCustom::get_as_text() const {
  // I dont know of a way to get a useful name from the function
  // For now we are just using the callables hash.
  return vformat("ExampleCallableCustom 0x%X", h);
}

uint32_t ExampleCallableCustom::hash() const { return h; }

void ExampleCallableCustom::call(const Variant **p_arguments, int p_argcount,
                                 Variant &r_return_value,
                                 Callable::CallError &r_call_error) const {
  print_line(vformat("ExampleCallableCustom::call()  0x%X", h));
}