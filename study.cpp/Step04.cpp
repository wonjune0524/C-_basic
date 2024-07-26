// 04-1

/*

// RectangleFault.cpp      => 클래스의 멤버변수가 public으로 선언되었을 때 발생할 수 있는 문제점에 대한 예제

#include <iostream>

using namespace std;

class Point
{
public:
   int x;      // x 좌표의 범위는 0 이상 100 이하
   int y;      // y 좌표의 범위는 0 이상 100 이하
};

class Rectangle
{
public:
   Point upLeft;
   Point lowRight;

public:
   void ShowRecInfo()
   {
      cout << "좌 상단: " << '[' << upLeft.x << ", ";
      cout << upLeft.y << ']' << endl;
      cout << "우 하단: " << '[' << lowRight.x << ", ";
      cout << lowRight.y << ']' << endl;
   }
};

int main(void)
{
   Point pos1 = { -2, 4 };
   Point pos2 = { 5, 9 };
   Rectangle rec = { pos2, pos1 };
   rec.ShowRecInfo();

   return 0;
}

*/

/*

// Point.cpp      => Point.h 의 함수들 모음

#include <iostream>
#include  "Point.h"

using namespace std;

bool Point::InitMembers(int xpos, int ypos)
{
    if (xpos < 0 || ypos < 0)
    {
        cout << "벗어난 범위의 값 전달" << endl;

        return false;
    }

    x = xpos;
    y = ypos;

    return true;
}

int Point::GetX() const      // const 함수!
{
    return x;
}

int Point::GetY() const      // const 함수에 대해서는 잠시 후에 설명
{
    return y;
}

bool Point::SetX(int xpos)
{
    if (xpos < 0 || xpos > 100)
    {
        cout << "벗어난 범위의 x값 전달" << endl;

        return false;
    }

    x = xpos;

    return true;
}

bool Point::SetY(int ypos)
{
    if (ypos < 0 || ypos >> 100)
    {
        cout << "벗어난 범위의 y값 전달" << endl;

        return false;
    }

    y = ypos;

    return true;
}

// Rectangle.cpp

#include <iostream>
#include "Rectangle.h"

using namespace std;

bool Rectangle::InitMembers(const Point& ul, const Point& lr)
{
    if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
    {
        cout << "잘못된 위치정보 전달" << endl;
        return false;
    }

    upLeft = ul;
    lowRight = lr;

    return true;
}

void Rectangle::ShowRecInfo() const
{
    cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << ']' << endl;
    cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
    cout << lowRight.GetY() << ']' << endl;
}

// RectangleFaultFind.cpp

#include <iostream>
#include "Point.h"
#include "Rectangle.h"

using namespace std;

int main(void)
{
    Point pos1;

    if (!pos1.InitMembers(-2, 4))               // 출력
    {
        cout << "초기화 실패" << endl;
    }
    if (!pos1.InitMembers(2, 4))
    {
        cout << "초기화 실패" << endl;
    }

    Point pos2;
    if (!pos2.InitMembers(5, 9))
    {
        cout << "초기화 실패" << endl;
    }

    Rectangle rec;
    if (!rec.InitMembers(pos2, pos1))            // 출력
    {
        cout << "직사각형 초기화 실패" << endl;
    }
    if (!rec.InitMembers(pos1, pos2))
    {
        cout << "직사각형 초기화 실패" << endl;
    }

    rec.ShowRecInfo();

    return 0;
}

*/

/*

// 문제 04-1 [정보은닉과 const]

#include <iostream>

using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    int SaleApples(int money)
    {
        if (money < 0)
        {
            cout << "잘못된 정보가 전달되어 판매를 취소합니다." << endl;
            return 0;
        }

        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }

    void ShowSalesResult() const
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller& seller, int money)
    {
        if (money < 0)
        {
            cout << "잘못된 정보가 전달되어 구매를 취소합니다." << endl;
        }

        numOfApples += seller.SaleApples(돈);
        myMoney -= money;
    }

    void ShowBuyResult() const
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}

*/

// 04-2

