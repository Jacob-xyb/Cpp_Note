#include <iostream>

using namespace std;

class Person
{
public:
    string name = "jx";
    int age = 28;
    int id = 74;
};

int main(int argc, char const *argv[])
{
    Person p;

    cout << p.name << " " << p.age << " " << p.id << endl;

    return 0;
}
