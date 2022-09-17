#include <iostream>
#include <typeinfo>

int main() {
    short a = -32768;

    std::cout << a << " " << (short)(a-1) << std::endl; // underflow

    return 0;
}