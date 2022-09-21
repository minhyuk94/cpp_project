#include "hello.h"

static int cubic(int num) {
    return pow(num, 3);
}

void hello_header(const int num) {
    std::cout << "Hello, World" << num << std::endl;
    std::cout << "Cubic : " << cubic(3) << std::endl;
}