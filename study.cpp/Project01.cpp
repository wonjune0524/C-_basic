/*

// BankingSystemVer01.cpp

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;	// ������ ����

void ShowMenu(void);		// �޴����
void MakeAccount(void);		// ���°����� ���� �Լ�
void DepositMoney(void);	// �� ��
void WithdrawMoney(void);	// �� ��
void ShowAllAccInfo(void);	// �ܾ���ȸ

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};	// MAKE���� EXIT���� 1~5 ����.

typedef struct
{
	int accID;					// ���¹�ȣ
	int balance;				// �� ��
	char cusName[NAME_LEN];		// ���̸�
} Account;

Account accArr[100];			// Account ������ ���� �迭
int accNum = 0;					// ����� Account ��

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "����: ";
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount(void)
{
	int id;
	int balance;
	char name[NAME_LEN];
	
	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "�� ��: "; cin >> name;
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

	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void WithdrawMoney(void)
{
	int id;
	int money;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			if (accArr[i].balance < money)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "����ID: " << accArr[i].accID << endl;
		cout << "�� ��: " << accArr[i].balance << endl;
		cout << "�� ��: " << accArr[i].cusName << endl << endl;
	}
}

*/