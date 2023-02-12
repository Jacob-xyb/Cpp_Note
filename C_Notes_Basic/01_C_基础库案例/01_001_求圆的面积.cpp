#include "01_C_基础库案例.h"

// 已知条件： 半径r
// 算法： 面积 S = π*r*r

// 解析步骤：
// ++ r 通过 键盘输入
// ++ 定义一个面积变量 area = pai * r * r

#define PI 3.14

void Case_Calculate_Area_of_Circle() {

	float r = 0.0f;
	float s = 0.0f;		// 圆的面积

	printf("请输入圆的半径r：");
	scanf("%f", &r);

	s = PI * r * r;

	printf("半径为：%f, 面积为：%.2f 的圆", r, s);
}
