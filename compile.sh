#!/bin/bash
for cpp_file in *.cpp; do
    filename="${cpp_file%.*}"
    g++ -o "$filename" "$cpp_file" -std=c++20 -Wall -Wextra -Wpedantic
done
