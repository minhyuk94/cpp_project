#include <iostream>
#include <typeinfo>

int main() {

    short a;
    int b;
    long c;
    long long d;

    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(c) << std::endl;
    std::cout << sizeof(d) << std::endl;

    // c++filt -t 를 sh에 추가해주면 타입이 char말고 string형태로 제대로 표시됨.
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;
    std::cout << typeid(c).name() << std::endl;
    std::cout << typeid(d).name() << std::endl;

    int q = 10;
    int w(20);
    int e{30}; // C++11 에서 부터 지원

    std::cout << q << " " << w << " " << e << std::endl;

    // OverFlow UnderFlow
    short r = -32768;

    std::cout << r << " " << (short)(r-1) << std::endl; // UnderFlow (내부에서 잡아주지만 이런걸 파악할 줄 알아야함)

    // Type Conversion
    // 1. Explicit(명시적 바로보임)  2.Implicit(내부적)
    // static_cast, dynamic_cast, const_cast, interpret_cast
    int t = 10, g = 3;
    std::cout << static_cast<double>(t) / g << std::endl;

    // 삼항연산
    int h = 10, j = 20;
    int k;

    k = true ? h : j;
    std::cout << k << std::endl;

    return 0;
}