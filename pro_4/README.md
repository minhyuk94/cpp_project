## 4.

### Macro Function

- 매크로 함수는 함수가 선언한 곳을 그대로 대체하여 사용하므로 예를들어

    ``` 
    #define PSUB(x) printf("The value of (10 - x) is %d\n", 10 -x) 
    ```

    을 선언하여 출력하면 x 라는 문자가 치환되지 않고 그대로나오기 때문에 아래처럼 #을 붙여 사용해야 치환됨.


    ```
    #define PSUB2(x) printf("The value of (10 - "#x") is %d\n", 10 -x)
    ```

### 변수

- global(전역) , local(지역) ,static(정적)

### namespace

- main과 겹치지않고 독립시켜서 사용하고 싶을 경우 활용.

    결론적으로 std도 namespace임.

    using namespace를 사용하면 더이상 std:: 이런식으로 선언 하지 않아도됨.

    하지만 namespace의 의의가 메인과 독립시키기 위함이기 때문에 std를 메인함수와 같이 사용하는건 모순.

### header file
- hello.cpp hello.h 작성
- main.cpp 에서 include하여 사용

### Static function
- main에서는 사용 불가능
- 프로토타입으로 등장하면 절대 안됨
- 오직 해당 파일에서만 동작 (ex)hello.cpp에서 static으로 선언하면 다른 파일에서 선언불가)
    - 단, 최신 컴파일러로는 해당 버그가 자동처리됨.

## 기본컴파일 및 실행
- g++ -c main.cpp hello.cpp
- g++ -o runfile main.o hello.o
- ./runfile

## 여러 파일이 섞여 있는 경우 어떻게 Makefile을 수정해야 하는가?

```
CC = gcc
CXX = g++
TARGET = runfile
OBJS = main.o hello.o
# OBJS 에는 반드시 필요한 오브젝트를 전부 작성해줘야함

# Wall = 모든 경고를 보여주기, Werror(경보감지)
# CXXFLAGS = 컴파일 시 필요
CXXFLAGS = -Wall -std=c++17 -g -Werror
# LDFLAGS
LDFLAGS = 
# LDLIBS = linking 할 때
LDLIBS = -lm

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# 모든 cpp를 아래 형식으로 컴파일
.cpp.o :
	$(CXX) -c $(CXXFLAGS) -o $@ $<

# phony는 무슨일이 있어도 실행하라는 명령어
.PHONY: clean
clean :
	rm -f *.o $(TARGET)
```