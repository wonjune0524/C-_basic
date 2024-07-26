// 01-1

/*

// HelloWorld.cpp

#include <iostream>

int main(void)
{
   int num = 20;
   std::cout << "Hello World!" << std::endl;
   std::cout << "Hello " << "World!" << std::endl;
   std::cout << num << ' ' << 'A';
   std::cout << ' ' << 3.14 << std::endl;

   return 0;
}

*/

/*

// SimpleAdder.cpp

#include <iostream>

int main(void)
{
   double val1;
   std::cout << "첫 번째 숫자입력: ";
   std::cin >> val1;

   double val2;
   std::cout << "두 번째 숫자입력: ";
   std::cin >> val2;

   double result = val1 + val2;
   std::cout << "덧셈결과: " << result << std::endl;

   return 0;
}

*/

/*

//BetweenAdder.cpp

#include <iostream>

int main(void)
{
   int val1, val2;
   int result = 0;
   std::cout << "두 개의 숫자입력: ";
   std::cin >> val1 >> val2;

   if (val1 < val2)
   {
      for (int i = val1 + 1; i < val2; i++)
      {
         result += i;
      }
   }

   else
   {
      for (int i = val2 + 1; i < val1; i++)
      {
         result += i;
      }
   }

   std::cout << "두 수 사이의 정수 합: " << result << std::endl;

   return 0;
}

*/

/*

// StringIO.cpp

#include <iostream>

int main(void)
{
   char name[100];
   char lang[200];

   std::cout << "이름은 무엇입니까? ";
   std::cin >> name;

   std::cout << "좋아하는 프로그래밍 언어는 무엇인가요? ";
   std::cin >> lang;

   std::cout << "내 이름은 " << name << "입니다.\n";
   std::cout << "제일 좋아하는 언어는 " << lang << "입니다." << std::endl;

   return 0;
}

*/

// 문제 01-1 [C++ 기반의 데이터 입출력]

/*

// 문제 1

#include <iostream>

int main(void)
{
   int result = 0;

   for (int i = 1; i <= 5; i++)
   {
      int num = 0;
      std::cout << i << "번째 정수 입력: ";
      std::cin >> num;

      result += num;
   }

   std::cout << "합계: " << result << std::endl;
   return 0;
}

*/

/*

// 문제 2

#include <iostream>

int main(void)
{
   char name[20], phone[30];

   std::cout << "이름: ";
   std::cin >> name;

   std::cout << "전화번호: ";
   std::cin >> phone;

   std::cout << "당신의 이름은 " << name << " 이며 당신의 전화번호는 " << phone << " 이다.\n";

   return 0;
}

*/

/*

// 문제 3

#include <iostream>

int main(void)
{
   int num;
   std::cout << "숫자를 입력하세요. 해당 숫자의 구구단을 출력해드리겠습니다. ";
   std::cin >> num;
   std::cout << std::endl;

   for (int i = 1; i <= 9; i++)
   {
      std::cout << num << " x " << i << " = " << num * i << std::endl;
   }

   return 0;
}

*/

/*

// 문제 4

#include <iostream>

int main(void)
{
   while (1)
   {
      int pay = 0;

      std::cout << "판매 금액을 입력해주세요: ";
      std::cin >> pay;

      if (pay == -1)
      {
         std::cout << "프로그램을 종료합니다.";
         break;
      }

      else
      {
         std::cout << "이번 달 급여: " << 50 + pay * 0.12 << "만원" << std::endl;
      }
   }

   return 0;
}

*/

// 01-2

/*

// FunctionOverloading.cpp

#include <iostream>

void MyFunc(void)
{
   std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c)
{
   std::cout << "MyFunc(char c) called " << c << std::endl;
}

void MyFunc(int a, int b)
{
   std::cout << "MyFunc(int a, int b) called " << a << " " << b << std::endl;
}

int main(void)
{
   MyFunc();
   MyFunc('A');
   MyFunc(12, 13);

   return 0;
}

*/

/*

// 문제 01-2 [함수 오버로딩]

#include <iostream>

void SwapFunc(int num1, int num2)
{
   int mark = num1;
   num1 = num2;
   num2 = mark;

   std::cout << num1 << ' ' << num2 << std::endl;
}

void SwapFunc(char ch1, char ch2)
{
   char mark = ch1;
   ch1 = ch2;
   ch2 = mark;

   std::cout << ch1 << ' ' << ch2 << std::endl;
}

void SwapFunccc(float db1, float db2)
{
   float mark = db1;
   db1 = db2;
   db2 = mark;

   std::cout << db1 << ' ' << db2 << std::endl;
}

int main(void)
{
   int num1 = 20, num2 = 30;
   char ch1 = 'A', ch2 = 'Z';
   double db1 = 1.111, db2 = 5.555;

   SwapFunc(num1, num2);
   SwapFunc(ch1, ch2);
   SwapFunccc(db1, db2);

   return 0;
}

*/

// 01-3

/*

// DefaultValue1.cpp

#include <iostream>

int Adder(int num1 = 1, int num2 = 2)
{
   return num1 + num2;
}

int main(void)
{
   std::cout << Adder() << std::endl;
   std::cout << Adder(5) << std::endl;     // num1 에 5 대입
   std::cout << Adder(3, 5) << std::endl;

   return 0;
}

*/

/*

// DefaultValue2.cpp

#include <iostream>

int Adder(int num1 = 1, int num2 = 2);

int main(void)
{
   std::cout << Adder() << std::endl;
   std::cout << Adder(5) << std::endl;     // num1 에 5 대입
   std::cout << Adder(3, 5) << std::endl;

   return 0;
}

int Adder(int num1, int num2)
{
   return num1 + num2;
}

*/

