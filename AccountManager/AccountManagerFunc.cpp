#include "AccountManager.h"

Account::Account(int id, string name, int balance)
{
    _id = id;
    _name = name;
    _balance = balance;
}

int Account::getId()
{
    return _id;
}

int Account::getBalance()
{
    return _balance;
}

void Account::setBalance(int balance)
{
    _balance = balance;
}

string Account::getName()
{
    return _name;
}

bool operator==(const Account &n1, const Account &n2)
{
    return n1._id == n2._id;
}

void AccountManager::Start()
{
    int choice;

    while (true)
    {
        ShowMenu();
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE_ACCOUNT:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithDrawMoney();
            break;
        case INQUIRE:
            ShowAllAccountInfo();
            break;
        case EXIT:
            return;
        default:
            cout << "잘못된 선택입니다." << endl
                 << endl;
        }
    }
}

void AccountManager::ShowMenu()
{
    cout << "----- Menu -----" << endl;
    cout << "1. 계좌 개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌 정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: ";
}

bool AccountManager::MakeAccount()
{
    int id;
    string name;
    int balance;

    cout << "[계좌 개설]" << endl;
    cout << "계좌 ID: ";
    cin >> id;
    cout << "이름: ";
    cin >> name;
    cout << "잔액: ";
    cin >> balance;
    if (SearchAccount(id))
    {
        cout << "[!] 동일한 ID가 존재합니다." << endl
             << endl;
        return false;
    }

    accounts.push_back(new Account(id, name, balance));
    cout << "[v] 계좌 개설이 완료되었습니다." << endl
         << endl;
    return true;
}

bool AccountManager::DepositMoney()
{
    int id;
    int money;

    cout << "[입금]" << endl;
    cout << "계좌 ID: ";
    cin >> id;
    cout << "입금액: ";
    cin >> money;

    Account *account = SearchAccount(id);

    if (!account)
    {
        cout << "[!] 계좌 ID가 없습니다." << endl
             << endl;
        return false;
    }

    account->setBalance(account->getBalance() + money);
    cout << "[v] 입금이 완료되었습니다." << endl
         << endl;
    return true;
}

bool AccountManager::WithDrawMoney()
{
    int id;
    int money;

    cout << "[출금]" << endl;
    cout << "계좌 ID: ";
    cin >> id;
    cout << "출금액: ";
    cin >> money;

    Account *account = SearchAccount(id);

    if (!account)
    {
        cout << "[!] 계좌 ID가 없습니다." << endl
             << endl;
        return false;
    }

    if ((account->getBalance() - money) < 0)
    {
        cout << "[!] 잔액이 부족합니다." << endl
             << endl;
        return false;
    }
    account->setBalance(account->getBalance() - money);
    cout << "[v] 출금이 완료되었습니다." << endl
         << endl;
    return true;
}

void AccountManager::ShowAllAccountInfo()
{
    for (Account *account : accounts)
    {
        cout << "계좌 ID: " << account->getId() << endl;
        cout << "이름: " << account->getName() << endl;
        cout << "잔액: " << account->getBalance() << endl
             << endl;
    }
}

Account *AccountManager::SearchAccount(int id)
{
    for (Account *account : accounts)
    {
        if (account->getId() == id)
        {
            return account;
        }
    }

    return NULL;
}