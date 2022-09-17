#include <iostream>

int main() {

    int a = 0;
    
    // cin 을 여러번 사용하는 경우 쓰레기값이 들어갈 경우가 있어 std::cin.clear(); 을 통해 초기화
    std::cin >> a;
    std::cout << "Number: " << a << std::endl;
    std::cout << "Hello World\n" << std::endl;
    std::cin.clear();

    return 0;
}