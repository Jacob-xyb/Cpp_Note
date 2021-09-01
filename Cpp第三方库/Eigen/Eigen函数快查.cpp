#include "../第三方库测试.h"

template<typename T>
using Mat2 = Matrix<T, 2, 2>;

//template + using 自定义数据类型
void Eigen_bilibili_001()
{
	Mat2<int> m1;
	m1 << 1, 1,
		1, 1;
	cout << "m1:" << endl <<m1 << endl;
	//感觉有点花里胡哨..
	Matrix<int, 2, 2> m2(m1);
	cout << "m2:" << endl << m2 << endl;
}
//Eigen常用函数
void Eigen_bilibili_002()
{
	//常用构建
	MatrixXd m1 = MatrixXd::Zero(2, 2);
	MatrixXd m2 = MatrixXd::Ones(2, 2);
	MatrixXd m3 = MatrixXd::Identity(2, 2);
	MatrixXd m4 = MatrixXd::Random(2, 2);
	RowVectorXd v1 = RowVectorXd::LinSpaced(4,1,4);	//（size,low,high）
	cout << "线性向量： " << v1 << endl;
	//常用操作
	m1.setOnes();
	cout << "矩阵设为1" << endl << m1 << endl;
	m1.setZero();
	cout << "矩阵设为0" << endl << m1 << endl;
	m1.setRandom();
	cout << "矩阵随机" << endl << m1 << endl;
	m1.setConstant(6);
	cout << "矩阵设为确认常数" << endl << m1 << endl;
	m1.setIdentity();
	cout << "矩阵设为对角矩阵" << endl << m1 << endl;
	//m1.setLinSpaced(4,1,4);	//只能用于向量

	/*少见*/
	//setUnit(index i)	//vector(i) = 1，其余均为0
	v1.setUnit(1);
	cout << "向量重置" << endl << v1 << endl;
	//setUnit(new size num, index i)	//vector.size() = num ; vector(i) = 1，其余均为0
	v1.setUnit(3,1);
	cout << "矩阵设为对角单位矩阵" << endl << v1 << endl;


}
//Eigen常用特殊矩阵
void Eigen_bilibili_003()
{
	MatrixXd m1 = MatrixXd::Random(2, 2);
	cout << "原矩阵"   << endl << m1 << endl;
	cout << "转置矩阵" << endl << m1.transpose() << endl;
	cout << "共轭矩阵" << endl << m1.conjugate() << endl;
	cout << "逆矩阵"   << endl << m1.inverse() << endl;
	cout << "伴随矩阵" << endl << m1.adjoint() << endl;
}
//Vector块操作
void Eigen_bilibili_004()
{
	VectorXd v(9);
	v << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	cout << "原向量： " << v.transpose() << endl;
	cout << "前三个： " << v.head(3).transpose() << endl;
	cout << "后三个： " << v.tail(3).transpose() << endl;
	cout << "中间三个：" << v.segment(3, 3).transpose() << endl;
}
//Matrix块操作
void Eigen_bilibili_005()
{
	MatrixXd m(4, 4);
	m << 1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16;
	cout << "原矩阵" << endl << m << endl;
	cout << "第一列" << endl << m.col(0) << endl;
	cout << "第一行" << endl << m.row(0) << endl;
	/*block四个参数*/
	//前两个参数是起始元素的行列标签
	//后两个参数是取多少行多少列
	cout << "子矩阵" << endl << m.block(0,1,3,2) << endl;
	//block<3, 2>(0, 1) 则是相反，<>内是矩阵尺寸，()内是起始位置
	cout << "子矩阵" << endl << m.block<3, 2>(0, 1) << endl;
}

