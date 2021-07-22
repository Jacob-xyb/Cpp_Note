/*
案例：结构体案例 
说明：学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下：
    设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
    学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
    最终打印出老师数据以及老师所带学生数据。
*/

#include <iostream>
using namespace std;

struct Student
{
    string sName;        // 学生姓名
    int score;      // 考试分数
};

struct Teacher
{
    string tName;        // 老师姓名
    struct Student stuArr[5];
};

// 创建赋值函数
void allocateSpace(struct Teacher tcArr[], int len)
{
    string nameSeed = "ABCDE";
    int stuLen = sizeof(tcArr[0].stuArr)/sizeof(tcArr[0].stuArr[0]);
    // 给老师赋值
    for (int i = 0; i < len; i++)
    {
        tcArr[i].tName = "Teacher_" + nameSeed[i];

        // 每个老师带5个学生
        for (int j = 0; j < stuLen; j++)
        {
            tcArr[i].stuArr[j].sName = "Student_" + nameSeed[j];
            tcArr[i].stuArr[j].score = 60;
        }
        
    }
    
}

void printInfo(struct Teacher tcArr[],int len)
{
    int stuLen = sizeof(tcArr[0].stuArr)/sizeof(tcArr[0].stuArr[0]);
    for (int i = 0; i < len; i++)
    {
        cout << tcArr[i].tName << "带领的三名学生姓名和成绩分别为:\n\t";

        for (int j = 0; j < stuLen; j++)
        {
            cout << tcArr[i].stuArr[j].sName << ":" 
                 << tcArr[i].stuArr[j].score << "\t";
        }

        cout << endl;
    }
    
}

int main()
{
    // 创建存放3名老师的数组
    struct Teacher tcArr[3];

    // 通过函数给3名老师赋值
    int len = sizeof(tcArr)/sizeof(tcArr[0]);
    allocateSpace(tcArr,len);

    printInfo(tcArr,len);

    cout << tcArr[0].tName;
    
    return 0;
}
