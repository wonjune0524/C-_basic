// 03-1

/*

// RacingCar.cpp

#include <iostream>

using namespace std;

#define ID_LEN      20
#define MAX_SPD      200
#define FUEL_STEP      2
#define ACC_STEP      10
#define BRK_STEP      10

struct Car
{
   char gamerID[ID_LEN];   // ������ ID
   int fuelGauge;         // ���ᷮ
   int curSpeed;         // ���� �ӵ�
};

void ShowCarState(const Car& car)
{
   cout << "������ ID : " << car.gamerID << endl;
   cout << "���ᷮ : " << car.fuelGauge << "%" << endl;
   cout << "����ӵ� : " << car.curSpeed << "km/s" << endl << endl;
}

void Accel(Car& car)
{
   if (car.fuelGauge <= 0)
   {
      return;
   }

   else
   {
      car.fuelGauge -= FUEL_STEP;
   }

   if (car.curSpeed + ACC_STEP >= MAX_SPD)
   {
      car.curSpeed = MAX_SPD;
      return;
   }

   car.curSpeed += ACC_STEP;
}

void Break(Car& car)
{
   if (car.curSpeed < BRK_STEP)
   {
      car.curSpeed = 0;
      return;
   }

   car.curSpeed -= BRK_STEP;
}

int main(void)
{
   Car run99 = { "run99" , 100, 0 };
   Accel(run99);
   Accel(run99);
   ShowCarState(run99);
   Break(run99);
   ShowCarState(run99);

   Car speed77 = { "speed77" ,100,0 };
   Accel(speed77);
   Break(speed77);
   ShowCarState(speed77);

   return 0;
}

*/

/*

// RacingCarFuncAdd.cpp

#include <iostream>

using namespace std;

#define ID_LEN      20
#define MAX_SPD      200
#define FUEL_STEP      2
#define ACC_STEP      10
#define BRK_STEP      10


struct Car
{
   char gamerID[ID_LEN];   // ������ ID
   int fuelGauge;         // ���ᷮ
   int curSpeed;         // ���� �ӵ�

   void ShowCarState()
   {
      cout << "������ ID : " << gamerID << endl;
      cout << "���ᷮ : " << fuelGauge << "%" << endl;
      cout << "����ӵ� : " << curSpeed << "km/s" << endl << endl;
   }

   void Accel()
   {
      if (fuelGauge <= 0)
      {
         return;
      }

      else
      {
         fuelGauge -= FUEL_STEP;
      }

      if (curSpeed + ACC_STEP >= MAX_SPD)
      {
         curSpeed = MAX_SPD;
         return;
      }

      curSpeed += ACC_STEP;
   }

   void Break()
   {
      if (curSpeed < BRK_STEP)
      {
         curSpeed = 0;
         return;
      }

      curSpeed -= BRK_STEP;
   }
};

int main(void)
{
   Car run99 = { "run99" , 100, 0 };
   run99.Accel();
   run99.Accel();
   run99.ShowCarState();
   run99.Break();
   run99.ShowCarState();

   Car speed77 = { "speed77" ,100,0 };
   speed77.Accel();
   speed77.Break();
   speed77.ShowCarState();

   return 0;
}

*/

/*

// ���� 03-1 [����ü ���� �Լ� �����ϱ�]

#include <iostream>

using namespace std;

struct Point
{
   int xpos;
   int ypos;

   void MovePos(int x, int y)
   {
      xpos += x;
      ypos += y;
   }

   void AddPoint(const Point& pos)
   {
      xpos += pos.xpos;
      ypos += pos.ypos;
   }

   void ShowPosition()
   {
      cout << "[" << xpos << ", " << ypos << "]" << endl;
   }

};

int main(void)
{
   Point pos1 = { 12,4 };
   Point pos2 = { 20,30 };

   pos1.MovePos(-7, 10);
   pos1.ShowPosition();      // [5, 14] ���

   pos1.AddPoint(pos2);
   pos1.ShowPosition();      // [25, 44] ���

   return 0;
}

*/

/*

//RacingCarEnum.cpp

#include <iostream>

using namespace std;

namespace CAR_CONST
{
   enum
   {
      ID_LEN      = 20,
      MAX_SPD      = 200,
      FUEL_STEP   = 2,
      ACC_STEP   = 10,
      BRK_STEP   = 10
   };
}

struct Car
{
   char gamerID[CAR_CONST::ID_LEN];   // ������ ID
   int fuelGauge;         // ���ᷮ
   int curSpeed;         // ���� �ӵ�

   void ShowCarState()
   {
      cout << "������ ID : " << gamerID << endl;
      cout << "���ᷮ : " << fuelGauge << "%" << endl;
      cout << "����ӵ� : " << curSpeed << "km/s" << endl << endl;
   }

   void Accel()
   {
      if (fuelGauge <= 0)
      {
         return;
      }

      else
      {
         fuelGauge -= CAR_CONST::FUEL_STEP;
      }

      if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
      {
         curSpeed = CAR_CONST::MAX_SPD;
         return;
      }

      curSpeed += CAR_CONST::ACC_STEP;
   }

   void Break()
   {
      if (curSpeed < CAR_CONST::BRK_STEP)
      {
         curSpeed = 0;
         return;
      }

      curSpeed -= CAR_CONST::BRK_STEP;
   }
};

int main(void)
{
   Car run99 = { "run99" , 100, 0 };
   run99.Accel();
   run99.Accel();
   run99.ShowCarState();
   run99.Break();
   run99.ShowCarState();

   Car speed77 = { "speed77" ,100,0 };
   speed77.Accel();
   speed77.Break();
   speed77.ShowCarState();

   return 0;
}

*/

