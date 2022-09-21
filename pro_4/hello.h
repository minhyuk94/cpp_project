#include <iostream>
#include <math.h>

#ifndef HELLO_HEADER
#define HELLO_HEADER

// 우리가 사용할 수 있는 함수들의 prototype을 정의 해 주는 것.
void hello_header(const int num);

#endif

// hello.h 를 두번 include 되는걸 막기위해서 ifndef 로 중복되는 것을 방지!!!!