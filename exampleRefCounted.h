#ifndef EXAMPLEREFCOUNTED_H
#define EXAMPLEREFCOUNTED_H

#include "core/core_bind.h"
#include "core/object/ref_counted.h"

class ExampleRefCounted : public RefCounted {
  GDCLASS(ExampleRefCounted, RefCounted);

protected:
  static void _bind_methods();

public:
  ExampleRefCounted();
  ~ExampleRefCounted();

  Callable get_exmaple_callable();
};
#endif