/*

// RacingCarOuterFunc.cpp

#include <iostream>

using namespace std;

namespace CAR_CONST
{
   enum
   {
      ID_LEN = 20,
      MAX_SPD = 200,
      FUEL_STEP = 2,
      ACC_STEP = 10,
      BRK_STEP = 10
   };
}

struct Car
{
   char gamerID[CAR_CONST::ID_LEN];   // ������ ID
   int fuelGauge;         // ���ᷮ
   int curSpeed;         // ���� �ӵ�

   void ShowCarState();   // ���� ���� ���
   void Accel();         // ����, �ӵ� ����
   void Break();         // �극��ũ, �ӵ� ����
};

inline void Car::ShowCarState()
{
   cout << "������ ID : " << gamerID << endl;
   cout << "���ᷮ : " << fuelGauge << "%" << endl;
   cout << "����ӵ� : " << curSpeed << "km/s" << endl << endl;
}

inline void Car::Accel()
{
   if (fuelGauge <= 0)
   {
      return;
   }

   else
   {
      fuelGauge -= CAR_CONST::FUEL_STEP;
   }

   if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
   {
      curSpeed = CAR_CONST::MAX_SPD;
      return;
   }

   curSpeed += CAR_CONST::ACC_STEP;
}

inline void Car::Break()
{
   if (curSpeed < CAR_CONST::BRK_STEP)
   {
      curSpeed = 0;
      return;
   }

   curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
   Car run99 = { "run99" , 100, 0 };
   run99.Accel();
   run99.Accel();
   run99.ShowCarState();
   run99.Break();
   run99.ShowCarState();

   Car speed77 = { "speed77" ,100,0 };
   speed77.Accel();
   speed77.Break();
   speed77.ShowCarState();

   return 0;
}

*/

// 03-2

/*

// RacingCarClassBase.cpp

#include <iostream>
#include <cstring>

using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
        ACC_STEP = 10, BRK_STEP = 10
    };
}

class Car
{
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

public:
    void InitMembers(const char* ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

void Car::InitMembers(const char* ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "������ ID : " << gamerID << endl;
    cout << "���ᷮ : " << fuelGauge << "%" << endl;
    cout << "����ӵ� : " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel()
{
    if (fuelGauge <= 0)
    {
        return;
    }

    else
    {
        fuelGauge -= CAR_CONST::FUEL_STEP;
    }

    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }

    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }

    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car speed77;
    speed77.InitMembers("speed77", 100);
    speed77.Accel();
    speed77.Break();
    speed77.ShowCarState();

    return 0;
}

*/

/*

// RacingMain.cpp

#include "Car.h"

int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    Car speed77;
    speed77.InitMembers("speed77", 100);
    speed77.Accel();
    speed77.Break();
    speed77.ShowCarState();

    return 0;
}

*/

// ���� 03-2 [Ŭ������ ����]

/*

// ���� 1

#include <iostream>
#include "Cal.h"

using namespace std;

int main(void)
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();

    return 0;
}

*/

/*

// ���� 2

#include <iostream>
#include <cstring>

using namespace std;

class Printer
{
private:
    char print[30];

public:
    void SetString(const char* sent);
    void ShowString();
};

void Printer::SetString(const char* sent)
{
    strcpy(print, sent);
}

void Printer::ShowString()
{
    cout << print << endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();

    return 0;
}

*/

// 03-3

/*

// FruitSaleSim1.cpp

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
        numOfApples = num;      // ���� ��� ����
        myMoney = money;        // �Ǹ� ����
    }

    int SaleApples(int money)
    {
        int num = money / APPLE_PRICE;         // �Ǹ� ��� ����
        numOfApples -= num;
        myMoney += money;
        
        return num;
    }

    void ShowSalesResult()
    {
        cout << "���� ���: " << numOfApples << endl;
        cout << "�Ǹ� ����: " << myMoney << endl;
    }
};

class FruitBuyer
{
    int myMoney;            // private:
    int numOfApples;        // private:

public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller& seller, int money)
    {
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }

    void ShowBuyResult()
    {
        cout << "���� �ܾ�: " << myMoney << endl;
        cout << "��� ����: " << numOfApples << endl;
    }
};

int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);      // ������ ����!

    cout << "���� �Ǹ����� ��Ȳ" << endl;
    seller.ShowSalesResult();
    cout << "\n���� �������� ��Ȳ" << endl;
    buyer.ShowBuyResult();

    return 0;
}

*/