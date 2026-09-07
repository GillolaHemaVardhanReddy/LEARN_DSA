#!/usr/bin/env bash
# DSA build+run helper for Hema Vardhan.
# Fixes the macOS toolchain bug: Anaconda's stale `ld` (ld64-530) shadows Apple's
# modern linker and can't parse new-SDK .tbd files. The -B flag forces GCC to use
# Apple's Command Line Tools linker instead.
#
# Usage:
#   ./run.sh path/to/solution.cpp        # compile + run
#   ./run.sh                             # defaults to ./solution.cpp in current dir
set -e

SRC="${1:-solution.cpp}"
BIN="$(mktemp -t dsa_run.XXXXXX)"

g++-15 -std=c++17 -O2 -Wall \
    -B/Library/Developer/CommandLineTools/usr/bin \
    "$SRC" -o "$BIN"

echo "── running $SRC ──"
"$BIN"
