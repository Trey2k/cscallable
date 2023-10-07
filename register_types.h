#ifndef LUA_REGISTER_TYPES_H
#define LUA_REGISTER_TYPES_H

#include "modules/register_module_types.h"

void initialize_cscallable_module(ModuleInitializationLevel p_level);
void uninitialize_cscallable_module(ModuleInitializationLevel p_level);
#endif
