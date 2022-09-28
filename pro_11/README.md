## 11>

## C++ 공식문서 읽기
- C++ 문서 1 - https://www.cplusplus.com
- C++ 문서 2 - https://en.cppreference.com/w/
- string => substr,find 등 여러가지 함수들이 있고 공식 문서 참고해서 사용하기.

## ISSUE on COPY
- Shallow Copy vs. Deep Copy

- Default Copy Constructor (Shallow Copy)
    - 아래처럼 생긴 기본 카피생성자가 자동으로 적용중.(얕은 복사)
    - 동적할당을 하는 경우 문제가 생김.
```
Student(const Student& rhs) {
    this->m_id = rhs.m_id;
    this->m_name = rhs.m_name
}
```

## Double free문제
- 예를들어, class student를 사용해 student1 이라는 객체를 생성하고
- student 객체를 복사한 student2를 생성 후
- id를 동적할당 후 메모리 해제 하게 되면 에러가 발생하게 되는데
- 이유는 student1는 제대로 해제가 되고 student2도 이어서 해제를 하게되는데
- 이미 student1 에서 id라는 변수의 메모리를 해제 했으므로 2는 해제를 할 부분이 없게되버림.
- 프로세스 자체가 종료되어버리는 문제가 발생!
- 해당 문제는 shallow copy(얕은복사)로 인해 발생한 문제이므로 deep copy(깊은복사)를 사용해야 한다.

```
class Student {
    private:
        int* m_id = nullptr;
        std::string m_name;
    public:
        Student(int, std::string);
        ~Student();

    // ID
    void setID(const int id) {
        *(this->m_id) = id;
    }
    int getID() {
        return *(this->m_id);
    }

    // NAME
    void setID(const std::string name) {
        this->m_name = name;
    }
    std::string getName() {
        return this->m_name;
    }
};

Student::Student(const int id, const std::string name) : m_id{new int(id)}, m_name{name} {
    
}

Student::~Student() {
    if (m_id) delete m_id;
    std::cout << "freed" << std::endl;
}

int main () {
    Student student = Student(20220928, "James");
    Student student2 = Student(student);
    
    std::cout << student.getID() << " " <<  student.getName() <<std::endl;
    std::cout << student2.getID() << " " <<  student2.getName() <<std::endl;

    return 0;    
}
```


## Deep Copy
- User-Defined Copy Constructor
- 실제 값을 새로운 메모리 공간에 복사를 하는것

```
class Student {
    private:
        int* m_id = nullptr;
        std::string m_name;
    public:
        Student(int, std::string);
        ~Student();

        //User-Defined Copy Constructor (Deep Copy)
        Student(const Student& rhs) {
            this->m_id = new int(*rhs.m_id);
            this->m_name = rhs.m_name;
        }

    // ID
    void setID(const int id) {
        *(this->m_id) = id;
    }
    int getID() {
        return *(this->m_id);
    }

    // NAME
    void setID(const std::string name) {
        this->m_name = name;
    }
    std::string getName() {
        return this->m_name;
    }
};

Student::Student(const int id, const std::string name) : m_id{new int(id)}, m_name{name} {
    
}

Student::~Student() {
    if (m_id) delete m_id;
    std::cout << "freed" << std::endl;
}

int main () {
    Student student = Student(20220928, "James");
    Student student2 = Student(student);
    
    std::cout << student.getID() << " " <<  student.getName() <<std::endl;
    std::cout << student2.getID() << " " <<  student2.getName() <<std::endl;

    return 0;    
}
```

## Extra Keywords for Class
1) static
    - 메모리 상에서 정적영역에 따로 저장을 시킨다.
    - Stack 이나 Heap이 아니다 !!(아예 다른 메모리 영역)
    - 객체가 몇 개가 되든 unique하다.
    - Static Function은 항상 Static Variable만 사용이 가능하다.
    - Static에 대해서는 this pointer사용이 불가능하다
        - this pointer는 클래스 또는 멤버 함수를 부른 객체 그 자체를 명시적으로 가져오기 위해 사용하는데, static 변수 혹은 함수는 각 객체에 종속된 것이 아닌 모든 객체들이 공유하는 Unique한(유일한) 변수 또는 함수이기 때문에
    - When?
        - Member Variable
        - Member Function
    - Why?
        - 객체 생성과 상관 없이 클래스 이름을 통해서 값이나 함수에 접근하기 위해서
            (static의 의미와 상관이 있다)
        - private인 statice member variable에 접근할 때 사용

```
class MyClass {
    private:
    public:
        static int smv; // static은 선언만 가능(초기화 불가능)
        static int smf() {
            return smv;
        }
        
        MyClass();
        ~MyClass();
        int getSMV(){return this->smv};
};

MyClass::MyClass() {

}

MyClass::~MyClass() {

}

int MyClass::smv= 10; //이런식으로 전역으로 선언해야 변수에 값을 전달하는 것이 가능.

int main() {
    std::cout << MyClass::smf() << std::endl;
    return 0;
}
```

