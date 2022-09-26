#include <iostream>

int main(const int argc, const char** argv) {
    // 다차원 배열 동적할당
    // 5 x n 배열 동적
    int** arr = new int*[5];
    
    // Some Operations
    std::size_t n = 4; // 5 x 4 -> 4개짜리 배열이 5줄
    
    // 다차원 동적할당
    for (std::size_t i=0; i<5; ++i) {
        arr[i] = new int[n];
    }

    // 5 x 4
    arr[4][3] = 1;
    std::cout << arr[4][3] << std::endl;
    
    // 다차원 동적할당 해제
    for (std::size_t i=0; i<5; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    std::cout << arr[4][3] << std::endl;
}