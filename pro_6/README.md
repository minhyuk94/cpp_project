## 6.

### Array

- 어떤 Data Type 을 가진 Data들의 Sequence(나열)
- 기존의 Data Type을 포함할 수 있는 특별한 Data Type
- data_type variable_name[#_of_elements]

### Multi-dimensional Array(다차원 배열)
```
    2 x 2 matrix  | a b | row : 행
                  | c d | column : 열
    첫 주소로부터 얼마나 떨어져 있는가로 판단.
    a = (0,0) b = (0,1) c = (1,0) d = (1,1)


    int md_arr[][3] 으로 해도 알아서 빈칸을 2로 채워줌(결과값이 2by3 행렬이니까)
    int md_arr[2][3] = {{1,2,3}, 
                        {4,5,6}};
```

### Pointer
- 메모리 주소를 저장 할 수 있는 특별한 data type 
- & = ampersand , 읽을때는 address of, at, reference 등으로 읽음.

```
    variable    type    address     data
        a       int     0x6b06f54c    10
        ptr     int*    0x6b06f540    0x6b06f54c
```
### Pointer Arithmetic
```
    printf("%p\n", ptr);
    ptr++;//4byte 증가(1칸)
    printf("%p\n", ptr);
```

```
    variable    type    address             data
        a       int     0x7fffdd12e318      10
        b       int     0x7fffdd12e31c      20
        ptr     int*                        0x7fffdd12e318
```

### Bit Separation
```
#define MSBV(x) (short)(x>>8)
00000100 00000001 우측 8bit 기준
8bit right shift = 00000000 00000100 = 4

#define LSBV(x) ((short)(x<<8)>>8)
00000100 00000001
8bit left shift = 00000001 00000000
8bit right shift = 00000000 00000001 = 1

int main() {
    // short : 2B = 00000100 00000001 = 1025
    // short n = 0b0000010000000001; = 1025
    // 00000100 00000001
    // ' 4 '     '  1  '
    // Bitwise Operation


    // Shift연산을 통해 값 구하기(short는 2byte니까 8byte를 옮기면 +1 -1이 되는것과 같음)
    short val = 1025;
    std::cout << MSBV(val) << " " << LSBV(val) << std::endl;

    // 포인터를 통해 값 구하기
    short val = 1025;
    char* ptr = (char*) &val;
    std::cout << (short)*ptr << std::endl;
    std::cout << (short)*(ptr+1) << std::endl;
}
```

### Array With Pointer(배열을 포인터로 관리)
- 배열에서 접근할 때 : arr[n] = *(arr+n) 
- 포인터를 사용하면 속도가 더 빠르게 접근가능


### 시간측정
```
#include <stdio.h>
#include <time.h>
 
 
int main() {
    clock_t start, finish;
    double duration;
    
    start = clock();
 
    /*실행 시간을 측정하고 싶은 코드*/
    
    finish = clock();
    
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f초", duration);
    
    return 0;
}

```