2) const
    - 함수자체가 const 라는 것은 어떤 멤버변수와 연관지을때 그 멤버변수의 수정이 없음을 의미(안전)

```
class MyClass {
    private:
    public:
        int mv;

        const int getValue() const {
            return mv;
        }

        // const라서 변수의 값을 변경하는게 불가능.
        // void setValue() const {
        //     mv = val;
        // }

        MyClass(const int);
       ~MyClass();
};

MyClass::MyClass(const int val) : mv{val} {

}

MyClass::~MyClass() {

}


int main() {
    MyClass mc = MyClass(10);

    std::cout << mc.getValue() << std::endl;
    return 0;
}
```
3) inline
    - pro_7 참조
4) friend
    - A. 종류
        - friend function
        - multiple friend functions
        - friend classes
        - friend member functions
    - B. 의미
        - friend 키워드가 사용된 클래스 에 대해서 private 영역을 외부함수,클래스가 접근할 수
        있도록 만드는 것.
        - '(클래스) { ...friend (키워드 대상) ... }'
        - (키워드 대상)이 (클래스) 에 대한 private 접근 권한을 얻는다.
        - 즉, 접근 허용 대상이 ClassName의 클래스 private 영역에 접근가능해진다.
        ```
        class [ClassName] {
            ...
            friend[접근 허용 대상];
            ...
        }
        ```
    - C. 목적
        - 함수나 클래스가 다른 클래스에 대한 권한을 얻는 것이기 때문에
        - 함수나 클래스가 다른 클래스와 연관은 되어 있지만, 떼어 놓고 싶을 때 사용한다.

## 1)friend function
- 간단한 예제
```
class MyClass {
    private:
        int a;
    public:
        MyClass(int n) : a(n){};
        ~MyClass();
        
        friend void func(const MyClass& mc);
};

// MyClass::MyClass(){};
MyClass::~MyClass(){};

// 이 외부 함수가 MyClass 내부의 함수에 접근하도록 하려면?
void func(const MyClass& mc) {
    // std::cout << a << std::endl; // 이런식으로 직접 접근은 안됨
    std::cout << mc.a << std::endl;
}

int main() {
    MyClass mc = MyClass(10);
    func(mc);

    return 0;
}
```

## 2. multiple friend function
- 온도와 습도를 입력받아 출력하는 함수 예제
- friend 함수를 이용하면 공통함수인 printWeather가 두 클래스에 접근가능.
- getter,setter를 만들어서도 사용 가능하지만, 코드가 짧아지고 속도도 어느정도 개선가능!

```
class Humidity; // 프로토타입을 선언해야 Temperature 클래스 에서 밑의 Humidity 클래스를 인지가능.

class Temperature {
    private:
        int m_temp {};
    public:
        Temperature(int temp=0) : m_temp { temp }{}

        friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

class Humidity {
    private:
        int m_humidity {};
    public:
        Humidity(int humidity=0): m_humidity { humidity }{}

        friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

void printWeather(const Temperature& temperature, const Humidity& humidity) {
    std::cout << "The temperature is " << temperature.m_temp <<
        " and the humidity is " << humidity.m_humidity << '\n';
}

int main() {
    Humidity hum = Humidity(1);
    Temperature temp = Temperature(2);

    printWeather(temp, hum);

    return 0;
}
```

## 3. friend classes
- Temperature class의 내부에 friend class Humidity 를 선언하면, Humidity class가
Temperature class에 대한 접근 권한을 얻게 된다는 의미.

```
class Temperature {
    private:
        int m_temp {};
    public:
        Temperature(int temp=0) : m_temp { temp }{}

        friend void printWeather(const Temperature& temperature, const Humidity& humidity);
        friend class Humidity; // Humidity 클래스가 Temperature 클래스 내부 접근권한을 얻는것.
};

class Humidity {
    private:
        int m_humidity {};
    public:
        Humidity(int humidity=0): m_humidity { humidity }{}

        friend void printWeather(const Temperature& temperature, const Humidity& humidity);
        
        // 아래의 함수는 Temperature Class에 접근이 필요한 함수
        double calcHum(const Temperature& temp) {
            return (double) temp.m_temp;
        }
};
```

## 4. friend member functions
- 2,3번의 조합이라고 볼 수 있음.
- 정의를 완전히 밑으로 빼주는 게 활용하기 좋음.
```
class Temperature;

class Humidity {
    private:
        int m_humidity {};
    public:
        Humidity(int humidity=0): m_humidity { humidity }{}

        void printWeather(const Temperature& Temperature);
};

class Temperature {
    private:
        int m_temp {};
    public:
        Temperature(int temp=0) : m_temp { temp }{}

        friend void Humidity::printWeather(const Temperature& temperature);
};

void Humidity::printWeather(const Temperature& temperature) {
    std::cout << "The temperature is " << temperature.m_temp <<
    " and the humidity is " << m_humidity << '\n';
}

int main() {

    return 0;
}
```