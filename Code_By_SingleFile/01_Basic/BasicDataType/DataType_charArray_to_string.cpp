#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    char cstr[] = "test.txt";

    string sstr = cstr;

    int index = sstr.find_last_of('.');

    cout << sstr.substr(0, index) + std::to_string(1) + ".txt";

    sstr.c_str();

    return 0;
}
