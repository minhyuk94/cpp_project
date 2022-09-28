## 10>

### Object-Oriented Programming (OOP)
1) Abstraction(추상화)
    - 실제 동작 코드와 함수 프로토 타입을 분리시키는 것.
2) Encapsulation(캡슐화)
    - 유저가 알 필요가 없거나 사용하지 말아야 할 그러한 일종의 변수,함수들을 안보이게 하는것.
3) Inheritance(상속)
4) polymorphism(다형성)

```
class User {
    private:
        int _id;
        int _pw;
    public:
        void setID(const int id);
        const int getID();
        void setPW(const int pw);
        const int getPW();
};

void User::setID(const int id) {
    _id = id;
}
const int User::getID() {
    return _id;
}

void User::setPW(const int pw) {
    _pw = pw;
}
const int User::getPW() {
    return _pw;
}

int main() {
    User user;
    user.setID(100);
    user.setPW(123);

    std::cout << user.getID() << " " << user.getPW() << std::endl;
}
```

## Constructor(생성자)
- 클래스의 객체가 생성이 될 때 자동으로 불리는 특별한 메소드 (method = member function)
- 생성자는 return 자체가 불가능 하기 때문에 return type이 없다.(void가 아니라 아예 없음)
- 해당 클래스와 완전히 동일한 함수 이름을 갖는다.

```
class User {
    private:
        int _id;
        int _pw;
    public:
        User(); //생성자 선언
        void setID(const int id);
        const int getID();
        void setPW(const int pw);
        const int getPW();
};

void User::setID(const int id) {
    _id = id;
}
const int User::getID() {
    return _id;
}

void User::setPW(const int pw) {
    _pw = pw;
}
const int User::getPW() {
    return _pw;
}

// 생성자
User::User() {
    _id = (int) NULL;
    _pw = (int) NULL;
    std::cout << "Constructor" << std::endl;
}

int main() {
    User user = User(); // 생성자로 만든 User로 선언
    user.setID(100);
    user.setPW(123);

    std::cout << user.getID() << " " << user.getPW() << std::endl;
}
```

## Destuctor(소멸자)
- 클래스의 객체 수명이 다하면, 자동으로 불리는 특별한 메소드 (생성자와 같이 return type이 없음)
- 해당 클래스와 비슷한 함수 이름을 갖는다. (~Class)
- 소멸자가 필요한 이유? => new, malloc 등이 사용 됐을 때, 메모리 해제를 해주어야 한다.

```
class User {
    private:
        int _id;
        int* _pw;
    public:
        User(); //생성자 선언
        ~User(); //소멸자 선언
        void setID(const int id);
        const int getID();
        void setPW(const int pw);
        const int getPW();
};

void User::setID(const int id) {
    _id = id;
}
const int User::getID() {
    return _id;
}

void User::setPW(const int pw) {
    _pw = new int(pw);
}
const int User::getPW() {
    return *_pw;
}

// 생성자
User::User() {
    _id = (int) NULL;
    _pw = nullptr;
    std::cout << "Constructor" << std::endl;
}
// 소멸자
User::~User() {
    if(_pw) delete _pw;
    std::cout << "Destructor" << std::endl;
}

int main() {
    User user = User(); // 생성자로 만든 User로 선언
    user.setID(100);
    user.setPW(123);

    std::cout << user.getID() << " " << user.getPW() << std::endl;
}
```

## Variable Initialization(변수 초기화)
- Function Overloading
- 초기화 방식에는 총 3가지가 존재

1) Class::Class(...){....}
    - 생성자에 파라미터를 넣어 좀 더 간결하게 클래스 구성 가능.
    - 가장 쉬운 방식
```
class User {
    private:
        int _id;
        int _pw;
    public:
        User(); //생성자 선언
        User(int id, int pw); // 생성자2선언(overloading)
        ~User(); //소멸자 선언
        void setID(const int id);
        const int getID();
        void setPW(const int pw);
        const int getPW();
};

void User::setID(const int id) {
    _id = id;
}
const int User::getID() {
    return _id;
}

void User::setPW(const int pw) {
    _pw = int(pw);
}
const int User::getPW() {
    return _pw;
}

// 생성자
User::User() {
    _id = (int) NULL;
    _pw = (int) NULL;
    std::cout << "Constructor" << std::endl;
}

// 생성자2(Overloading)
User::User(int id, int pw) {
    _id = id;
    _pw = pw;
    std::cout << "Constructor2" << std::endl;
}

// 소멸자
User::~User() {
    // if(_pw) delete _pw;
    std::cout << "Destructor" << std::endl;
}

int main() {
    User user = User(100, 123); // 생성자2를 통해 선언 및 데이터 입력
    std::cout << user.getID() << " " << user.getPW() << std::endl;
}
```

2) Class::Class(...) : var_1{arg_1}, var_2{arg_2}, ... , var_n(arg_n) {}
    - 가독성이 좋음.
```
User::User(int id, int pw) : _id{id}, _pw{pw} {
    std::cout << "Constructor3" << std::endl;
}
```

3) Class::Class() : Class(...){}
    - 다른 생성자를 이용해서 기본형식을 사용하는 형식
    - 로직
        - 메인 함수에서 가장 기본형태의 User() 호출
        - 파라미터 값이 생성자2의 선언형태이므로 생성자2로 이동
        - 이후 생성자1의 바디로 이동
        - 메인함수 종료 시 Destructor 실행

```
class User {
    private:
        int _id;
        int _pw;
    public:
        User(); //생성자 선언
        User(int id, int pw);
        ~User(); //소멸자 선언
        void setID(const int id);
        const int getID();
        void setPW(const int pw);
        const int getPW();
};

void User::setID(const int id) {
    _id = id;
}
const int User::getID() {
    return _id;
}

void User::setPW(const int pw) {
    _pw = int(pw);
}
const int User::getPW() {
    return _pw;
}

// 생성자
User::User() : User((int)NULL, (int)NULL){ 
    std::cout << "Constructor" << std::endl;
}

// 생성자2
User::User(int id, int pw) : _id{id}, _pw{pw} {
    std::cout << "Constructor2" << std::endl;
}

// 소멸자
User::~User() {
    // if(_pw) delete _pw;
    std::cout << "Destructor" << std::endl;
}

int main() {
    User user = User();

    std::cout << user.getID() << " " << user.getPW() << std::endl;
}
```

## This Pointer
- 자기 자신을 나타내는 포인터(객체 자체의 주소)
- 어떤 객체로 부터 기인한 것인지에 대해서 나타내기 위해
- 하나의 클래스로부터 파생된 객체는 독립적이지만 특정 영역은 공유가 될 수 있기 때문에 변수 충돌을 방지하기 위해
- this->변수
- class, instance, object
    - class를 만들어 메모리에 올리고(instance화) 특정이름의 object 가 됨.
    - my = MyClass(); // my(object), MyClass()(Class), my를 만드는 과정(instance)