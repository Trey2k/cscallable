#!/bin/sh

set -e

# Assumes this folder is a sibling folder to godot!
cd "$(dirname "$0")"/TestProject

../../godot/bin/godot.linuxbsd.editor.x86_64.mono --editor