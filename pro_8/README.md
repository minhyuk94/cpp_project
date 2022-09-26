## 8>
### l-value, r-value (포인터나 동적할당에도 동일 적용)
- 코딩을 문법적으로 잘못했을 때 컴파일러에서 직접적으로 나타나기도함.
- 역사적으로: left (right) hand side value / = 
- 공식 문서: identity를 갖느냐? move 될 수 있느냐? 등 에따라서 나뉨
- l-value : 메모리 상 어딘가에 저장이 되어서 코드 한 줄 한 줄 끝나도 재사용이 가능한 값(지속성을 갖는다) => 영역
- r-value : 메모리 상 어딘가에 저장이 되지 않아 재사용이 불가능한 값(지속성이 없음), 상황에 따라서 어딘가에 저장이 될 수는 있지만 없다고 생각해도 무방

- l-value : 메모리 영역에 어떤 값을 써주는 역할은 l-value, r-value 모두 가능!
- 메모리 영역에 접근해서 동작하는 것은 l-value만 가능!
- l-value : 변수, 상수, Union, Class ...
- r-value : 상수표현식, ampersand ...

```
    int a = 10, b = 20; // a = l-value 10 = r-value, b = l-value, 20 = r-value
    a = b; // a = l-value, b = l-value
    a = b-10;  // a = l-value, b-10 = r-value(연산자를 통해 나온 결과값이니까)
    int* ptr = &a; // ptr = l-value, &a = r-value 
```

## Reference Type
- lvalue reference type vs rvalue reference type
- &, &&
- & (int& a) : lvalue reference type // pro_7에서의 reference type과 완벽히 동일
- 서로 다른 이름의 동일한 변수

```
int a{10};
int& rf = a;

std::cout << a << std::endl; // 10
rf = 20;
std::cout << a << std::endl; // 20
std::cout << rf << std::endl; // 20
```

## r-value
- && (int&& a) : lvalue reference type 또는 rvalue reference type(문맥에 따라 다름)
- rvalue reference 는 중간과정을 저장하는 용도로 많이 사용.(값을 보호, 불필요한 복사를 방지)

```
// std::size_t : 좀 더 안전한 데이터타입
int& array(std::size_t index) {
    static int arr[5] = {5,4,3,2,1}; // static이라 한 번 사용이되면 프로그램 종료시까지 안사라짐
    return arr[index];
}
```

```
    int a{10}, b{20};
    int&& val = (a+b/2)*3 -3; // rvalue
    std::cout<< val << std::endl;
    val = a; // lvalue로도 가능
    std::cout<< val << std::endl; 
```

## Dangling Reference(허상 참조)
```
int& dangling() {
    static int a = 10; // buggy
    // static int a = 10; static 으로 만들거나 global로 해야 에러가안남. 
    return a;
}

int main() {
    
    // Dangling Reference
    int& lrf = dangling();
    std::cout << lrf << std::endl; // segmentation fault(반환값이 없어서)

    return 0;
}
```

## Double Pointer
- 포인터 변수의 주소를 저장하는 포인터

```
    int value = 100;
    int* value_ptr = &value;
    int** value_double_ptr = &value_ptr;

    std::cout << "Value = " << value << std::endl; // 100
    std::cout << "Pointer to value = " << *value_ptr << std::endl; // 100
    std::cout << "Double Pointer to value = " << **value_double_ptr << std::endl; //100
```

```
/---Comprehension of Computer---\ /--------- Main Memory ---------\
+--variable--+-------type--------+------address------+----data----+
|   value    |       int         |       #150        |    100     |
+------------+-------------------+-------------------+------------+
|  value_ptr |      int*         |       #146        |    #150    |
+------------+-------------------+-------------------+------------+
| value_d_ptr|      int**        |       #142        |    #146    |
+------------+-------------------+-------------------+------------+
|            |                   |                   |            |
+------------+-------------------+-------------------+------------+
|            |                   |                   |            |
+------------+-------------------+-------------------+------------+
```

## 1.Pointer Array
```
    // 포인터들의 배열, 배열의 원소가 포인터들로 이루어짐.

    int a{10}, b{20}, c{30};
    int* ptr_arr[3] = {&c, &a, &b};
    
    for (int i=0; i<3; ++i) {
        std::cout << *ptr_arr[i] << std::endl;
    }
```

## 2.Array Pointer
- 배열이 포인터로 관리되기는 하지만, 배열 자체를 나타내는 포인터가 필요했다. 왜?
- 다차원 배열부터는 순수 포인터만을 통해서 다차원 배열을 다루기 힘들기 때문 -> 몇 개로 묶이는 지를 알아야 한다.
- C++에는 Partial Array (Sub-array) 라는 개념이 존재하기 때문.

