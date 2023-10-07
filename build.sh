#!/bin/sh

# Make sure to modify this to point to your local nuget source folder. 
# If dotnet gives errors about invalid namespaces, try running `dotnet nuget locals all --clear` and then try the build again
NUGET_SOURCE=../nuget_sources

set -e

# Assumes this folder is a sibling folder to godot!
cd "$(dirname "$0")"/../godot
scons target=editor debug_symbols=yes custom_modules=../cscallable module_mono_enabled=yes compiledb=yes

cp compile_commands.json ../cscallable/compile_commands.json

chmod +x bin/godot.linuxbsd.editor.x86_64.mono

bin/godot.linuxbsd.editor.x86_64.mono --headless --generate-mono-glue modules/mono/glue
./modules/mono/build_scripts/build_assemblies.py --godot-output-dir=./bin --push-nupkgs-local $NUGET_SOURCE