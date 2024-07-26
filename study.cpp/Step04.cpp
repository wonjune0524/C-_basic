// 04-1

/*

// RectangleFault.cpp      => Ŭ������ ��������� public���� ����Ǿ��� �� �߻��� �� �ִ� �������� ���� ����

#include <iostream>

using namespace std;

class Point
{
public:
   int x;      // x ��ǥ�� ������ 0 �̻� 100 ����
   int y;      // y ��ǥ�� ������ 0 �̻� 100 ����
};

class Rectangle
{
public:
   Point upLeft;
   Point lowRight;

public:
   void ShowRecInfo()
   {
      cout << "�� ���: " << '[' << upLeft.x << ", ";
      cout << upLeft.y << ']' << endl;
      cout << "�� �ϴ�: " << '[' << lowRight.x << ", ";
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

// Point.cpp      => Point.h �� �Լ��� ����

#include <iostream>
#include  "Point.h"

using namespace std;

bool Point::InitMembers(int xpos, int ypos)
{
    if (xpos < 0 || ypos < 0)
    {
        cout << "��� ������ �� ����" << endl;

        return false;
    }

    x = xpos;
    y = ypos;

    return true;
}

int Point::GetX() const      // const �Լ�!
{
    return x;
}

int Point::GetY() const      // const �Լ��� ���ؼ��� ��� �Ŀ� ����
{
    return y;
}

bool Point::SetX(int xpos)
{
    if (xpos < 0 || xpos > 100)
    {
        cout << "��� ������ x�� ����" << endl;

        return false;
    }

    x = xpos;

    return true;
}

bool Point::SetY(int ypos)
{
    if (ypos < 0 || ypos >> 100)
    {
        cout << "��� ������ y�� ����" << endl;

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
        cout << "�߸��� ��ġ���� ����" << endl;
        return false;
    }

    upLeft = ul;
    lowRight = lr;

    return true;
}

void Rectangle::ShowRecInfo() const
{
    cout << "�� ���: " << '[' << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << ']' << endl;
    cout << "�� �ϴ�: " << '[' << lowRight.GetX() << ", ";
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

    if (!pos1.InitMembers(-2, 4))               // ���
    {
        cout << "�ʱ�ȭ ����" << endl;
    }
    if (!pos1.InitMembers(2, 4))
    {
        cout << "�ʱ�ȭ ����" << endl;
    }

    Point pos2;
    if (!pos2.InitMembers(5, 9))
    {
        cout << "�ʱ�ȭ ����" << endl;
    }

    Rectangle rec;
    if (!rec.InitMembers(pos2, pos1))            // ���
    {
        cout << "���簢�� �ʱ�ȭ ����" << endl;
    }
    if (!rec.InitMembers(pos1, pos2))
    {
        cout << "���簢�� �ʱ�ȭ ����" << endl;
    }

    rec.ShowRecInfo();

    return 0;
}

*/

/*

// ���� 04-1 [�������а� const]

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
            cout << "�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�." << endl;
            return 0;
        }

        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }

    void ShowSalesResult() const
    {
        cout << "���� ���: " << numOfApples << endl;
        cout << "�Ǹ� ����: " << myMoney << endl << endl;
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
            cout << "�߸��� ������ ���޵Ǿ� ���Ÿ� ����մϴ�." << endl;
        }

        numOfApples += seller.SaleApples(��);
        myMoney -= money;
    }

    void ShowBuyResult() const
    {
        cout << "���� �ܾ�: " << myMoney << endl;
        cout << "��� ����: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "���� �Ǹ����� ��Ȳ" << endl;
    seller.ShowSalesResult();
    cout << "���� �������� ��Ȳ" << endl;
    buyer.ShowBuyResult();

    return 0;
}

*/

// 04-2

