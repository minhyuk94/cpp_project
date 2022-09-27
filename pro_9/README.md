## 9>

### const
- const의 위치에 따른 의미
    - 대표적으로 3가지

    - Integer pointer, integer값을 integer pointer로 옮기는 작업(코드)
    - 1. const int& 변수명
    - 2. int* const 변수명
    - 3. const int* const 변수명

- 1. const int 의 포인터 -> int가 const 되었음 -> 포인터 변수가 나타내고 있는 값을 바꾸지 못함
    - 하지만 주소는 변경할 수 있음.

```
int a = 10, b = 20;
    const int* ptr; // const int 의 pointer -> int가 const

    printf("%p\n", &a);
    ptr = &a;
    printf("%p %p\n", &a, ptr);
    printf("%d %d %d\n", a, b, *ptr);

    ptr = &b;
    printf("%d %d %d\n", a, b, *ptr);
```

- 2. int의 const 포인터 -> 변수가 const 되었음 -> 포인터 변수가 지닌 값을 변경하지 못함.(초기화가 안되면 사용 불가)
```
    int a = 10, b = 20;
    int* const ptr = &a;

    printf("%p\n", &a);
    printf("%p %p\n", &a, ptr);

    a = 30;
    printf("%d %d %d\n", a, b, *ptr);
    *ptr = -10;
    printf("%d %d %d\n", a, b, *ptr);
```

- 3.1+2
```
    int a = 10, b = 20;
    const int* const ptr = &a;


    printf("%d %d %d\n", a, b, *ptr);
    a = 20; // a 값이 변하지 않는 한 바꿀수없음.
    printf("%d %d %d\n", a, b, *ptr);
```


## Struct(구조체)

- 객체 : 덩어리 / -> 새로운 데이터 타입을 정의하낟.
- Built-in Data Type : int, float, bool, char, void + (여러 데이터 타입)

- 객체를 왜 만드는가?
    - 결론 : 결국 효율성을 위함
- 대부분 C에서 사용됨, C++에서는 class가 거의 다 대체 가능.
- Struct : 변수들의 리스트(순서가 있음)
- Struct를 만드는 방식에는 크게 2가지가 있다.
    - 1)struct Struct_Name{....};
    - 2)typedef struct{...} Strct_Name;
        - typedef a b => a를 b로 쓰겠다.



### C-Style
```
struct Worker{
    int id;
    const char* name[100]; //메모리를 잘 사용하려면 이렇게 선언. char name[100] 말고
};

int main() {
    struct Worker worker; // C-Style
    worker.id = 1010;
    *worker.name = "John";

    std::cout << worker.id << std::endl;
    std::cout << *worker.name << std::endl;

    return 0;
}
```

### C++ Style
```
struct Worker{
    int id;
    const char* name[100]; //메모리를 잘 사용하려면 이렇게 선언. char name[100] 말고
};

int main() {
    struct Worker* worker;
    worker = new Worker{1010, "John"};

    std::cout << worker->id << " " << *worker->name << std::endl;
    delete worker;

    return 0;
}
```

```
struct Worker{
    int id;
    const char* name[100]; //메모리를 잘 사용하려면 이렇게 선언. char name[100] 말고
};

int main() {

    struct Worker workers[5];

    struct Worker* worker1;
    worker1 = new Worker{1010, "John"};

    workers[0] = *worker1;
    std::cout << worker1->id << " " << *worker1->name << std::endl;
    std::cout << workers[0].id << " " << *workers[0].name << std::endl;
    
    delete worker1;

    return 0;
}
```

- typedef를 사용해서 struct Worker => Worker로 변경
```
typedef struct{
    int id;
    const char* name[100]; //메모리를 잘 사용하려면 이렇게 선언. char name[100] 말고
} Worker;

int main() {

    Worker workers[5];

    Worker* worker1;
    worker1 = new Worker{1010, "John"};

    workers[0] = *worker1;
    std::cout << worker1->id << " " << *worker1->name << std::endl;
    std::cout << workers[0].id << " " << *workers[0].name << std::endl;
    
    delete worker1;

    return 0;
}
```

### Class
- C++을 포함한 객체지향 프로그래밍의 꽃이다.
- Object-Oriented Programming에는 보통 4가지의 개념이 있다.
    - 1. Abstraction : 추상화
    - 2. Encapsulation : 객체화
    - 3. Inheritance : 상속
    - 4. Polymorphism : 다형성

- Class : 단순한 유저가 임의로 정의하는 데이터 타입
- Object : 개별적인 Instance
- Instance : Class라는 데이터 타입을 이용해서 변수 선언을 해서 메모리에 올린 메모리 덩어리의 상태

- Object
    - relevant properties (attributes, 변수)
    - behaviors (methods, functions)

- Accessor : 접근자 (기본적으로 private 상태)
    - private, public, protected
    - public : 바깥에서 누구나 접근 가능.
    - private : member function 접근이 가능한것.
    - member function : Class 내의 정의된 함수.

```
class Worker {
    int id;
    char name[100];
};

int main() {
    Worker worker;
    // worker.id = 1010; // 클래스에 접근이 불가능하므로 접근자가 필요.
    // worker.name = "John";

    return 0;
}
```

## strcpy를 사용하여 값 넣어보기
```
#include <iostream>
#include <string.h> // strcpy

class Worker {
private:
    int id;
public:
    char name[100];
};

int main() {
    Worker worker;
    strcpy(worker.name, "John");
    std::cout << worker.name << std::endl;
    return 0;
}
```

## private, public으로 class 구현
```
#include <iostream>
#include <string.h> // strcpy

class Worker {
// private를 함으로써 외부에서 값을 임의로 변경하는 것이 불가능
private:
    int _id; // _를 붙이면 private라는 의미
public:
    char name[100];
public:
    void setID(int id) {_id = id;} //member function 이므로 private에 접근 가능
    int getID(); // prototype
};

int Worker::getID() {
    return _id;
}

int main() {
    Worker worker;
    worker.setID(1000);
    std::cout << worker.getID() << std::endl;

    strcpy(worker.name, "John");
    std::cout << worker.name << std::endl;
    return 0;
}
```

### 심화 구현
- class를 class main,header로 나누어 main에서 참조하도록
- header 에는 prototype만 작성
- makefile에 파일 추가는 잊지 말 것.