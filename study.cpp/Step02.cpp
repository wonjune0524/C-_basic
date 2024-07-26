// 02-2

/*

// TrueAndFalse.cpp

#include <iostream>

using namespace std;

int main(void)
{
   int num = 10;
   int i = 0;

   cout << "true: " << true << endl;
   cout << "false: " << false << endl;

   while (true)
   {
      cout << i++ << ' ';

      if (i > num)
      {
         break;
      }
   }

   cout << endl;

   cout << "sizeof 1: " << sizeof(1) << endl;
   cout << "sizeof 0: " << sizeof(0) << endl;
   cout << "sizeof true: " << sizeof(true) << endl;
   cout << "sizeof false: " << sizeof(false) << endl;

   return 0;
}

*/

/*

// DataTypeBool.cpp

#include <iostream>

using namespace std;

bool IsPositive(int num)      // 함수 선언 및 정의
{
   if (num <= 0)
   {
      return false;
   }

   else
   {
      return true;
   }
}

int main(void)
{
   bool isPos;
   int num;
   cout << "Input number: ";
   cin >> num;

   isPos = IsPositive(num);

   if (isPos)      // if true,
   {
      cout << "Positive number" << endl;
   }

   else         // if false,
   {
      cout << "Negative number" << endl;
   }

   return 0;
}

*/

// 02-3

/*

// Referen.cpp

#include <iostream>

using namespace std;

int main(void)
{
   int num1 = 1020;
   int& num2 = num1;      // 참조자 선언

   num2 = 3047;
   cout << "VAL: " << num1 << endl;
   cout << "REF: " << num2 << endl;

   cout << "VAL: " << &num1 << endl;      // 주소 값 출력
   cout << "REF: " << &num2 << endl;

   return 0;
}

*/

/*

// RefArrElem.cpp

#include <iostream>

using namespace std;

int main(void)
{
   int arr[3] = { 1,3,5 };
   int& ref1 = arr[0];
   int& ref2 = arr[1];
   int& ref3 = arr[2];

   cout << ref1 << endl;
   cout << ref2 << endl;
   cout << ref3 << endl;

   return 0;
}

*/

/*

// RefPtr.cpp

#include <iostream>

using namespace std;

int main(void)
{
   int num = 12;
   int* ptr = &num;
   int** dptr = &ptr;

   int& ref = num;
   int* (&pref) = ptr;
   int** (&dpref) = dptr;

   cout << ref << endl;
   cout << *pref << endl;
   cout << **dpref << endl;

   return 0;
}

*/

// 02-4

/*

// RefSwap.cpp

#include <iostream>

using namespace std;

void SwapByRef2(int& ref1, int& ref2)
{
   int temp = ref1;
   ref1 = ref2;
   ref2 = temp;
}

int main(void)
{
   int val1 = 10;
   int val2 = 20;

   SwapByRef2(val1, val2);

   cout << "val1: " << val1 << endl;
   cout << "val2: " << val2 << endl;

   return 0;
}

*/

// 문제 02-1 [참조자 기반의 Call-by-reference 구현]

/*

// 문제 1

#include <iostream>

using namespace std;

void PlusByRef(int& ref1)
{
   ref1++;
}

void ChangeByRef(int& ref2)
{
   ref2 = ref2 * (-1);
}

int main(void)
{
   int val1 = 100;
   int val2 = 200;

   PlusByRef(val1);
   ChangeByRef(val2);

   cout << "val1: " << val1 << endl;
   cout << "val2: " << val2 << endl;

   return 0;
}

*/

// 문제 2

// SwapByRef2 함수는 참조자 기반의 Call-By-Reference 함수호출이다. 따라서 참조자가 변수로 초기화되어야 하는데, 다음{SwapByRef2(23,45)} 과 같이 변수가 아닌 상수값이 주어지게 되면,
// 참조자 선언 자체가 불가능하기 때문에 컴파일 에러가 발생할 수 밖에 없을 것이다.

/*

// 문제 3 - 참조자를 이용한 call-by-reference 함수 호출 방법

#include <iostream>

using namespace std;

void SwapPointer(int* (&pref1), int* (&pref2))
{
   int* mark = pref1;
   pref1 = pref2;
   pref2 = mark;
}

int main(void)
{
   int num1 = 5;
   int* ptr1 = &num1;

   int num2 = 10;
   int* ptr2 = &num2;

   cout << "ptr1: " << *ptr1 << endl;
   cout << "ptr2: " << *ptr2 << endl;

   SwapPointer(ptr1, ptr2);

   cout << "ptr1: " << *ptr1 << endl;
   cout << "ptr2: " << *ptr2 << endl;

   return 0;
}

*/

/*

// 문제 3 - 주소 값을 이용한 call-by-reference 함수 호출 방법

#include <iostream>

using namespace std;

void SwapPointer(int* ref1, int* ref2)
{
   int mark = *ref1;
   *ref1 = *ref2;
   *ref2 = mark;
}

int main(void)
{
   int num1 = 5;
   int* ptr1 = &num1;

   int num2 = 10;
   int* ptr2 = &num2;

   cout << "ptr1: " << *ptr1 << endl;
   cout << "ptr2: " << *ptr2 << endl;

   SwapPointer(ptr1, ptr2);

   cout << "ptr1: " << *ptr1 << endl;
   cout << "ptr2: " << *ptr2 << endl;

   return 0;
}

*/

