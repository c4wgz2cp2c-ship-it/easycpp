# EasyCPP - C++ Made Easy 🚀 (250+ Utilities)

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![Standard: C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Status: Active](https://img.shields.io/badge/status-active-brightgreen.svg)

**250+ Python-like utility functions for modern C++.**  
Stop writing the same boilerplate over and over. `easycpp.h` is a **single-header library** that brings the simplicity of Python to C++ without sacrificing performance.

## ✨ Why EasyCPP?

- **Single Header:** Just drop `easycpp.h` into your project and `#include` it.
- **No Dependencies:** Uses only the C++ Standard Library.
- **Zero Overhead:** `constexpr`, `noexcept`, and `[[nodiscard]]` everywhere.
- **Rich Feature Set:** From basic I/O to advanced sorting, data structures, CSV handling, and geometry.
- **Readable Code:** Write `print()`, `input()`, `split()`, `trim()` instead of `std::cout << ... << std::endl;`.

## 🚀 Quick Example

```cpp
#include "easycpp.h"
using namespace std;

int main() {
    // Clean printing
    println("Hello, ", "World!"); // Supports multiple args

    // Simple input
    string name = input_str("What's your name? ");
    int age = input_int("How old are you? ");

    // String utilities
    string s = "  Hello World  ";
    println(trim(s));                  // "Hello World"
    vector<string> words = split(s);   // {"Hello", "World"}

    // Vector utilities
    vector<int> nums = {1, 2, 3, 4, 5};
    println("Sum: ", sum(nums));       // 15
    println("Avg: ", average(nums));   // 3.0

    // Sorting
    vector<int> v = {5, 2, 9, 1, 5};
    bubble_sort(v);
    println("Sorted: ", v);            // {1, 2, 5, 5, 9}

    // Colored console output
    color_red();
    println("This is red!");
    color_reset();

    return 0;
}