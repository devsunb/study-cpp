#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // char str[100] = "abcd";
    // cout << str << endl;
    // cout << strlen(str) << endl;

    // strcat(str, "efgh");
    // cout << str << endl;

    // char *str2 = new char[100];
    // strcpy(str2, str);
    // cout << str << endl;

    // cout << "strcmp: ";
    // cout << strcmp(str, str2) << endl;

    int randnum[5];

    for (int i = 0; i < sizeof(randnum) / sizeof(*randnum); i++)
    {
        randnum[i] = rand() % 100;
        cout << randnum[i] << endl;
    }

    return 0;
}