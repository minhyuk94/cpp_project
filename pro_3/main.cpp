#include <iostream>

/*
int main() {
    // Data Type Detection 데이터타입추론
    // c와 c++은 '' 와  "" 가 다름 (작은따옴표는 문자그대로를 출력한다면 큰따옴표는 문자+\0(문자종결자)) 

    auto a = 10;// C++11 부터 사용가능
    std::cout << "Data Type: " << typeid(a).name() << " Value: " << a << std::endl;

    return 0;
}
*/

/*
int main() {
    // 윤년계산 
    // 1. 서력기원 년수가 4로 나눠 떨어지는 해는 윤년으로 한다.
    // 2. 그 (1) 중 100으로 나눠 떨어지는 해는 평년으로 한다.
    // 3. 그 (2) 즁 400으로 나눠 떨어지는 해는 다시 윤년으로 한다.
    
    int year;
    std::cin >> year;
    if (year % 400 == 0) {
        std::cout << 1 << std::endl;
    }
    else if (year % 100 == 0) {
        std::cout << 0 << std::endl;
    }
    else if (year % 4 == 0) {
        std::cout << 1 << std::endl;
    }
    else {
        std::cout << 0 << std::endl;
    }
}
*/



/*
int main() {
    // 0 ~ 2022년 까지의 윤년이 몇 번 있었는지 출력(while)
    int count{0}, year{0};

    while(year <= 2022) {
        if (year % 400 == 0) {
            count++;
    }
    else if (year % 100 == 0) {
        std::cout << 0 << std::endl;
    }
    else if (year % 4 == 0) {
        count++;
    }
    else {
        std::cout << 0 << std::endl;
    }
        year++;
    }

   std::cout << count << std::endl;
}
*/

/*
int main() {

    //do while 문법(무조건 한 번 이상 실행)
    int n = 1, bound = 5; // 5! 구하기

    do{
        n*= bound;
        bound--;
    }
    while(bound > 1);
    std::cout << n << std::endl;
}
*/

/*
int main() {
    //for 문법
    //초기값,조건식,증감식 모두 독립적으로 동작하여 ;;; 이런식으로 아무것도 안적어도 동작은 함.
    
    for (int i=0; i<10; i++) {
       std::cout << i << " ";
    }
    std::cout << std::endl;
}
*/


/*
int main() {
 //Range-Based for loop (문자열에서 하나씩 빼오는)

   char str[] = "Hello, World!"; //제대로 출력이 나오지 않으면 c++filt -t 를 지워주기
   for (char c : str) {
       // [H][e][l]...
       std::cout << "[" << c << "]";
   }
   std::cout << std::endl; // 줄바꿈

   return 0;
}
*/

/*
int main() {
    // break(반복문을 빠져 나올 때), continue(반복문을 '새로' 시작할 때)
    // 가장 가까운 반복문에 대해서!!! 조건의 위치가 중요!!!

    // 3의 배수이면 2번 출력, 15가 넘어가면 그만 출력
    // 4의 배수이면 0번 출력
    int n = 0;

    while(true) 
    {
        n++;
        if (n > 15) break;

        if (n%4 == 0) continue;

        std::cout << n << std::endl;
        if (n%3 == 0) {
            std::cout << n << std::endl;
        }
    }

    return 0;
}
*/

/*
int main() {
    // goto 문법 사용(지정된 레이블로 코드가 이동)
    // 요즘에는 goto를 안쓰는 추세(플로우를 해침)
    // 10 ~ 0 countdown 'liftoff!'
    int n = 10;

countdown:
    std::cout << n << " ";
    n--;
    if(n > 0) goto countdown;
    std::cout << "lift-off!" << std::endl;

    return 0;
}
*/

int main() {

    // switch 는 반드시 break가 필요.

    int n = 1;

    switch (n)
    {
        case 1:
            std::cout << 1 << std::endl;
            break;
        case 2:
            std::cout << 2 << std::endl;
            break;
        default:
            std::cout << "Not-Expected" << std::endl;
            break;
    }
    return 0;
}