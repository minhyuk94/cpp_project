CC = gcc
CXX = g++
TARGET = runfile
OBJS = main.o
# OBJS 에는 반드시 필요한 오브젝트를 전부 작성해줘야함

# Wall = 모든 경고를 보여주기, Werror(경보감지), 모든 경고도 에러로 감지하니까 판단 필요. 
# CXXFLAGS = 컴파일 시 필요
CXXFLAGS = -Wall -std=c++17 -g
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