/*

// DefaultValue3.cpp

#include <iostream>

int BoxVolume(int length, int width = 1, int height = 1)
{
   return length * width * height;
}

int main(void)
{
   std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
   std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
   std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
   // std::cout << "[D, D, D] : " << BoxVolume() << std::endl;     , length에 값이 지정되지 않았으므로 이는 컴파일 에러로 이어짐.

   return 0;
}

*/

/*

// 문제 1

#include <iostream>

int BoxVolume(int length, int width, int height)
{
   return length * width * height;
}

int BoxVolume(int length, int width)
{
   return length * width;
}

int BoxVolume(int length)
{
   return length;
}

int main(void)
{
   std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
   std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
   std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
   // std::cout << "[D, D, D] : " << BoxVolume() << std::endl;     , length에 값이 지정되지 않았으므로 이는 컴파일 에러로 이어짐.

   return 0;
}

*/

/*

// 문제 2

#include <iostream>

int SimpleFunc(int a = 10)
{
   return a + 1;
}

int SimpleFunc(void)
{
   return 10;
}

int main(void)
{
   // std::cout << SimpleFunc() << std::endl;     => 오류 발생, 공백 입력 시 두 함수가 충돌하기 때문.
   std::cout << SimpleFunc(100) << std::endl;     // => 위의 함수로 출력됨.     두 함수는 오버로딩의 조건을 만족한다.
}

*/

// 01-4

/*

// 매크로 함수 예제

#include <iostream>
#define SQUARE(x) ((x)*(x))

int main(void)
{
   std::cout << SQUARE(5) << std::endl;
   return 0;
}

// 위 코드 전처리 과정

#include <iostream>

int main(void)
{
   std::cout << ((5)*(5)) << std::endl;
   return 0
}

*/

/*

// InlineFunc.cpp

#include <iostream>

inline int SQUARE(int x)
{
   return x * x;
}

int main(void)
{
   std::cout << SQUARE(5) << std::endl;
   std::cout << SQUARE(12) << std::endl;

   return 0;
}

*/

/*

// 템플릿 예시

#include <iostream>

template <typename T>
inline T SQUARE(T x)
{
   return x * x;
}

int main(void)
{
   std::cout << SQUARE(5.5) << std::endl;     // 데이터 손실 해결
   std::cout << SQUARE(12) << std::endl;

   return 0;
}

*/

// 01-5

/*

// NameSp1.cpp

#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void)
    {
        std::cout << "BestCom이 정의한 함수" << std::endl;
    }
}

namespace ProgComImp1
{
    void SimpleFunc(void)
    {
        std::cout << "Progcom이 정의한 함수" << std::endl;
    }
}

int main(void)
{
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();

    return 0;
}

*/

/*

// NameSp2.cpp - 함수의 선언과 정의 구분

#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void);
}

namespace ProgComImp1
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();

    return 0;
}

void BestComImp1::SimpleFunc(void)
{
    std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
    std::cout << "ProgCom이 정의한 함수" << std::endl;
}

*/

/*

// NameSp3.cpp

#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void);
    void PrettyFunc(void);
}

//namespace BestComImp1
//{
//    void PrettyFunc(void);
//}

namespace ProgComImp1
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImp1::SimpleFunc();

    return 0;
}

void BestComImp1::SimpleFunc(void)
{
    std::cout << "BestCom이 정의한 함수" << std::endl;
    PrettyFunc();     // 동일 이름공간
    ProgComImp1::SimpleFunc();     // 다른 이름공간
}

void BestComImp1::PrettyFunc(void)
{
    std::cout << "So Pretty!!" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
    std::cout << "ProgCom이 정의한 함수" << std::endl;
}

*/

/*

// 문제 01-4 [파일의 분할]

#include "SimpleFunc.h"

int main(void)
{
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();

    return 0;
}

*/

/*

// UsingDcl1.cpp

#include <iostream>

namespace Hybrid
{
    void HybFunc(void)
    {
        std::cout << "So simple function!" << std::endl;
        std::cout << "In namespace Hybrid!" << std::endl;
    }
}

int main(void)
{
    using Hybrid::HybFunc;
    HybFunc();
    HybFunc();
    HybFunc();

    return 0;
}

*/

/*

// UsingDcl2.cpp

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    int num = 20;
    cout << "Hello World!" << endl;
    cout << "Hello " << "World!" << endl;
    cout << num << ' ' << 'A';
    cout << ' ' << 3.14 << endl;

    return 0;
}

*/

/*

// UsingDcl3.cpp

#include <iostream>

using namespace std;

int main(void)
{
    int num = 20;
    cout << "Hello World!" << endl;
    cout << "Hello " << "World!" << endl;
    cout << num << ' ' << 'A';
    cout << ' ' << 3.14 << endl;

    return 0;
}

*/

/*

// NameAlias.cpp

#include <iostream>
using namespace std;

namespace AAA
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        }
    }
}

int main(void)
{
    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num2 = 30;

    namespace ABC = AAA::BBB::CCC;
    cout << ABC::num1 << endl;
    cout << ABC::num2 << endl;

    return 0;
}

*/

/*

// 문제 01-2 오답

#include <iostream>

void swap(int* a, int* b)
{
    int mark = *a;
    *a = *b;
    *b = mark;
}

void swap(char* a, char* b)
{
    char mark = *a;
    *a = *b;
    *b = mark;
}

void swap(double* a, double* b)
{
    double mark = *a;
    *a = *b;
    *b = mark;
}

int main(void)
{
    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    std::cout << num1 << ' ' << num2 << std::endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1, &ch2);
    std::cout << ch1 << ' ' << ch2 << std::endl;

    double db1 = 1.111, db2 = 5.555;
    swap(&db1, &db2);
    std::cout << db1 << ' ' << db2 << std::endl;
    
    return 0;
}

*/