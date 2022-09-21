## 5.

- Von Neuman (폰 노이만)

- CPU (연산 장치) <-> Memory(기억장치)

- SRAM(Static), DRAM(Dynamic)
    - SRAM 은 메모리만 기억하면 되므로 빠른 반면 DRAM은 캐패시터의 충방전을 고려하여 느림.
    - 속도면에서는 SRAM 이 좋지만 용량면에서는 DRAM이 우수.
    - SRAM 이 빠르기때문에 Cache Memory로 사용.

```
CPU <-> Register (0 ~ 31, 32개 (가장 효율이 좋은 개수)) 1cycle = 1/(2.1 * 10^9)[sec]
    <--> Cache 10 ~ 100 cycles
    <---> Memory (DRAM) 1000s cycles
    <----> Storage 1M cycles
```

- Managed Language
    - 언어 자체에서 메모리 관리를 전부 해주는 언어
    - Python, Java, C# 등

- Unmanaged Language
    - 언어 자체에서 메모리 관리를 안 해줘서 프로그래머가 관리 해주어야 하는 언어
    - C/C++ 등


- Main Memory 구조 !!! (g++ -S main.cpp 로 ASM어셈블리 확인가능)
    - [stack/heap]/bss/data/code
    - code,heap,stack 이 세가지가 중요.
    - CPP -> ASM -> OBJ -> Executable File
    - Stack 은 프로그램 종료 까지 사라지지않고 쌓임
    - Heap 은 동적할당에 사용됨.(Dynamic Allocation)

- Code : 우리가 작성한 코드
- Stack : 우리가 일반적으로 사용하는 초기화 된 변수
- Heap : 동적 할당을 한 경우 
- 비슷한 기능을 위해서 사용이 되는 변수들은 같이 그 주변에 선언을 해서 사용을 해주는 것이 좋다.(다시 메모리를 뽑아 쓸 필요 없도록)

## Coding Style
1. Functioning != Readability
    -  정상적으로 기능도 하면서 가독성도 좋아야함. 
2. Error-free code
    - 다른 다이나믹한 환경에서도 에러가 없이 동작해야함.
3. Maintainability(Refactoring)
    - 가독성, 효율성, 보수성 등을 잘 생각하며 코드를 짜야함.

- 구글의 코딩 스타일 (Google C++ Style Guide)
    - 함수에 대한 코드가 40줄을 넘어가면 다시 한 번 확인해볼 것(짧은 함수를 지향)
    - https://google.github.io/styleguide/cppguide.html'
    - 주석에는 //(single line)을 사용./* */(multiple line)은 오류를 발생시킬 가능성이 많아서

- 참고 사이트(xv6라는 mit 리눅스 교육용 os)
    - https://pdos.csail.mit.edu/6.828/2012/xv6.html


## include, define
1. C Libraries
    - #include <math.h>
2. C++ Libraries
    - #include <iostream>
3. User Libraries
    - #include "hello.h"
4. Macro Constant, Functions
    - #define MAX(a, b) a > b ? a : b
- 일반적으로 .h 는 C라이브러리, <> 를 사용하면 C++라이브러리
- 기본 built-in 라이브러리는 찾아보고 활용할 것!
- 참고 사이트
    - https://cplusplus.com