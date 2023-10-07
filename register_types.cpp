#include "register_types.h"

#include "exampleRefCounted.h"

void initialize_cscallable_module(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }

  ClassDB::register_class<ExampleRefCounted>();
}

void uninitialize_cscallable_module(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }
}
