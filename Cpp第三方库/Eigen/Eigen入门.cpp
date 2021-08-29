#include "../第三方库测试.h"
using namespace Eigen;

//MatrixXd
//	初识Eigen矩阵
void Eigen_introduction_started_001()
{
	MatrixXd m(2, 2);	// MatrixXd 表示的是动态数组，初始化的时候指定数组的行数和列数
	cout << m << endl;	// eigen重载了<<运算符，可以直接输出eigen矩阵的值
	m(0, 0) = 3;
	m(1, 0) = 2.5;
	m(0, 1) = -1;
	m(1, 1) = m(1, 0) + m(0, 1);
	std::cout << m << std::endl;
}
// Matrices and vectors:Eg001
void Eigen_introduction_started_002()
{
	//初始化动态矩阵m,使用Random函数,初始化的值在[-1,1]区间内,矩阵大小3X3
	MatrixXd m = MatrixXd::Random(3, 3);
	cout << m << endl;
	//MatrixXd::Constant(3, 3, 1.2)初始化3X3矩阵,矩阵里面的数值为常量,全部为1.2
	//	Eigen重载了 + 运算符，两个矩阵有相同的行数和列数即可相加,对应位置上的值相加
	m = (m + MatrixXd::Constant(3, 3, 1.2));  
	//矩阵 乘 常数
	m *= 100;
	cout << "m =" << endl << m << endl;

	//定义一个向量 v len = 3；
	VectorXd v(3);	//只是定义了尺寸
	//	和 STL 不同，没有初始化，而是未初始化内存空间，可以访问
	cout << v[0] << endl;
	//逗号初始化，英文：comma-initializer,Eigen未提供c++11 的{}初始化方式
	v << 1, 2, 3;
	//	eigen重载了<<运算符，可以直接输出Eigen向量的值
	//		并且Eigen的一维向量默认为列向量
	cout << "v = " << endl << v << endl;
	//矩阵与向量的乘法
	cout << "m * v =" << endl << m * v << endl;
}
// Matrices and vectors:Eg002
void Eigen_introduction_started_003()
{
	//MatrixXd m = MatrixXd::Random(3, 3);
	//m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;
	//cout << "m =" << endl << m << endl;
	//VectorXd v(3);
	//v << 1, 2, 3;
	//cout << "m * v =" << endl << m * v << endl;

	//一下代码实现的功能与上述完全一致
	//但是实现方式略有不同，相比上一个例子，以下代码更多的采用了方阵实现
	Matrix3d m = Matrix3d::Random();
	m = (m + Matrix3d::Constant(1.2)) * 50;
	cout << "m =" << endl << m << endl;
	Vector3d v(1, 2, 3);
	cout << "m * v =" << endl << m * v << endl;
}

//comma-initializer
//	尺度一定要一致
void Eigen_introduction_Jx003()
{
	RowVectorXd vec1(3);
	vec1 << 1, 2, 3;
	std::cout << "vec1 = " << vec1 << std::endl;

	RowVectorXd vec2(4);
	vec2 << 1, 4, 9, 16;
	std::cout << "vec2 = " << vec2 << std::endl;

	RowVectorXd joined(7);
	joined << vec1, vec2;	//同类型向量可以这样合并
	std::cout << "joined = " << joined << std::endl;
}
//	常用的初始化方法
void Eigen_introduction_Jx004()
{
	//随机初始化初始化的值在[-1,1]区间内,矩阵大小3X3
	MatrixXd m0 = MatrixXd::Random(3, 3);    
	//常量值初始化,矩阵里面的值全部为2.4 ,三个参数分别代表：行数，列数，常量值
	MatrixXd m1 = MatrixXd::Constant(3, 3, 2.4);
	Matrix2d m2 = Matrix2d::Zero(); 				//零初始化.矩阵里面的值全部为0
	Matrix3d m3 = Matrix3d::Ones();                 //矩阵里面的值全部初始化为1
	Matrix4d m4 = Matrix4d::Identity();             //初始化为单位矩阵
	Matrix3d m5;                                    //逗号初始化
	m5 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	cout << "m0 =" << endl << m0 << endl;
	cout << "m1 =" << endl << m1 << endl;
	cout << "m2 =" << endl << m2 << endl;
	cout << "m3 =" << endl << m3 << endl;
	cout << "m4 =" << endl << m4 << endl;
	cout << "m5 =" << endl << m5 << endl;

	MatrixXf mat = MatrixXf::Ones(2, 3);
	std::cout << "before: " << endl << mat << std::endl << std::endl;
	//此处使用了临时变量，然后使用逗号初始化，在此必须使用finish（）方法来获取实际的矩阵对象。
	mat = (MatrixXf(2, 2) << 0, 1, 2, 0).finished() * mat;    
	std::cout << "after: " << endl << mat << std::endl;
}
//	MatrixXd中的X
void Eigen_introduction_MatrixXd_001()
{
	//Xd可以被Xd定义
	MatrixXd m0 = MatrixXd::Random(3, 3);
	//Xd可以被方阵定义
	MatrixXd m1 = Matrix2d::Zero();
	cout << "m1 = " << endl << m1 << endl;
	//意思就是Xd可以很随意的被定义

	//方阵可以被同尺寸的Xd定义
	Matrix2d m2 = MatrixXd::Ones(2, 2);
	cout << "m2 = " << endl << m2 << endl;
}
//	获取行列尺寸
void Eigen_introduction_MatrixXd_002()
{ 
	MatrixXd m = Matrix2d::Ones();
	cout << m << endl;
	m.resize(4, 3);
	std::cout << "The matrix m is of size "
		<< m.rows() << "x" << m.cols() << std::endl;
	std::cout << "It has " << m.size() << " coefficients" << std::endl;
	VectorXd v(2);
	v.resize(5);
	std::cout << "The vector v is of size " << v.size() << std::endl;
	std::cout << "As a matrix, v is of size "
		<< v.rows() << "x" << v.cols() << std::endl;
}

