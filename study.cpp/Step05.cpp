// 05-1

/*

// ClassInit.cpp

#include <iostream>

using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;

public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{
		// empty
	}

	SoSimple(const SoSimple& copy)
		: num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1;		// SoSimple sim2(sim1); 으로 변환 가능!
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();

	return 0;
}

*/

// 05-2

/*

// ShallowCopyError.cpp

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

	Person(const Person &copy)
		: age(copy.age)
	{
		int len = strlen(copy.name) + 1;
		name = new char[len];
		strcpy(name, copy.name);
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
	Person man2 = man1;					// class에서 별도의 복사 생성자가 정의되지 않았으므로, 디폴트 복사 생성자에 의한 맴버 대 맴버의 복사가 진행된다.
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}

*/

/*

// 문제 05-1 [복사 생성자의 정의]

#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int position)
	{
		switch (position)
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
	char* company;
	char* phone_num;
	int position;

public:
	NameCard(const char* NAME, const char* COMPANY, const char* PHONE_NUM, int POSITION)
		: position(POSITION)
	{
		name = new char[strlen(NAME) + 1];
		strcpy(name, NAME);

		company = new char[strlen(COMPANY) + 1];
		strcpy(company, COMPANY);

		phone_num = new char[strlen(PHONE_NUM) + 1];
		strcpy(phone_num, PHONE_NUM);
	}

	NameCard(const NameCard& copy)
		: position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);

		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);

		phone_num = new char[strlen(copy.phone_num) + 1];
		strcpy(phone_num, copy.phone_num);
	}

	void ShowNameCardInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone_num << endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(position); cout << endl;
	}

	~NameCard()
	{
		delete[]name;
		delete[]company;
		delete[]phone_num;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}

*/

// 05-3

/*

// PassObjCopycon.cpp

#include <iostream>

using namespace std;

class SoSimple
{
private:
	int num;

public:
	SoSimple(int n)
		: num(n)
	{
		// empty
	}

	SoSimple(const SoSimple& copy)
		: num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}

	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob)
{
	ob.ShowData();
}

int main(void)
{
	SoSimple obj(7);
	cout << "함수호출 전" << endl;
	SimpleFuncObj(obj);
	cout << "함수호출 후" << endl;

	return 0;
}

*/

/*

// ReturnObjCopycon.cpp

#include <iostream>

using namespace std;

class SoSimple
{
private:
	int num;

public:
	SoSimple(int n)
		: num(n)
	{
		// empty
	}

	SoSimple(const SoSimple& copy)
		: num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}

	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}

	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "return 이전" << endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();
	obj.ShowData();

	return 0;
}

*/

/*

// IKnowTempObj.cpp

#include <iostream>

using namespace std;

class Temporary
{
private:
	int num;

public:
	Temporary(int n)
		: num(n)
	{
		cout << "create obj: " << num << endl;
	}
	
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);
	cout << "********** end of main!" << endl << endl;
	
	return 0;
}

*/

// ReturnObjDeadTime.cpp