```
    int arr1[3] = {1,2,3};
    int arr2[2][3] = {{1,2,3}, {2,3,4}}; // 메모리 상에서는 1열로 작성이 되니까
    int arr3[2][2][3] = {
        {{1,2,3}, {2,3,4}},
        {{1,2,3}, {2,3,4}}
    };

    int* ptr = arr1; // 이건 됨
    
    // int** dptr = arr2; // 이건 안됨
    int (*dptr)[3] = arr2; // 배열 자체를 포인터로 만들어주면 가능
    
    int (*ptr3)[2][3] = arr3;
    
    std::cout << dptr[1][0] << std::endl;
    // 배열이 아닌 포인터라는 점을 알면됨.

    int* ptr4 = &arr2[0][0];
    for (int i=0; i<6; i++) {
        std::cout << ptr4[i] << " ";
        if ((i+1)%3 == 0) std::cout << std::endl;
    }
```

## 다차원 포인터 배열
```
    int arr2[2][3] = {{1,2,3}, {2,3,4}};
    int* ptr4 = &arr2[0][0];
```
```
/---Comprehension of Computer---\ /--------- Main Memory ---------\
+--variable--+-------type--------+------address------+----data----+
|            |          int[1][2]|       #520        |    4       |
+------------+-------------------+-------------------+------------+
|            |          int[1][1]|       #516        |    3       |
+------------+-------------------+-------------------+------------+
|            |  int[1], int[1][0]|       #512        |    2       |
+------------+-------------------+-------------------+------------+
|            |          int[0][2]|       #508        |       3    |
+------------+-------------------+-------------------+------------+
|            |          int[0][1]|       #504        |      2     |
+------------+-------------------+-------------------+------------+
|     arr2   |  int[0], int[0][0]|       #500        |      1     |
+------------+-------------------+-------------------+------------+
|     ptr4   |      int*         |       #400쯤       |    #500    |
+------------+-------------------+-------------------+------------+

```
- 다차원 배열 -> Double Pointer 못했지않는가? -> 사실 함수의 인자로 넣어줄 때는 가능하다!
```
int main(const int argc, const char** argv) {
    // argument의 변경이 없으면 const로 하는게 더 빠름.
    
    // g++ -o runfile main.cpp -lm
    // ./runfile hello world 123
    // 위와 같이 파라미터를 직접 입력하는대로 받는 것이 가능.

    for (int i=0; i<argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    return 0;
}
```

## Dynamic Allocation(동적 할당)

```
/---Comprehension of Computer---\ /--------- Main Memory ---------\
+--variable--+-------type--------+------address------+----data----+ Stack(High)
|            |                   |                   |            |
+------------+-------------------+-------------------+------------+
|            |                   |                   |            |
+------------+-------------------+-------------------+------------+
|            |                   |                   |            |
+------------+-------------------+-------------------+------------+
|            |                   |                   |            |
+------------+-------------------+-------------------+------------+
|            |                   |                   |            |
+------------+-------------------+-------------------+------------+
|            |                   |                   |            |
+------------+-------------------+-------------------+------------+ Heap(Low)

```

- 어떤 메모리 영역(heap)을 사용하겠다고 예약을 해두고, 사용을 하는것.
- stack에는 사용 불가
- 사용 시기 : 변수, 클래스, 배열을 사용하고 싶은데 얼마나 사용이 될 지 크기를 모를 때
- C-Style : 할당 -> 해제 / malloc,realloc, calloc / malloc -> free
- C++-Style : 할당 -> 해제 / new -> delete

### C-Style
```
    // 크기가 5인 배열
    int* array = (int*)malloc(sizeof(int)*5);
    array[3] = 4;
    std::cout << array[3] << std::endl;
    free(array);
    
    //std::cout << array[3] << std::endl; // dangling pointer(아무것도 나타내는게 없음)
```

### C++-Style
```
    // 크기가 5인 배열
    int* array = new int[5];
    array[3] = 4;
    std::cout << array[3] << std::endl;
    delete[] array;
```

## 다차원 배열 동적할당

```
    //4 x 5 배열 동적
    // 요즘 코딩트랜드 자체가 array pointer의 입지가 줄어듦(유저가 어떤 값을 넣을지를 모르니 모든 케이스를 다루어야함)

    int (*array)[5] = new int[4][5]; // Compile Time Constant
    auto array = new int[4][5]; // since C++11 부터는 auto 사용

    std::cout << array[3] << std::endl;
    delete[] array;
```

```
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
```

## [++ 필독 ++]
- Q1. lvalue reference type에서 함수의 return type으로 주는 부분이 잘 이해가 안 가요.
- A1: lvalue reference type은 새로운 변수라고 생각하시면됩니다. 제가 알려드린 바와 같이 '서로 다른 이름의 동일한 변수'가 lvalue reference type이라고 볼 수 있습니다. 하지만, 함수의 return type이 되는 경우에는 함수의 return 값이 무명의 변수가 된다고 생각하시면 됩니다.  array(0)을 통해 함수를 불렀을 때, return 값인 return arr[0] 자체가 하나의 변수명이 된다고 생각하시면 됩니다. 그리고 static 변수를 사용했기 때문에 namespace가 static 변수에 한해서만 main 함수의 namespace와 array 함수의 namespace가 공유될 수 있습니다.


