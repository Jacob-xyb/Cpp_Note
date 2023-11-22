#include <stdio.h>
#include <string.h>  //提供strlen函数原型

#define PRAISE "You are an extraordinary being."

void Example_CPrimerPlus_43();

int main(int argc, char const *argv[])
{
    Example_CPrimerPlus_43();
    return 0;
}

void Example_CPrimerPlus_43()
{
    char name[40];
    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %zd letters occupies %zd memory cells,\n", strlen(name), sizeof name);
    printf("The phrase of praise has zd letters ", strlen(PRAISE));
    printf("and occupies %zd memory cells,\n", sizeof PRAISE);
}
