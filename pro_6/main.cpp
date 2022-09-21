#include <iostream>
#include <time.h>
// Array : 배열
/*
int main() {
    // 어떤 Data Type 을 가진 Data들의 Sequence(나열)
    // 기존의 Data Type을 포함할 수 있는 특별한 Data Type
    // data_type variable_name[#_of_elements]

    int arr[4] = {1,2,3,4}; // stack 에 쌓임. 1부터 쌓여서 아래에서 위로 (LIFO)

    std::cout << sizeof(arr) << std::endl;

    // J i n
    char name[10] = {0,0,1,2,3,4,5,6,7,8};
    
    name[0] = 'J';
    name[1] = 'i';
    name[2] = 'n';
    name[3] = '\0'; // 문자열을 출력할 때는 반드시 \0 으로 문자열의 끝을 표기해야 함.
    std::cout << name << std::endl;
    std::cout << sizeof(name) << std::endl; // char 3byte \0 1byte => 10byte

    return 0;
}
*/

// Multi-dimensional Array(다차원 배열)

/*
int main() {
    // 2 x 2 matrix  | a b | row : 행
    //               | c d | column : 열
    // 첫 주소로부터 얼마나 떨어져 있는가로 판단.
    // a = (0,0) b = (0,1) c = (1,0) d = (1,1)


    // int md_arr[][3] 으로 해도 알아서 빈칸을 2로 채워줌(결과값이 2by3 행렬이니까)
    int md_arr[2][3] = {{1,2,3}, 
                        {4,5,6}};
       

    std::cout << md_arr[1][1] << std::endl;
}
*/

// Pointer 포인터
// 메모리 주소를 저장 할 수 있는 특별한 data type 

/* 
int main() {
    
    int a{10};
    int* ptr = &a;

    std::cout << *ptr << std::endl;
    // 의미 : 해당 포인터가 가진 메모리 주소에 저장된 data(역참조)

    // Pointer Arithmetic
    printf("%p\n", ptr);
    ptr++;//4byte 증가(1칸)
    printf("%p\n", ptr);

    return 0;
}
*/

// Pointer Arthmetic 예제
/*
int main() {
    int a = 10;
    int b = 20;
    int* ptr = &a;

    printf("%p %p\n", &a, &b);
    std::cout << *ptr << std::endl;
    ptr++;
    std::cout << *ptr << std::endl;

    return 0;
}
*/

// Bit Separation
/*
#define MSBV(x) ((short)x>>8)  //x = 1025
#define LSBV(x) ((short)(x<<8)>>8)

int main() {
    // short : 2B = 00000100 00000001 = 1025
    // short n = 0b0000010000000001; = 1025
    // 00000100 00000001
    // ' 4 '     '  1  '
    // Bitwise Operation


    // Shift연산을 통해 값 구하기(short는 2byte니까 8byte를 옮기면 +1 -1이 되는것과 같음)
    //short val = 1025;
    //std::cout << MSBV(val) << " " << LSBV(val) << std::endl;

    // 포인터를 통해 값 구하기
    // short val = 1025;
    // char* ptr = (char*) &val;
    // std::cout << (short)*ptr << std::endl;
    // std::cout << (short)*(ptr+1) << std::endl;

}
*/

// Array With Pointer(배열을 포인터로 관리)
int main() {
    int arr[6] = {1,2,3,4,5,6};
    int* ptr = &arr[1];
    std::cout << *arr << " " << *ptr << std::endl; // *arr = 1, *ptr = 2
    std::cout << ptr[3] << std::endl;
    // ptr[3] = 5(*ptr = &arr[1] 이니까 그거에서 +3떨어진 원소 arr[4]를 가리킴)
    // 배열에서 접근할 때 : arr[n] = *(arr+n) 

    clock_t start, finish;
    double duration;
    
    start = clock();
    
    // 포인터를 활용하면 속도가 더 빠름
    for (ptr = &arr[1]; ptr<&arr[5]; ++ptr) {
        std::cout << *ptr << " ";
    }

    // for (int i=1; i<5; ++i) {
    //     std::cout << arr[i] << " ";
    // }

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f초", duration);

    std::cout << std::endl;
}