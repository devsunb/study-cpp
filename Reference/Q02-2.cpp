#include <iostream>

int main()
{
    const int &num = 12;

    const int *ptr = &num;

    const int *(&pref) = ptr;

    std::cout << *pref << std::endl;

    return 0;
}