#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int NAME_LEN = 20;
const int ACC_MAX = 100;

void showMenu();
void makeAccount();
void depositMoney();
void withdrawMoney();
void showAllAccInfo();

typedef struct {
	int accID;
	int balance;
	char cusName[NAME_LEN];
} Account;

Account accArray[ACC_MAX];
int accCounter = 0;

int main() {
	int choice = 0;
	while (true) {
		showMenu();
		cout << "���� : ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			makeAccount();
			break;
		case 2:
			depositMoney();
			break;
		case 3:
			withdrawMoney();
			break;
		case 4:
			showAllAccInfo();
			break;
		case 5:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
	}
}

void showMenu() {
	cout << "----------Menu----------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	return;
}

void makeAccount() {
	int accID;
	char cusName[20];
	int balance;

	cout << "[���°���]" << endl;
	cout << "���� ID : ";
	cin >> accID;
	cout << "�̸� : ";
	cin >> cusName;
	cout << "�Աݾ� : ";
	cin >> balance;

	for (int i = 0; i < ACC_MAX; i++) {
		if (accArray[i].accID == accID) {
			cout << "�̹� �����ϴ� �����Դϴ�." << endl << endl;
			return;
		}
	}

	cout << endl;
	accArray[accCounter].accID = accID;
	strcpy(accArray[accCounter].cusName, cusName);
	accArray[accCounter].balance = balance;
	accCounter++;
	return;
}

void depositMoney() {
	int accID;
	int money;

	cout << "[��    ��]" << endl;
	cout << "���� ID : ";
	cin >> accID;
	cout << "�Աݾ� : ";
	cin >> money;

	for (int i = 0; i < ACC_MAX; i++) {
		if (accArray[i].accID == accID) {
			accArray[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "�Աݽ��� : ���°� �������� �ʽ��ϴ�." << endl << endl;
	return;
}

void withdrawMoney() {
	int accID;
	int money;

	cout << "[��    ��]" << endl;
	cout << "���� ID : ";
	cin >> accID;
	cout << "��ݾ� : ";
	cin >> money;

	for (int i = 0; i < ACC_MAX; i++) {
		if (accArray[i].accID == accID) {
			if (accArray[i].balance < money) {
				cout << "��ݽ��� : �ܾ��� �����մϴ�." << endl << endl;
			}
			else {
				accArray[i].balance -= money;
				cout << "��ݿϷ�" << endl;
				cout << "�ܾ��� " << accArray[i].balance << "�� �Դϴ�." << endl << endl;
			}
			return;
		}
	}
	cout << "��ݽ��� : ���°� �������� �ʽ��ϴ�." << endl << endl;
	return;
}

void showAllAccInfo() {
	for (int i = 0; i < accCounter; i++) {
		cout << "����ID : " << accArray[i].accID << endl;
		cout << "�� �� : " << accArray[i].cusName << endl;
		cout << "�� �� : " << accArray[i].balance << endl << endl;
	}
}