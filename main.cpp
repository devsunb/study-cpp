#include <iostream>
#include <string.h>
#include <ctime>
#include <sys/time.h>

int main(void)
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    std::cout << (now->tm_year + 1900) << '-'
              << (now->tm_mon + 1) << '-'
              << now->tm_mday << ' '
              << now->tm_hour << ':'
              << now->tm_min << ':'
              << now->tm_sec
              << std::endl
              << std::endl;

    std::string a = "aa";
}