/*

// Encaps1.cpp

#include <iostream>

using namespace std;

class SinivelCap           // �๰ óġ�� ĸ��
{
public:
    void Take() const { cout << "�๰�� ��~ ���ϴ�." << endl; }
};

class SneezeCap             // ��ä�� óġ�� ĸ��
{
public:
    void Take() const { cout << "��ä�Ⱑ �ܽ��ϴ�." << endl; }
};

class SnuffleCap            // �ڸ��� óġ�� ĸ��
{
public:
    void Take() const { cout << "�ڰ� �� �ո��ϴ�." << endl; }
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

class SinivelCap            // �๰ óġ�� ĸ��
{
public:
    void Take() const { cout << "�๰�� ��~ ���ϴ�." << endl; }
};

class SneezeCap             // ��ä�� óġ�� ĸ��
{
public:
    void Take() const { cout << "��ä�Ⱑ �ܽ��ϴ�." << endl; }
};

class SnuffleCap            // �ڸ��� óġ�� ĸ��
{
public:
    void Take() const { cout << "�ڰ� �� �ո��ϴ�." << endl; }
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

// ���� 04-2 [�پ��� Ŭ������ ����]

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
    Point point;            // ���� �߽�
    int radius;             // ������

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

// Constructor1.cpp             => ������ �����ε�

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
    SimpleClass(int n1 = 0, int n2 = 0)         // �� �ڵ忡�� �� �Լ��� ȣ����� �ʴ� ���ϴ�.
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
    SimpleClass sc1();              // �Ʒ��� ���ǵ� �Լ��� ���� ����!
    SimpleClass mysc = sc1();       // SimpleClass��� class�� ��ü ����!
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
        cout << "���� ���: " << numOfApples << endl;
        cout << "�Ǹ� ����: " << myMoney << endl << endl;
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
        numOfApples += seller.SaleApples(��);
        myMoney -= money;
    }

    void ShowBuyResult() const
    {
        cout << "���� �ܾ�: " << myMoney << endl;
        cout << "��� ����: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);

    cout << "���� �Ǹ����� ��Ȳ" << endl;
    seller.ShowSalesResult();
    cout << "���� �������� ��Ȳ" << endl;
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
        : APPLE_PRICE(price), numOfApples(num), myMoney(��)
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
        cout << "���� ���: " << numOfApples << endl;
        cout << "�Ǹ� ����: " << myMoney << endl << endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;

public:
    FruitBuyer(int money)
        : myMoney(��), numOfApples(0)
    {
        // empty
    }

    void BuyApples(FruitSeller& seller, int money)
    {
        numOfApples += seller.SaleApples(��);
        myMoney -= money;
    }

    void ShowBuyResult() const
    {
        cout << "���� �ܾ�: " << myMoney << endl;
        cout << "��� ����: " << numOfApples << endl << endl;
    }
};

int main(void)
{
    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);

    cout << "���� �Ǹ����� ��Ȳ" << endl;
    seller.ShowSalesResult();
    cout << "���� �������� ��Ȳ" << endl;
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
        cout << "�̸�: " << name << endl;
        cout << "����: " << age << endl;
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

// ���� 04-3 [C++ ����� ������ �����]

/*

// ���� 1

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
    int rad;            // ������
    Point center;       // ���� �߽�

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

// ���� 2

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
            cout << "���" << endl;
            break;
        case SENIOR:
            cout << "����" << endl;
            break;
        case ASSIST:
            cout << "�븮" << endl;
            break;
        case MANAGER:
            cout << "����" << endl;
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
        cout << "�̸�: " << name << endl;
        cout << "ȸ��: " << corp << endl;
        cout << "��ȭ��ȣ: " << phone << endl;
        cout << "����: "; COMP_POS::ShowGrade(grade);
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
        cout << "�̸�: " << name << ", ";
        cout << "����: " << age << endl;
    }

    ~Person()
    {
        delete[]name;
        cout << "called destructor!" << endl;
    }
};

int main(void)
{
    Person parr[3];             // ��ü �迭 ����
    char namestr[100];
    char* strptr;
    int age;
    int len;

    for (int i = 0; i < 3; i++)
    {
        cout << "�̸�: ";
        cin >> namestr;
        cout << "����: ";
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
        cout << "�̸�: " << name << ", ";
        cout << "����: " << age << endl;
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
        cout << "�̸�: ";
        cin >> namestr;
        cout << "����: ";
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
    SoSimple* ptr1 = sim1.GetThisPointer();     // sim1 ��ü�� �ּ� �� ����
    cout << ptr1 << ", ";
    ptr1->ShowSimpleData();

    SoSimple sim2(200);
    SoSimple* ptr2 = sim2.GetThisPointer();     // sim2 ��ü�� �ּ� �� ����
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
        cout << this->num1 << endl;     // this ������ ���� ����
        cout << this->num2 << endl;     // this ������ ���� ����
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
        cout << "��ü����" << endl;
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