- Q2. Double Pointer와 Pointer Array는 어떤 상관관계가 있나요?
- A2: Array는 Pointer로 관리될 수 있기 때문에, Pointer Array에서  Array 부분이 다시 Pointer로 관리될 수 있음을 보여주고자 했습니다. 함수 인자가 아닌 경우에는 순수하게 Pointer로만 다차원 배열을 관리할 수는 없습니다. 따라서 Pointer Array는 부분적으로 Double Pointer라고 할 수 있습니다. 따라서 Pointer Array는 완벽하게 Double Pointer는 아닙니다. Array가 Pointer는 아니다의 예시가 되는 경우라고 할 수 있습니다.


- Q3. Double Pointer와 Array Pointer는 어떤 상관관계가 있나요?
- A3: Double Pointer의 개념 자체는 '포인터 변수의 주소를 저장하는 포인터'라고 볼 수 있습니다. 하지만, 사용하는 이유는 다차원 배열을 순수하게 Pointer로만 다루려고 하는 것에 대한 도전이라고 할 수 있습니다. <정적 다차원 배열>을 다루기 위해 Double Pointer를 사용하려고 했지만, 오히려 Single Pointer형태로 귀결되었다고 볼 수 있습니다. int arr[4][5];의 정적 다차원 배열을 강의에서와 같이 int* ptr = arr; 이런식으로도 충분히 관리할 수 있지만, 그나마 int (*ptr)[5] = arr; 처럼 Array Pointer로 연속적인 주소 공간을 포인터로 나타내게끔 만들어 약간의 가독성을 올렸다고 볼 수 있습니다. (사람에 따라, int* ptr = arr도 가능한데 굳이 그렇게 해야하나?라는 분들도 있습니다. 시간이 지나면서, 이런 경향이 더 많아졌다고 찌라시처럼 들은 적이 있네요.)
    그 이후 동적할당의 중요성이 커지면서 <동적 다차원 배열>을 동적할당하며 Array Pointer로 관리하는 것은 효율이 매우 떨어지기 때문에 Double Pointer를 사용하는 방식으로 자연스레 옮겨갔다고 보시면 됩니다.


- Q4. 그렇다면 왜 Double Pointer 카테고리에 Pointer Array와 Array Pointer를 넣어두었나요?
- A4. 항상 Array는 Pointer로 관리된다는 말을 달고 왔기 때문인 이유가 가장 큽니다. 그래서 Array Pointer와 Pointer Array는 이름이 매우 헷갈리기도 하고, 동적할당과 연관이 크기 때문입니다. 추가로 매번 강조해왔던 'Array를 Pointer로'에 대한 반례로 생각하는 혼동을 줄 수도 있을 것 같다는 생각이 들어서 헷갈리지 않으셨으면 하는 바람으로 같이 넣었습니다.

- Q5. Pointer Array의 예시로 {&a, &b, ...} 이렇게 int자료형의 주소가 원소로 되어 있었고, 포인터는 주소를 받으니깐 이해가 됐어요. 그렇지만 문자열의 경우는 {"John", "Sam", "Anne", ...}가 잘 이해가 안 되기도 하고 예시가 잘못된 것이 아닌가 싶어요. &a 출력하면 16진법 주소가 나오지만 james는 주소가 나오지는 않잖아요. (실제 질문)
- A5. 제가 강조하고자 했던 부분은 문자열은 결국 character pointer와 다르지 않다는 것입니다.  &a이 가능한 이유는 a가 변수이기 때문이에요. 변수가 아니라면 애초에 &로 주소를 가져올 수 없습니다. (&을 쓸 수 있느냐 없느냐는 정확히는 lvalue냐 rvalue냐 차이에요) 물론 제가 알려드린 것과 같이 코딩하고 컴파일한다면 Warning을 내뿜을 것입니다(이런 식으로 짜는 건 그렇게 좋지 않아요. 포인터 관리 형식을 확인해보시면 좋을 것 같아요.). 
```
int main(){
    char var1 = 'a';
    char* names[3] = {"James", "Amy", "Gaby"};
    char var2 = 'a'; // to check a stack address
					 
    printf("%x\n", &var1);
    for (int i=0; i<3; ++i) printf("%x %s\n", &names[i], names[i]);
    printf("%x\n", &var2);

    char* ptr = (char*)malloc(1); // to check a heap address
    printf("%x\n", ptr);
    free(ptr);

    return 0;
}
```
위 코드의 실행 결과를 분석해보면 결국 이렇습니다. 먼저 주어진 문자열을 모두 Stack에 작성하고, Amy, James의 첫 주소를 그 다음 메모리 영역에 8byte 단위(혹은 4byte일 수 있음)로 Stack에 저장한다. 그리고 names라는 배열은 문자열이 직접적으로 작성된 공간을 관리하는 것이 아니라 문자열의 주소가 저장된 메모리 영역을 관리하는 것입니다. 따라서 결국에는 이 또한 Pointer Array가 되는 것입니다.