/*

// Encaps1.cpp

#include <iostream>

using namespace std;

class SinivelCap           // 콧물 처치용 캡슐
{
public:
    void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SneezeCap             // 재채기 처치용 캡슐
{
public:
    void Take() const { cout << "재채기가 멎습니다." << endl; }
};

class SnuffleCap            // 코막힘 처치용 캡슐
{
public:
    void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class ColdPatient
{
public:
    void TakeSinivelCap(const SinivelCap& cap) const { cap.Take(); }
    void TakeSneezeCap(const SneezeCap& cap) const { cap.Take(); }
    void TakeSnuffleCap(const SnuffleCap& cap) const { cap.Take(); }
};

int main(void)
{
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient sufferer;
    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSneezeCap(zcap);
    sufferer.TakeSnuffleCap(ncap);

    return 0;
}

*/

/*

// Encaps2.cpp

#include <iostream>

using namespace std;

class SinivelCap            // 콧물 처치용 캡슐
{
public:
    void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SneezeCap             // 재채기 처치용 캡슐
{
public:
    void Take() const { cout << "재채기가 멎습니다." << endl; }
};

class SnuffleCap            // 코막힘 처치용 캡슐
{
public:
    void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class CONTAC600
{
private:
    SinivelCap sin;
    SneezeCap sne;
    SnuffleCap snu;

public:
    void Take() const
    {
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient
{
public:
    void TakeCONTAC600(const CONTAC600& cap) const { cap.Take(); }
};

int main(void)
{
    CONTAC600 cap;
    ColdPatient sufferer;
    sufferer.TakeCONTAC600(cap);

    return 0;
}

*/

/*

// 문제 04-2 [다양한 클래스의 정의]

#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }

    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle
{
private:
    Point point;            // 원의 중심
    int radius;             // 반지름

public:
    void Init(int x, int y, int r)
    {
        point.Init(x, y);
        radius = r;
    }

    void ShowRingInfo() const
    {
        cout << "radius: " << radius << endl;
        point.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle circle1, circle2;

public:
    void Init(int x1, int y1, int r1, int x2, int y2, int r2)
    {
        circle1.Init(x1, y1, r1);
        circle2.Init(x2, y2, r2);
    }

    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..." << endl;
        circle1.ShowRingInfo();
        cout << "Outter Circle Info..." << endl;
        circle2.ShowRingInfo();
    }
};

int main(void)
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();

    return 0;
}

*/

// 04-3

/*

// Constructor1.cpp             => 생성자 오버로딩

#include <iostream>

using namespace std;

class SimpleClass
{
private:
    int num1;
    int num2;

public:
    SimpleClass()
    {
        num1 = 0;
        num2 = 0;
    }

    SimpleClass(int n)
    {
        num1 = n;
        num2 = 0;
    }

    SimpleClass(int n1, int n2)
    {
        num1 = n1;
        num2 = n2;
    }
*/

/*
SimpleClass(int n1 = 0, int n2 = 0)
{
    num1 = n1;
    num2 = n2;
}
*/


/*

    void ShowData() const
    {
        cout << num1 << ' ' << num2 << endl;
    }
};

int main(void)
{
    SimpleClass sc1;
    sc1.ShowData();

    SimpleClass sc2(100);
    sc2.ShowData();

    SimpleClass sc3(100, 200);
    sc3.ShowData();

    return 0;
}

*/

/*

// Constructor2.cpp

#include <iostream>

using namespace std;

class SimpleClass
{
private:
    int num1;
    int num2;

public:
    SimpleClass(int n1 = 0, int n2 = 0)         // 이 코드에서 이 함수는 호출되지 않는 듯하다.
    {
        num1 = n1;
        num2 = n2;
    }

    void ShowData() const
    {
        cout << num1 << ' ' << num2 << endl;
    }
};

int main(void)
{
    SimpleClass sc1();              // 아래에 정의된 함수의 원형 선언!
    SimpleClass mysc = sc1();       // SimpleClass라는 class에 객체 생성!
    mysc.ShowData();

    return 0;
}

SimpleClass sc1()
{
    SimpleClass sc(20, 30);

    return sc;
}

*/

/*

// FruitSaleSim2.cpp

#include <iostream>

using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    FruitSeller(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    int SaleApples(int money)
    {
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;

        return num;
    }

    void ShowSalesResult() const
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl << endl;
   }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;

public:
    FruitBuyer(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller& seller, int money)
    {
        numOfApples += seller.SaleApples(돈);
        myMoney -= money;
    }

    void ShowBuyResult() const
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}

*/

