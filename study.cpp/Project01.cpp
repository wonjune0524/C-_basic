/*

// BankingSystemVer01.cpp

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;	// 정수값 고정

void ShowMenu(void);		// 메뉴출력
void MakeAccount(void);		// 계좌개설을 위한 함수
void DepositMoney(void);	// 입 금
void WithdrawMoney(void);	// 출 금
void ShowAllAccInfo(void);	// 잔액조회

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};	// MAKE부터 EXIT까지 1~5 저장.

typedef struct
{
	int accID;					// 계좌번호
	int balance;				// 잔 액
	char cusName[NAME_LEN];		// 고객이름
} Account;

Account accArr[100];			// Account 저장을 위한 배열
int accNum = 0;					// 저장된 Account 수

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id;
	int balance;
	char name[NAME_LEN];
	
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> balance;
	cout << "이 름: "; cin >> name;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void)
{
	int id;
	int money;

	cout << "[입 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithdrawMoney(void)
{
	int id;
	int money;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balance < money)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "잔 액: " << accArr[i].balance << endl;
		cout << "이 름: " << accArr[i].cusName << endl << endl;
	}
}

*/