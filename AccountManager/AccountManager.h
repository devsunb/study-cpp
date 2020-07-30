#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <iostream>
#include <clocale>
#include <string>
#include <vector>

// using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::string;
using std::vector;

class Account
{
public:
  Account(int id, string name, int balance);
  void setBalance(int balance);
  int getBalance();
  int getId();
  string getName();
  friend bool operator==(const Account &n1, const Account &n2);

private:
  int _id;
  string _name;
  int _balance;
};

class AccountManager
{
public:
  void Start();
  void ShowMenu();
  bool MakeAccount();
  bool DepositMoney();
  bool WithDrawMoney();
  void ShowAllAccountInfo();
  Account *SearchAccount(int id);

private:
  vector<Account *> accounts;
  enum
  {
    MAKE_ACCOUNT = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
  };
};

#endif