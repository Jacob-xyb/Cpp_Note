/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2024-06-24 15:01:02
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2024-10-09 16:25:56
 * @Description: Life is struggle.
 */

#include <stdio.h>

void RunCaseByIndex(int index);

int main()
{
    int index = 0;
    printf("请输入测试用例编号: ");
    scanf("%d", &index);
    RunCaseByIndex(index);
    return 0;
}

/*
题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
程序分析：可填在百位、十位、个位的数字都是 1、2、3、4，组成所有的排列后再去掉不满足条件的排列。
*/
void Case1_Different3Digits()
{
    int i, j, k;
    int count = 0;
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            if (j == i)
                continue; // 同一位数不用考虑
            for (k = 1; k <= 4; k++)
            {
                if (k == i || k == j)
                    continue; // 与前两位数重复的数不用考虑
                printf("%d%d%d\n", i, j, k);
                count++;
            }
        }
    }
    printf("Total count: %d\n", count);
}

/*
题目：企业发放的奖金根据利润提成。
利润(I)低于或等于10万元时，奖金可提10%；
利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
20万到40万之间时，高于20万元的部分，可提成5%；
40万到60万之间时高于40万元的部分，可提成3%；
60万到100万之间时，高于60万元的部分，可提成1.5%；
高于100万元时，超过100万元的部分按1%提成。
从键盘输入当月利润I，求应发放奖金总数？
程序分析：请利用数轴来分界，定位。注意定义时需把奖金定义成双精度浮点(double)型。
*/
void Case2_CalculateBonus()
{
    // 120000 bonus: 11500
    // 2e6 bonus: 49500
    int methodIndex = 1;

    double I;
    double bonus = 0.0;
    printf("请输入当月利润I: ");
    scanf("%lf", &I);

    if (methodIndex == 0) // 初学者无限嵌套
    {
        if (I > 1e5)
        {
            bonus += 1e5 * 0.1;
            if (I > 2e5)
            {
                bonus += (2e5 - 1e5) * 0.075;
                if (I > 4e5)
                {
                    bonus += (4e5 - 2e5) * 0.05;
                    if (I > 6e5)
                    {
                        bonus += (6e5 - 4e5) * 0.03;
                        if (I > 1e6)
                        {
                            bonus += (1e6 - 6e5) * 0.015;
                            bonus += (I - 1e6) * 0.01;
                        }
                        else
                        {
                            bonus += (I - 6e5) * 0.015;
                        }
                    }
                    else
                    {
                        bonus += (I - 4e5) * 0.03;
                    }
                }
                else
                {
                    bonus += (I - 2e5) * 0.05;
                }
            }
            else
            {
                bonus += (I - 1e5) * 0.075;
            }
        }
        else
        {
            bonus += I * 0.1;
        }
    }
    else if (methodIndex == 1) // 利用数轴
    {
        double bonusBoundary[] = {0, 1e5, 2e5, 4e5, 6e5, 1e6, 1e7};
        double bonusRate[] = {0, 0.1, 0.075, 0.05, 0.03, 0.015, 0.01};
        for (int i = 1; i < 7; i++)
        {
            if (I <= bonusBoundary[i])
            {
                bonus += (I - bonusBoundary[i - 1]) * bonusRate[i];
                break;
            }
            else
            {
                bonus += (bonusBoundary[i] - bonusBoundary[i - 1]) * bonusRate[i];
            }
        }
    }
    printf("Bonus: %lf\n", bonus);
}

void RunCaseByIndex(int index)
{
    switch (index)
    {
    case 1:
        Case1_Different3Digits();
        break;
    case 2:
        Case2_CalculateBonus();
        break;
    default:
        printf("Invalid case index.\n");
        break;
    }
}