/*

// FruitSaleSim3.cpp

#include <iostream>

using namespace std;

class FruitSeller
{
private:
    const int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    FruitSeller(int price, int num, int money)
        : APPLE_PRICE(price), numOfApples(num), myMoney(돈)
    {
        // empty
    }

    int SaleApples(int money)
    {
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;

        return num;
    }

    void ShowSalesResult() const
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;

public:
    FruitBuyer(int money)
        : myMoney(돈), numOfApples(0)
    {
        // empty
    }

    void BuyApples(FruitSeller& seller, int money)
    {
        numOfApples += seller.SaleApples(돈);
        myMoney -= money;
    }

    void ShowBuyResult() const
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}

*/

/*

// ReferenceMember.cpp

#include <iostream>

using namespace std;

class AAA
{
public:
    AAA()
    {
        cout << "empty object" << endl;
    }

    void ShowYourName()
    {
        cout << "I'm class AAA" << endl;
    }
};

class BBB
{
private:
    AAA& ref;
    const int& num;

public:
    BBB(AAA& r, const int& n)
        : ref(r), num(n)
    {
        // empty constructor body
    }

    void ShowYourName()
    {
        ref.ShowYourName();
        cout << "and" << endl;
        cout << "I ref num " << num << endl;
    }
};

int main(void)
{
    AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();

    return 0;
}

*/

/*

// PrivateConstructor.cpp

#include <iostream>

using namespace std;

class AAA
{
private:
    int num;

public:
    AAA()
        : num(0)
    {
        // empty
    }

    AAA& CreateInitObj(int n) const
    {
        AAA* ptr = new AAA(n);

        return *ptr;
    }

    void ShowNum() const
    {
        cout << num << endl;
    }

private:
    AAA(int n)
        : num(n)
    {
        // empty
    }
};

int main(void)
{
    AAA base;
    base.ShowNum();

    AAA& obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    AAA& obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

    delete& obj1;
    delete& obj2;

    return 0;
}

*/

/*

// Destructor.cpp

#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char* name;
    int age;

public:
    Person(const char* myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }

    ~Person()
    {
        delete[]name;
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2("Jang dong gun", 41);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}

*/

// 문제 04-3 [C++ 기반의 데이터 입출력]

/*

// 문제 1

#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y)
        : xpos(x), ypos(y)
    {
        // empty
    }

    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle
{
private:
    int rad;            // 반지름
    Point center;       // 원의 중심

public:
    Circle(int x, int y, int r)
        : rad(r), center(x, y)
    {
        // empty
    }

    void ShowCircleInfo() const
    {
        cout << "radius: " << rad << endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle inCircle;
    Circle outCircle;

public:
    Ring (int inX, int inY, int inR, int outX, int outY, int outR)
        : inCircle(inX, inY, inR), outCircle(outX, outY, outR)
    {
        // empty
    }

    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..." << endl;
        inCircle.ShowCircleInfo();
        cout << "Outter Circle Info..." << endl;
        outCircle.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();

    return 0;
}

*/

/*

// 문제 2

#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
    enum { CLERK, SENIOR, ASSIST, MANAGER };

    void ShowGrade(int grd)
    {
        switch (grd)
        {
        case CLERK:
            cout << "사원" << endl;
            break;
        case SENIOR:
            cout << "주임" << endl;
            break;
        case ASSIST:
            cout << "대리" << endl;
            break;
        case MANAGER:
            cout << "과장" << endl;
            break;
        }
    }
}

class NameCard
{
private:
    char* name;
    char* corp;
    char* phone;
    int grade;

public:
    NameCard(const char* Name, const char* CorpName, const char* PhoneNumber, int Grade)
        : grade(Grade)
    {
        int len1 = strlen(Name) + 1;
        name = new char[len1];
        strcpy(name, Name);

        int len2 = strlen(CorpName) + 1;
        corp = new char[len2];
        strcpy(corp, CorpName);

        int len3 = strlen(PhoneNumber) + 1;
        phone = new char[len3];
        strcpy(phone, PhoneNumber);
    }

    void ShowNameCardInfo()
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << corp << endl;
        cout << "전화번호: " << phone << endl;
        cout << "직급: "; COMP_POS::ShowGrade(grade);
        cout << endl;
    }

    ~NameCard()
    {
        delete[]name;
        delete[]corp;
        delete[]phone;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    return 0;
}

*/

