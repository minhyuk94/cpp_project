## 7

## Function Overloading
- Function Overloading : 여러개의 동일한 함수를 올려서 사용하는것.
- C++ 에서는 자동으로 function overloading시켜줌(C++이 강력한 이유중 하나)
- 파라미터 인자의 갯수가 달라도 자동으로 오버로딩됨
```
double square(double x) {
    std::cout << "DOUBLE" << std::endl;
    return x*x;
}

int square(int x) {
    std::cout << "INT" << std::endl;
    return x*x;
}

int main() {
    std::cout << square(3) << std::endl;
    std::cout << square(2.3f) << std::endl;
    return 0;
}
```

## Default Argument(디폴트 값)
- Default Argument : 디폴트 값을 넣어준다.
- 파라미터를 넣지않고 함수를 호출해도 기본적으로 디폴트값을 넣어줌.(필요하다면 항상 최소로 맨끝으로)
- 보통 boolean 형태로 많이 넣어씀.
- Function Declaration(함수의 선언만 상단에 해주고 실제 함수는 메인함수 밑으로) 할 경우 반드시
- 메인함수 밑의 실제 함수는 default argument를 빼야함(선언에만)

```
double square(double x, bool b = true);

int main() {
    std::cout << square(2.4f, false) << std::endl;
    return 0;
}

double square(double x, bool b) {
    if (b)
        std::cout << "DOUBLE" << std::endl;
    return x*x;
}
```

### inline function
- 10줄이하의 함수를 짜게 된다면, 인라인 함수를 짜는 것이 좋음
- '대치'가 되어서 컴파일된다.(매크로 함수와 같은 동작)
- 매크로 함수와 차이점은 inline 은 컴파일러에게 함수 '대치'를 제안한다(받아들이지 않을 수도 있음)
- 단, inline 함수는 void에는 적용되지않음.

```
inline double square(double x) {
    return x*x;
}

int main() {
    std::cout << square(2.4f) << std::endl;
    // std::cout << 2.4f*2.4f << std::endl; 이런식으로 대치됨.
    return 0;
}
```

## Swap Operation
- a = 1, b = 2 --> a = 2, b = 1
- swap함수는 독립적으로 동작하기 때문에 포인터를 사용해야 변경된 값을 가져올 수 있음.

```
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void ptr_swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1{1}, num2{2};

    // normal swap(정상 동작 x)
    swap(num1, num2);
    std::cout << num1 << " " << num2 << std::endl;

    // pointer swap
    ptr_swap(&num1, &num2);
    std::cout << num1 << " " << num2 << std::endl;
    return 0;
}
```

### Return pointer
- static variable
- 포인터를 활용 함으로써 변수,함수의 활용성이 증대됨.
- 안쪽에 있는 static 변수를 초기화 할 수 있는 것이 '포인터'

```
int* foo() {
    static int count = 0;
    count++;
    return &count;
}

void reset(int* count) {
    *count = 0;
    return;
}

int main() {
    int* cnt;
    
    for(int i=0; i<5; ++i) cnt = foo();
    std::cout << *cnt << std::endl;

    reset(cnt);
    std::cout << *cnt << std::endl;

    cnt = foo();
    std::cout << *cnt << std::endl;


    return 0;
}
```

### Functional Programming
```
int* foo() {
    static int count = 0;
    count++;
    return &count;
}

// 반복함수
void iterate(int n, int* (*function)()) {
    for (int i=0; i<n; ++i) function();
}

int main() {
    // 데이터타입과 펑션포인터가 구분되도록 선언해야함.
    int* cnt;
    int* (*fp)() = foo;
    iterate(4, foo); // 이것도 성립하지만
    cnt = fp(); //function 자체를 포인터로 만들어 사용하는 것이 효율이 좋음.
    std::cout << *cnt << std::endl;

    return 0;
}
```

## Argument Array(배열을 함수 인자로 넣도록)
- array를 포인터로 관리
- 보통 1,2차원 선에서 코딩하는 걸 추천(그 이상은 효율이나 관리가 어려움)

```
int arraySum(int* arr, int size) { //int arr[] 도 가능.(단, 다차원 배열은 안됨)
    int sum{0};
    for (int i=0; i<size; ++i) sum += arr[i];
    return sum;
}

int main() {
    int array[5] = {1,2,3,4,5};
    std::cout << arraySum(array, sizeof(array)/sizeof(int)) << std::endl; // 20/4
    return 0;
}
```

## return array
- doubling 예제
```
char* doubling(char* str) {
    int size{0};
    for (int i=0;;++i) {
        if (str[i] == '\0') break;
        size++;
    }
    for (int i=0; i<size; ++i) {
        str[i+size] = str[i];
    }
    // str = "abc" (size = 3)
    return str;
}

int main() {
    char str[100] = "Hello, World! ";
    std::cout << doubling(str) << std::endl;
    return 0;
}
```
## Reference Type
- Reference Type 을 통해서도 swap 가능.
- 서로 다른 이름을 가진 동일한 변수.(주소까지 완전히 동일, 한주소에 이름이 똑같은 게 존재하는것)
- a = num1 , b = num2

```
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
```