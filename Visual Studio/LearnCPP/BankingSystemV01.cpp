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
		cout << "선택 : ";
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
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
	}
}

void showMenu() {
	cout << "----------Menu----------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	return;
}

void makeAccount() {
	int accID;
	char cusName[20];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌 ID : ";
	cin >> accID;
	cout << "이름 : ";
	cin >> cusName;
	cout << "입금액 : ";
	cin >> balance;

	for (int i = 0; i < ACC_MAX; i++) {
		if (accArray[i].accID == accID) {
			cout << "이미 존재하는 계좌입니다." << endl << endl;
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

	cout << "[입    금]" << endl;
	cout << "계좌 ID : ";
	cin >> accID;
	cout << "입금액 : ";
	cin >> money;

	for (int i = 0; i < ACC_MAX; i++) {
		if (accArray[i].accID == accID) {
			accArray[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "입금실패 : 계좌가 존재하지 않습니다." << endl << endl;
	return;
}

void withdrawMoney() {
	int accID;
	int money;

	cout << "[출    금]" << endl;
	cout << "계좌 ID : ";
	cin >> accID;
	cout << "출금액 : ";
	cin >> money;

	for (int i = 0; i < ACC_MAX; i++) {
		if (accArray[i].accID == accID) {
			if (accArray[i].balance < money) {
				cout << "출금실패 : 잔액이 부족합니다." << endl << endl;
			}
			else {
				accArray[i].balance -= money;
				cout << "출금완료" << endl;
				cout << "잔액은 " << accArray[i].balance << "원 입니다." << endl << endl;
			}
			return;
		}
	}
	cout << "출금실패 : 계좌가 존재하지 않습니다." << endl << endl;
	return;
}

void showAllAccInfo() {
	for (int i = 0; i < accCounter; i++) {
		cout << "계좌ID : " << accArray[i].accID << endl;
		cout << "이 름 : " << accArray[i].cusName << endl;
		cout << "잔 액 : " << accArray[i].balance << endl << endl;
	}
}