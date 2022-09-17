## 데이터 타입 관련 내용

### 1. Data type (자료형)

int (integer, 정수) / float (floating point, 실수) / char (character, 문자) / bool (boolean, 참거짓)
void (무형 - 타입자체가 존재 하지 않음)

(1) int
    <부호, + - >
        signed (일반적으로 생략됨, 안쓰는게 기본) : - ~ + 
        unsigned : 0 ~ + (양수만)
    
    <크기>
        short (int) : 2Byte = 16Bit = 2^16 = 65536 개의 수
        int : 4Byte = 32Bit = 2^32 개의 수
        long (int) : 4Byte/8Byte
        long long (int) : 4Byte/8Byte

    <cover 설명>
        short : -2^15 ~ 2^15-1 (무조건 끝 범위 -1 해야함(국제표준))
        unsigned short : 0 ~ 2^16-1
        int : -2^31 ~ 2^31-1
        unsigned int : 0 ~ 2^31 -1

(2) float
    signed (일반적으로 생략됨, 안쓰는게 기본) : - ~ + 
    unsigned : 0 ~ + (양수만)

    <크기>
        float   :   4Byte (정확도가 떨어짐, 숫자가 커지고 데이터가 많아질경우 문제의 가능성이 높음)
        double  :   8Byte
        long double : 8?

(3) char
    (signed)
    unsigned

    <크기>
        char    :   1Byte = 256개의 수 / ASCII Code Table : 128개 - 0 ~ 127

Main Memory 구조 => 변수,타입,주소,데이터
ex) int a = 0
    variable : a
    type : int
    address : #10
    data : 0

참조 : cppreference.com 을 참조해서 모르는 부분을 찾아보는 것이 중요.