/*

// RefReturnOne.cpp

#include <iostream>

using namespace std;

int& RefRetFuncOne(int& ref)
{
   ref++;
   return ref;
}

int main(void)
{
   int num1 = 1;
   int& num2 = RefRetFuncOne(num1);      // 함수 선언에 &가 없으면, 우항의 값이 상수가 되어서 참조자 선언이 불가능해짐. 우항은 num1 자체를 지칭함.
   // int &num2 = num1;
   // int &num2 = ref;

   num1++;
   num2++;

   cout << "num1: " << num1 << endl;
   cout << "num2: " << num2 << endl;

   return 0;
}

*/

/*

// RefReturnTwo.cpp

#include <iostream>

using namespace std;

int& RefRetFuncOne(int& ref)
{
   ref++;
   return ref;
}

int main(void)
{
   int num1 = 1;
   int num2 = RefRetFuncOne(num1);

   num1 += 1;
   num2 += 100;

   cout << "num1: " << num1 << endl;
   cout << "num2: " << num2 << endl;

   return 0;
}

*/

/*

// RefReturnTwo.cpp

#include <iostream>

using namespace std;

int RefRetFuncTwo(int& ref)
{
   ref++;
   return ref;
}

int main(void)
{
   int num1 = 1;
   int num2 = RefRetFuncTwo(num1);

   num1 += 1;
   num2 += 100;

   cout << "num1: " << num1 << endl;
   cout << "num2: " << num2 << endl;

   return 0;
}

*/

/*

// 문제 02-2 [const 포인터와 const 참조자]

#include <iostream>

using namespace std;

int main(void)
{
   const int num = 12;
   const int* p = &num;
   const int* (&pref) = p;

   cout << "num: " << num << endl;
   cout << "num by p: " << *p << endl;
   cout << "num by pref: " << *pref << endl;

   return 0;
}

*/

// 02-5

/*

// MemMalFree.cpp

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

char* MakeStrAdr(int len)
{
   char* str = (char*)malloc(sizeof(char) * len);

   return str;
}

int main(void)
{
   char* str = MakeStrAdr(20);
   strcpy(str, "I am so happy~");
   cout << str << endl;
   free(str);

   return 0;
}

*/

/*

// NewDelete.cpp

#include <iostream>
#include <string.h>

using namespace std;

char* MakeStrAdr(int len)
{
   // char* str = (char*)malloc(sizeof(str) * len);
   char* str = new char[len];

   return str;
}

int main(void)
{
   char* str = MakeStrAdr(20);
   strcpy(str, "I am so happy~");
   cout << str << endl;
   // free(str);
   delete[]str;

   return 0;
}

*/

/*

// NewObject.cpp

#include <iostream>
#include <stdlib.h>

using namespace std;

class Simple
{
public:
   Simple()
   {
      cout << "I am simple constructor!" << endl;
   }
};

int main(void)
{
   cout << "case 1: ";
   Simple* sp1 = new Simple;

   cout << "case 2: ";
   Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);

   cout << endl << "end of main" << endl;
   delete sp1;
   free(sp2);

   return 0;
}

*/

/*

// 문제 02-3 [구조체에 대한 new & delete 연산]

#include <iostream>

using namespace std;

typedef struct __Point
{
   int xpos;
   int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
   Point* pptr = new Point;
   pptr->xpos = p1.xpos + p2.xpos;
   pptr->ypos = p1.ypos + p2.ypos;

   return *pptr;
}

int main(void)
{
   Point* pptr1 = new Point;
   pptr1->xpos = 10;
   pptr1->ypos = 100;

   Point* pptr2 = new Point;
   pptr2->xpos = 20;
   pptr2->ypos = 200;

   Point& pref = PntAdder(*pptr1, *pptr2);
   cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;

   delete pptr1;
   delete pptr2;
   delete& pref;

   return 0;
}

*/

// 02-6

/*

// StdCPPFunc.cpp

#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
   char str1[] = "Result";
   char str2[30];

   strcpy(str2, str1);
   printf("%s: %f \n", str1, sin(0.14));
   printf("%s: %f \n", str2, abs(-1.25));

   return 0;
}

*/

/*

// 문제 02-4 [C++의 표준함수 호출]

// 문제 1

#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char abc[] = "ABC 123 ";
    char* str1 = abc;

    char def[] = "DEF 456 ";
    char* str2 = def;
    char str3[50];

    cout << strlen(str1) << endl;
    cout << strlen(str2) << endl;
    strcpy(str3, str1);
    strcat(str3, str2);
    cout << str3 << endl;

    if (strcmp(str1, str2) == 0)
    {
        cout << "문자열이 같다." << endl;
    }

    else
    {
        cout << "문자열이 같지 않다." << endl;
    }

    return 0;
}

*/

/*

// 문제 2

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        int ran_num = 0;
        ran_num = rand() % 100;

        cout << ran_num << endl;
    }

    return 0;
}

*/