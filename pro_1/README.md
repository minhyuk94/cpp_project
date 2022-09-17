## 0. 설치 및 기본사항

g++ 설치 확인

컴파일 : g++ -o main.out main.cpp -lm

실행 : ./main.out

## 1. Makefile 만들기

```
CMP = g++
TARGET = runfile
OBJS = main.o

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CMP) -o $@ $^

# 모든 cpp를 아래 형식으로 컴파일
.cpp.o :
	$(CMP) -c -o $@ $<
```

위와 같이 Makefile 작성 후 make 명령어를 터미널에 입력

## 2. shell 실행파일 만들기

```bash
make

# make 결과가 0이면(정상)
if [ ${?} = 0 ]; then
    echo "Compile Success"
    echo "Execution Result"
    echo "===================="
    ./runfile
else
    echo "Compile Error, so not executed"
fi
```

위와 같이 [shell.sh](http://shell.sh) 작성 후 sh shell.sh 명령어를 터미널에 입력