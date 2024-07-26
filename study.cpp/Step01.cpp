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
   std::cout << "ù ��° �����Է�: ";
   std::cin >> val1;

   double val2;
   std::cout << "�� ��° �����Է�: ";
   std::cin >> val2;

   double result = val1 + val2;
   std::cout << "�������: " << result << std::endl;

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
   std::cout << "�� ���� �����Է�: ";
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

   std::cout << "�� �� ������ ���� ��: " << result << std::endl;

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

   std::cout << "�̸��� �����Դϱ�? ";
   std::cin >> name;

   std::cout << "�����ϴ� ���α׷��� ���� �����ΰ���? ";
   std::cin >> lang;

   std::cout << "�� �̸��� " << name << "�Դϴ�.\n";
   std::cout << "���� �����ϴ� ���� " << lang << "�Դϴ�." << std::endl;

   return 0;
}

*/

// ���� 01-1 [C++ ����� ������ �����]

/*

// ���� 1

#include <iostream>

int main(void)
{
   int result = 0;

   for (int i = 1; i <= 5; i++)
   {
      int num = 0;
      std::cout << i << "��° ���� �Է�: ";
      std::cin >> num;

      result += num;
   }

   std::cout << "�հ�: " << result << std::endl;
   return 0;
}

*/

/*

// ���� 2

#include <iostream>

int main(void)
{
   char name[20], phone[30];

   std::cout << "�̸�: ";
   std::cin >> name;

   std::cout << "��ȭ��ȣ: ";
   std::cin >> phone;

   std::cout << "����� �̸��� " << name << " �̸� ����� ��ȭ��ȣ�� " << phone << " �̴�.\n";

   return 0;
}

*/

/*

// ���� 3

#include <iostream>

int main(void)
{
   int num;
   std::cout << "���ڸ� �Է��ϼ���. �ش� ������ �������� ����ص帮�ڽ��ϴ�. ";
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

// ���� 4

#include <iostream>

int main(void)
{
   while (1)
   {
      int pay = 0;

      std::cout << "�Ǹ� �ݾ��� �Է����ּ���: ";
      std::cin >> pay;

      if (pay == -1)
      {
         std::cout << "���α׷��� �����մϴ�.";
         break;
      }

      else
      {
         std::cout << "�̹� �� �޿�: " << 50 + pay * 0.12 << "����" << std::endl;
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

// ���� 01-2 [�Լ� �����ε�]

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
   std::cout << Adder(5) << std::endl;     // num1 �� 5 ����
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
   std::cout << Adder(5) << std::endl;     // num1 �� 5 ����
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
   // std::cout << "[D, D, D] : " << BoxVolume() << std::endl;     , length�� ���� �������� �ʾ����Ƿ� �̴� ������ ������ �̾���.

   return 0;
}

*/

/*

// ���� 1

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
   // std::cout << "[D, D, D] : " << BoxVolume() << std::endl;     , length�� ���� �������� �ʾ����Ƿ� �̴� ������ ������ �̾���.

   return 0;
}

*/

/*

// ���� 2

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
   // std::cout << SimpleFunc() << std::endl;     => ���� �߻�, ���� �Է� �� �� �Լ��� �浹�ϱ� ����.
   std::cout << SimpleFunc(100) << std::endl;     // => ���� �Լ��� ��µ�.     �� �Լ��� �����ε��� ������ �����Ѵ�.
}

*/

// 01-4

/*

// ��ũ�� �Լ� ����

#include <iostream>
#define SQUARE(x) ((x)*(x))

int main(void)
{
   std::cout << SQUARE(5) << std::endl;
   return 0;
}

// �� �ڵ� ��ó�� ����

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

// ���ø� ����

#include <iostream>

template <typename T>
inline T SQUARE(T x)
{
   return x * x;
}

int main(void)
{
   std::cout << SQUARE(5.5) << std::endl;     // ������ �ս� �ذ�
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
        std::cout << "BestCom�� ������ �Լ�" << std::endl;
    }
}

namespace ProgComImp1
{
    void SimpleFunc(void)
    {
        std::cout << "Progcom�� ������ �Լ�" << std::endl;
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

// NameSp2.cpp - �Լ��� ����� ���� ����

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
    std::cout << "BestCom�� ������ �Լ�" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
    std::cout << "ProgCom�� ������ �Լ�" << std::endl;
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
    std::cout << "BestCom�� ������ �Լ�" << std::endl;
    PrettyFunc();     // ���� �̸�����
    ProgComImp1::SimpleFunc();     // �ٸ� �̸�����
}

void BestComImp1::PrettyFunc(void)
{
    std::cout << "So Pretty!!" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
    std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}

*/

/*

// ���� 01-4 [������ ����]

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

// ���� 01-2 ����

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