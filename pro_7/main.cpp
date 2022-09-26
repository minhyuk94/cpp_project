#include <iostream>

// Reference Type 을 통해서도 swap 가능.
// 서로 다른 이름을 가진 동일한 변수.(주소까지 완전히 동일, 한주소에 이름이 똑같은 게 존재하는것)
// a = num1 , b = num2

void ref_swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    printf("%p %p\n", &a, &b);
}


void ptr_swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("%p %p\n", &a, &b);
}

int main() {
    int num1{1}, num2{2};
    printf("%p %p\n", &num1, &num2);
    ptr_swap(&num1, &num2); //서로다른 주소
    // ref_swap(num1, num2); // 완전히 주소도 똑같아짐(변수명만 다른 동일한 주소의 변수)
    std::cout << num1 << " " << num2 << std::endl; 
    return 0;
}