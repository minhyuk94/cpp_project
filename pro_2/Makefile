CMP = g++
TARGET = runfile
OBJS = main.o

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CMP) -o $@ $^

# 모든 cpp를 아래 형식으로 컴파일
.cpp.o :
	$(CMP) -c -o $@ $<