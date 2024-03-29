#include <stdio.h>
#include <string.h> // 提供strlen()函数的原型

#define DENSITY 62.4 // 人体密度(单位:磅/立方英尺)
void Example_CPrimerPlus_41(void);

int main(int argc, char const *argv[])
{
    Example_CPrimerPlus_41();
    return 0;
}

void Example_CPrimerPlus_41()
{
    float weight, volume;
    int size, letters;
    char name[40];

    printf("Hi! What's your first name?\n");
    scanf("%s", name);
    printf("%s, what's your weight in pounds?\n", name);
    scanf("%f", &weight);

    size = sizeof name;
    letters = strlen(name);
    volume = weight / DENSITY;

    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
    printf("Also, your first name has %d letters,\n", letters);
    printf("and we have %d bytes to store it.\n", size);

    return;
}