// 04-4

/*

// ObjArr.cpp

#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char* name;
    int age;

public:
    Person(char* myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    Person()
    {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }

    void SetPersonInfo(char* myname, int myage)
    {
        name = myname;
        age = myage;
    }

    void ShowPersonInfo() const
    {
        cout << "이름: " << name << ", ";
        cout << "나이: " << age << endl;
    }

    ~Person()
    {
        delete[]name;
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person parr[3];             // 객체 배열 선언
    char namestr[100];
    char* strptr;
    int age;
    int len;

    for (int i = 0; i < 3; i++)
    {
        cout << "이름: ";
        cin >> namestr;
        cout << "나이: ";
        cin >> age;

        len = strlen(namestr) + 1;
        strptr = new char[len];
        strcpy(strptr, namestr);
        parr[i].SetPersonInfo(strptr, age);
    }

    parr[0].ShowPersonInfo();
    parr[1].ShowPersonInfo();
    parr[2].ShowPersonInfo();

    return 0;
}

*/

/*

// ObjPtrArr.cpp

#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char* name;
    int age;

public:
    Person(char* myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    Person()
    {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }

    void SetPersonInfo(char* myname, int myage)
    {
        name = myname;
        age = myage;
    }

    void ShowPersonInfo() const
    {
        cout << "이름: " << name << ", ";
        cout << "나이: " << age << endl;
    }

    ~Person()
    {
        delete[]name;
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person* parr[3];
    char namestr[100];
    int age;

    for (int i = 0; i < 3; i++)
    {
        cout << "이름: ";
        cin >> namestr;
        cout << "나이: ";
        cin >> age;
        parr[i] = new Person(namestr, age);
    }

    parr[0]->ShowPersonInfo();
    parr[1]->ShowPersonInfo();
    parr[2]->ShowPersonInfo();
    delete parr[0];
    delete parr[1];
    delete parr[2];

    return 0;
}

*/

/*

// PointerThis.cpp

#include <iostream>
#include <cstring>

using namespace std;

class SoSimple
{
private:
    int num;

public:
    SoSimple(int n)
        : num(n)
    {
        cout << "num = " << num << ", ";
        cout << "address = " << this << endl;
    }

    void ShowSimpleData()
    {
        cout << num << endl;
    }

    SoSimple* GetThisPointer()
    {
        return this;
    }
};

int main(void)
{
    SoSimple sim1(100);
    SoSimple* ptr1 = sim1.GetThisPointer();     // sim1 객체의 주소 값 저장
    cout << ptr1 << ", ";
    ptr1->ShowSimpleData();

    SoSimple sim2(200);
    SoSimple* ptr2 = sim2.GetThisPointer();     // sim2 객체의 주소 값 저장
    cout << ptr2 << ", ";
    ptr2->ShowSimpleData();

    return 0;
}

*/

/*

// UsefulThisPtr.cpp

#include <iostream>

using namespace std;

class TwoNumber
{
private:
    int num1;
    int num2;

public:
    TwoNumber(int num1, int num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    }

*/

    /*
    TwoNumber(int num1, int num2)
        : num1(num1), num2(num2)
    {
        // empty
    }
    */

/*

    void ShowTwoNumber()
    {
        cout << this->num1 << endl;     // this 포인터 생략 가능
        cout << this->num2 << endl;     // this 포인터 생략 가능
    }
};

int main(void)
{
    TwoNumber two(2, 4);
    two.ShowTwoNumber();

    return 0;
}

*/

/*

// SelfRef.cpp

#include <iostream>

using namespace std;

class SelfRef
{
private:
    int num;

public:
    SelfRef(int n)
        : num(n)
    {
        cout << "객체생성" << endl;
    }

    SelfRef& Adder(int n)
    {
        num += n;
        return *this;
    }

    SelfRef& ShowTwoNumber()
    {
        cout << num << endl;
        return *this;
    }
};

int main(void)
{
    SelfRef obj(3);
    SelfRef& ref = obj.Adder(2);

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();

    return 0;
}

*/