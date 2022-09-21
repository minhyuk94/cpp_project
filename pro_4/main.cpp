#include <iostream>

// 헤더파일 사용
#include "hello.h"

#define PI 3.141592 // C-Style

// c++ Macro Function
#define SQUARE(x) x*x
#define HELLO() std::cout << "Hello, World\n"
#define MAX(a, b) a > b ? a : b

// Macro Function 은 if문에도 사용가능
#define LOG 0
#define clprint() if(LOG) std::cout << "Hello World\n"; else std::cout << "Hello\n"

// 코드의 가독성을 위해 함수 내용은 메인함수의 아래쪽에 정리하거나 다른 파일로 나누고 메인함수 위쪽에 함수를 선언해서 사용!!
double max(double a, double b);
const double min(const double a, const double b);
int factorial(int n);
int getFive();
int calc(int num);

// c++ 에서 허용하는 변수 
// global, local static
// static = 정적 변수 처음 불려질 때만 초기화되고 이후는 초기화 되지않음.
// static 은 함수가 몇 번 불리는지 체크 하는 등 활용 가능.

// namespace
// main과 겹치지않고 독립시켜서 사용하고 싶을 경우 활용.
// 결론적으로 std도 namespace임.
// using namespace를 사용하면 더이상 std:: 이런식으로 선언 하지 않아도됨.
// 하지만 namespace의 의의가 메인과 독립시키기 위함이기 때문에 std를 메인함수와 같이 사용하는건 모순.

using namespace std;

/*
namespace USA {
    int gdp = 100;
    void hello() {
        std::cout << "Hello" << std::endl;
    }
}
*/

// Static function (main에서는 사용 불가능, 프로토타입으로 등장하면 절대 안됨.)


int main() {

    std::cout << SQUARE(4) << std::endl;
    // std:: cout << 4*4 << std::endl;

    int a = MAX(5, 10);
    std::cout << a << std::endl;

    clprint();

    std::cout << max(5, 10) << std::endl;

    std::cout << factorial(1) << std::endl;

    std::cout << calc(2) << std::endl;
    std::cout << calc(2) << std::endl;

    // std::cout << USA::gdp << std::endl;

    hello_header(5);

    return 0;  
}


// 일반적인 함수
double max(double a, double b) {
    return a > b ? a : b;
}

// const로 선언하면 속도를 좀 향상시킬 수 있음.
const double min(const double a, const double b) {
    return a > b ? b: a;
}

// 재귀
int factorial(int n) {
    return n <= 1 ? 1 : n*factorial(n-1);
}

int getFive() {
    return 5;
}

int calc(int num) {
    static int a = 1;
    a += 1;
    return a * num;
}