//The Matrix class
//	Storage orders
void Eigen_introduction_Storage_orders_001()
{
	Matrix<int, 3, 4, ColMajor> Acolmajor;
	Acolmajor << 8, 2, 2, 9,
				 9, 1, 4, 4,
				 3, 5, 4, 5;
	cout << "The matrix A:" << endl;
	cout << Acolmajor << endl << endl;

	cout << "In memory (column-major):" << endl;
	for (int i = 0; i < Acolmajor.size(); i++)
	  cout << *(Acolmajor.data() + i) << "  ";
	cout << endl << endl;

	Matrix<int, 3, 4, RowMajor> Arowmajor = Acolmajor;
	cout << "In memory (row-major):" << endl;
	for (int i = 0; i < Arowmajor.size(); i++)
	  cout << *(Arowmajor.data() + i) << "  ";
	cout << endl << endl;
}
//	简单测试
void Eigen_introduction_MatrixClass_001()
{
	//Matrix的三个必需模板参数
	//	Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
	Matrix <double, 3, 2> m1;	//默认是列优先存储
	cout << m1 << endl;
	Array33f arr(2);	//只提供了Array33f ；>10的并没有提供，所以不会产生混淆
	cout << arr << endl;
	//why arr(2)可以进行赋值？
	//	但是 ArrayXf ()里面只能输入一个参数确定X的值
	//ArrayXf arr1(4)(2);	//error
	//ArrayXf arr1(4,2);	//error
	ArrayXf arr1(4);
	cout << arr1 << endl;
	//换个思路可以初始化	//熟用Constant函数
	ArrayXf arr2 = ArrayXXf::Constant(4,1,2);
	cout << arr2 << endl;
}
//	Constructors
void Eigen_MatrixClass_Constructors_001()
{
	//If C++11 is enabled, fixed-size column or row vectors of arbitrary size can be initialized by passing an arbitrary number of coefficients:
	Matrix<int, 5, 1> v1{ 1, 2, 3, 4, 5 };	//double '{}' is also ok.
	cout << v1 << endl;

	//In the general case of matrices and vectors with either fixed or runtime sizes, coefficients have to be grouped by rows and passed as an initializer list of initializer list
	//Matrix<int, 2, 3> m1{ 1, 2, 3, 4, 5, 6 };	//error!
	Matrix<int, 2, 3> m1{ {1, 2, 3}, {4, 5, 6} };	//yes!
	cout << m1 << endl;

	//For column or row vectors, implicit transposition is allowed. This means that a column vector can be initialized from a single row:
	//	Because of implicit transposition, so must be initialized by double '{}'
	VectorXd v2{ {1.5, 2.5, 3.5} };             // A column-vector with 3 coefficients
	cout << "implicit transposition:" << endl <<  v2 << endl;	//unbelievable
	RowVectorXd v2t{ {1.5, 2.5, 3.5} };
	cout << "implicit transposition:" << endl << v2t << endl;
	//	回看模板原型，也会隐式转置，甚至兼容单双括号！！！
	Matrix<int, 1, 5> v3t { 1, 2, 3, 4, 5 } ;
	cout << "Constructors" << endl << v3t << endl;
}


//The Array class
//	Array定义及四则运算
void Eigen_introduction_ArrayClass_001()
{
	ArrayXXf a(3, 3);
	ArrayXXf b(3, 3);
	a << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;
	b << 1, 2, 3,
		1, 2, 3,
		1, 2, 3;
	cout << "a + b = " << endl << a + b << endl;
	cout << "a - 2 = " << endl << a - 2 << endl;
	cout << "a * b = " << endl << a * b << endl;
	cout << "a / b = " << endl << a / b << endl;
}
//	Array其他函数操作
void Eigen_introduction_ArrayClass_002()
{
	ArrayXXf a = ArrayXXf::Random(2, 2);     // 初始化2X2  Array
	a *= 2;
	cout << "a = " << endl
		<< a << endl;
	a = a.abs();
	cout << "a.abs() = " << endl
		<< a << endl;
	cout << "a.sqrt() =" << endl
		<< a.sqrt() << endl;
	cout << "a.minCoeff() = " << endl
		<< a.minCoeff() << endl;
	cout << "a.maxCoeff() = " << endl
		<< a.maxCoeff() << endl;
}

//Matrix和Array之间的相互转换
void Eigen_introduction_MatrixToArray_001()
{
	Array44f a1, a2;
	Matrix4f m1, m2;
	m1 = a1 * a2;                     //coeffwise乘积，从数组到矩阵的隐式转换。
	std::cout << "m1: " << std::endl << m1 << std::endl;
	a1 = m1 * m2;                     //矩阵乘积，从矩阵到数组的隐式转换。
	std::cout << "a1: " << std::endl << a1 << std::endl;

	a2 = a1 + m1.array();             //禁止混合数组和矩阵，必须显式转换以后才可以相加
	m2 = a1.matrix() + m1;    
	std::cout << "a2: " << std::endl << a2 << std::endl;
	std::cout << "m2: " << std::endl << m2 << std::endl;

	ArrayWrapper<Matrix4f> m1a(m1);   // m1a是m1.array（）的别名，它们共享相同的系数
	MatrixWrapper<Array44f> a1m(a1);
}
