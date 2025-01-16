# Example code for "Visualizing modern C++ using Clang and UML"

This repository contains sample code for my blog post:

* [Visualizing modern C++ using Clang and UML](https://blog.bkryza.com/posts/generating-uml-diagrams-from-moderncpp-using-clang)

# Running examples

```
git clone https://github.com/bkryza/blog-visualizing-modern-cpp-using-clang-and-uml
cd 
# Adjust paths to your Clang compiler (necessary for C++20 modules examples)
CC=/usr/bin/clang-19 CXX=/usr/bin/clang++-19 cmake -DLLVM_VERSION=19 -DCMAKE_GENERATOR=Ninja -S . -B debug
cmake --build debug
clang-uml -p
plantuml -tsvg diagrams/*.puml
```

# LICENSE

```
MIT License

Copyright (c) 2025 Bartek Kryza <bkryza@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```