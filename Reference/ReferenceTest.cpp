#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int num1 = 3000;
    int &num2 = num1;

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    return 0;
}