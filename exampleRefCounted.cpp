#include "exampleRefCounted.h"

#include "exampleCallableCustom.h"

void ExampleRefCounted::_bind_methods() {
  ClassDB::bind_method(D_METHOD("get_exmaple_callable"),
                       &ExampleRefCounted::get_exmaple_callable);
}

ExampleRefCounted::ExampleRefCounted() {
  print_line("ExampleRefCounted::ExampleRefCounted()");
}

ExampleRefCounted::~ExampleRefCounted() {
  print_line("ExampleRefCounted::~ExampleRefCounted()");
}

Callable ExampleRefCounted::get_exmaple_callable() {
  ExampleCallableCustom *callable = memnew(ExampleCallableCustom(this));
  return Callable(callable);
}