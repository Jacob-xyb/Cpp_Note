#include "../第三方库测试.h"
using namespace Eigen;

//MatrixXd
//	初识一下Eigen矩阵
void Eigen_introduction_Jx001()
{
	MatrixXd m(2, 2);	// MatrixXd 表示的是动态数组，初始化的时候指定数组的行数和列数
	cout << m << endl;	// eigen重载了<<运算符，可以直接输出eigen矩阵的值
	m(0, 0) = 1;
	m(0, 1) = 2;
	m(1, 0) = 3;
	m(1, 1) = m(0, 0) + m(1, 0);
	cout << m << endl;
}
void Eigen_introduction_Jx002()
{
	//初始化动态矩阵m,使用Random函数,初始化的值在[-1,1]区间内,矩阵大小3X3
	MatrixXd m = MatrixXd::Random(3, 3);
	cout << m << endl;
	m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;   // MatrixXd::Constant(3, 3, 1.2)初始化3X3矩阵,矩阵里面的数值为常量,全部为1.2
	// Eigen重载了+ 运算符，两个矩阵有相同的行数和列数即可相加,对应位置上的值相加
	cout << "m =" << endl << m << endl;
	VectorXd v(3);
	v << 1, 2, 3;                                   //逗号初始化，英文：comma-initializer,Eigen未提供c++11 的{}初始化方式
	cout << "m * v =" << endl << m * v << endl;
}