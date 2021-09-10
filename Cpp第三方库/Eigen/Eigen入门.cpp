#include "../第三方库测试.h"
using namespace Eigen;

/*Eigen入门*/
//初识Eigen矩阵
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
//Matrices and vectors:Eg001
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
//Matrices and vectors:Eg002
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
void Eigen_introduction_started_004()
{
	//尺度一定要一致
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
//常用的初始化方法
void Eigen_introduction_started_005()
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
//MatrixXd中的X
void Eigen_introduction_started_006()
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

/*The Matrix class*/
//Storage orders
void Eigen_introduction_Storage_orders_001()
{
	//ColMajor为0；RowMajor为1
	//列向量必须为列优先；行向量必须为行优先
	//	Matrix<int, dynamic, 1> option 默认为ColMajor且必须为ColMajor
	//	Matrix<int, 1, dynamic> option 默认为RowMajor且必须为RowMajor
	Matrix<int, 3, 3, ColMajor> Acolmajor;
	Acolmajor << 1, 2, 3,
				 4, 5, 6,
				 7, 8, 9;
	cout << "The matrix A:" << endl;
	cout << Acolmajor << endl << endl;

	cout << "In memory (column-major):" << endl;
	for (int i = 0; i < Acolmajor.size(); i++)
	  cout << *(Acolmajor.data() + i) << "  ";
	cout << endl << endl;

	Matrix<int, 3, 3, RowMajor> Arowmajor = Acolmajor;
	cout << "In memory (row-major):" << endl;
	for (int i = 0; i < Arowmajor.size(); i++)
	  cout << *(Arowmajor.data() + i) << "  ";
	cout << endl << endl;
}
//	test
void Eigen_introduction_Storage_orders_002()
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
//Constructors
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
//Coefficient accessors
void Eigen_MatrixClass_Coefficient_001()
{
	// the syntax m(index) is not restricted to vectors, it is also available for general matrices
	//	但是是有关矩阵的存储顺序的
	//	mCol 是列优先矩阵； mRow 是行优先矩阵
	Matrix<int, 3, 3, ColMajor> mCol;
	//Matrix<int, 3, 3, 0> mCol;
	mCol << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	cout << "mCol" << endl << mCol << endl;
	cout << "mCol(2): " << mCol(2) << endl;	//7
	Matrix<int, 3, 3, RowMajor> mRow;
	//Matrix<int, 3, 3, 1> mRow;
	mRow << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	cout << "mRow" << endl << mRow << endl;
	cout << "mRow(2): " << mRow(2) << endl;	//3

	//operator[]
	//cout << mRow[3] << endl;	//error	//matrix can't use operator[]
	Matrix<int, 1, 3> v;
	v << 1, 2, 3;
	cout << v[2] << endl;	//3	//one row or one col can use operator[]
}
//Resizeing
void Eigen_MatrixClass_Resizeing_001()
{
	//	The current size of a matrix can be retrieved by rows(), cols() and size(). These methods return the number of rows, the number of columns and the number of coefficients, respectively. Resizing a dynamic-size matrix is done by the resize() method.
	MatrixXd m = Matrix2d::Ones();
	cout << "调整前:" << endl << m << endl;
	m.resize(4, 3);
	std::cout << "The matrix m is of size "
		<< m.rows() << "x" << m.cols() << std::endl;
	std::cout << "It has " << m.size() << " coefficients" << std::endl;
	cout << "调整后:" << endl << m << endl;
	VectorXd v(2);
	v.resize(5);
	std::cout << "The vector v is of size " << v.size() << std::endl;
	std::cout << "As a matrix, v is of size "
		<< v.rows() << "x" << v.cols() << std::endl;
}
void Eigen_MatrixClass_Resizeing_002()
{
	MatrixXd m = Matrix2d::Ones();
	cout << "调整前:" << endl << m << endl;
	m.resize(2, 2);
	cout << "不改变尺寸:" << endl << m << endl;
	m.conservativeResize(4, 3);
	cout << "保留调整后:" << endl << m << endl;

	RowVectorXd v(2);
	v << 1, 2;
	v.conservativeResize(5);
	cout << "保留调整后:" << endl << v << endl;
}
//Optional template parameters
void Eigen_MatrixClass_TemplateParameters_001()
{
	Matrix<int, Dynamic, Dynamic, 0, 4, 4> m;
	cout << m.size() << endl;
	m.resize(2, 2);
	cout << m.size() << endl;
	m.resize(3, 3);
	cout << m.size() << endl;
	//m.resize(5, 3);	//error:(i,j) 中的 i and j 均小于 原有尺寸才行
}

/*Matrixand vector arithmetic*/
//Addition and subtraction
void Eigen_MatrixArithmetic_AdditionAndSubtraction_001()
{
	Matrix2d a;
	a << 1, 2,
		3, 4;
	MatrixXd b(2, 2);
	b << 2, 3,
		1, 4;
	std::cout << "a + b =\n" << a + b << std::endl;
	std::cout << "a - b =\n" << a - b << std::endl;
	std::cout << "Doing a += b;" << std::endl;
	a += b;
	std::cout << "Now a =\n" << a << std::endl;
	RowVector3d v(1, 2, 3);
	RowVector3d w(1, 0, 0);
	std::cout << "-v + w - v =\n" << -v + w - v << std::endl;
}
//Scalar multiplication and division
void Eigen_MatrixArithmetic_ScalarMAndD_001()
{
	Matrix2d a;
	a << 1, 2,
		3, 4;
	Vector3d v(1, 2, 3);
	std::cout << "a * 2.5 =\n" << a * 2.5 << std::endl;
	std::cout << "0.1 * v =\n" << 0.1 * v << std::endl;
	std::cout << "Doing v *= 2;" << std::endl;
	v *= 2;
	std::cout << "Now v =\n" << v << std::endl;
}
//Transposition and conjugation 转置和共轭
void Eigen_MatrixArithmetic_Transposition_001()
{
	MatrixXcf a = MatrixXcf::Random(2, 2);
	cout << "Here is the matrix a\n" << a << endl;
	cout << "Here is the matrix a^T\n" << a.transpose() << endl;
	cout << "Here is the conjugate of a\n" << a.conjugate() << endl;
	cout << "Here is the matrix a^*\n" << a.adjoint() << endl;

	//实数矩阵 的共轭 会报错吗？	//不会
	MatrixXf b = MatrixXf::Random(2, 2);
	cout << "Here is the conjugate of b\n" << b.conjugate() << endl;
}
void Eigen_MatrixArithmetic_Transposition_002()
{
	Matrix2i a; a << 1, 2, 3, 4;
	cout << "Here is the matrix a:\n" << a << endl;

	//a = a.transpose(); // !!! do NOT do this !!!
	//cout << "and the result of the aliasing effect:\n" << a << endl;

	a.transposeInPlace();
	cout << "and the result of the transposeInPlace():\n" << a << endl;
}
//Multiplication
void Eigen_MatrixArithmetic_Multiplication_001()
{
	Matrix2d mat;
	mat << 1, 2,
		3, 4;
	Vector2d u(-1, 1), v(2, 0);
	std::cout << "Here is mat* mat:\n" << mat * mat << std::endl;
	std::cout << "Here is mat * u:\n" << mat * u << std::endl;
	std::cout << "Here is u^T * mat:\n" << u.transpose() * mat << std::endl;
	std::cout << "Here is u^T * v:\n" << u.transpose() * v << std::endl;
	std::cout << "Here is u * v^T:\n" << u * v.transpose() << std::endl;
	std::cout << "Let's multiply mat by itself" << std::endl;
	mat = mat * mat;
	std::cout << "Now mat is mat:\n" << mat << std::endl;
}
//Dot product and cross product
void Eigen_MatrixArithmetic_DotAndCross_001()
{
	Vector3d v(1, 2, 3);
	Vector3d w(0, 1, 2);

	cout << "Dot product: " << v.dot(w) << endl;
	double dp = v.adjoint() * w; // automatic conversion of the inner product to a scalar
	cout << "Dot product via a matrix product: " << dp << endl;
	cout << "Cross product:\n" << v.cross(w) << endl;
}
//Basic arithmetic reduction operations
void Eigen_MatrixArithmetic_ReductionOperations_001()
{
	Eigen::Matrix2d mat;
	mat << 1, 2,
		3, 4;
	cout << "Here is mat.sum():       " << mat.sum() << endl;		// 10
	cout << "Here is mat.prod():      " << mat.prod() << endl;		// 24	
	cout << "Here is mat.mean():      " << mat.mean() << endl;		// 2.5	
	cout << "Here is mat.minCoeff():  " << mat.minCoeff() << endl;	// 1
	cout << "Here is mat.maxCoeff():  " << mat.maxCoeff() << endl;	// 4
	cout << "Here is mat.trace():     " << mat.trace() << endl;		// 5
}
void Eigen_MatrixArithmetic_ReductionOperations_002()
{
	Matrix3f m = Matrix3f::Random();
	std::ptrdiff_t i, j;
	//int i, j;
	float minOfM = m.minCoeff(&i, &j);
	cout << "这是矩阵 m:\n" << m << endl;
	cout << "它的最小系数 (" << minOfM
		<< ") 位于 (" << i << "," << j << ")\n\n";

	RowVector4i v = RowVector4i::Random();
	int maxOfV = v.maxCoeff(&i);
	cout << "这是向量 v：" << v << endl;
	cout << "它的最大系数 (" << maxOfV
		<< ") 在位置 " << i << endl;
}


/*The Array class*/
//Array定义及访问
void Eigen_Introduction_ArrayClass_001()
{
	ArrayXXf a(2, 2);
	ArrayXXf b(2, 2);
	a(0, 0) = 1; a(0, 1) = 2;
	a(1, 0) = 3; a(1, 1) = 4;
	cout << "a\n" << a << endl;
	b << 4, 3, 2, 1;
	cout << "b\n" << b << endl;
}
//Array四则运算
void Eigen_Introduction_ArrayClass_002()
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
//Array其他函数操作
void Eigen_Introduction_ArrayClass_003()
{
	ArrayXf a = ArrayXf::Random(5);
	ArrayXf b = ArrayXf::Random(5);
	cout << "a = " << endl 
		<< a.transpose() << endl;
	cout << "b = " << endl
		<< b.transpose() << endl;
	cout << "a.abs() = " << endl
		<< a.abs().transpose() << endl;				//绝对值
	cout << "a.sqrt() =" << endl
		<< a.abs().sqrt().transpose() << endl;		//开方	
	cout << "a.minCoeff() = " << endl
		<< a.minCoeff() << endl;					//最小系数
	cout << "a.maxCoeff() = " << endl
		<< a.maxCoeff() << endl;					//最大系数
	cout << "a.min(b)" << endl
		<< a.min(b).transpose() << endl;			//对应最小值
	cout << "a.max(b)" << endl
		<< a.max(b).transpose() << endl;			//对应最大值
}
//Matrix和Array之间的相互转换
/*	Matrix to Array*/
void Eigen_Introduction_ArrayClass_004()
{
	Matrix2f m1, m2;
	Matrix2f result;
	Array22f a1, a2;
	m1 << 1, 2,
		  3, 4;
	m2 << 2, 2,
		  2, 2;

	result = m1 * m2;
	cout << "-- Matrix m*n: --" << endl << result << endl << endl;
	result = m1.array() * m2.array();
	cout << "-- Array m*n: --" << endl << result << endl << endl;
	result = m1.cwiseProduct(m2);
	cout << "-- With cwiseProduct: --" << endl << result << endl << endl;
	result = m1.array() + 4;
	cout << "-- Array m + 4: --" << endl << result << endl << endl;
}
/*	Array to Matrix*/
void Eigen_Introduction_ArrayClass_005()
{
	//主要测一下矩阵怎么执行数组运算
	Matrix2f m1, m2;
	Matrix2f result;
	m1 << 1, 2,
		  3, 4;
	m2 << 2, 2,
		  2, 2;
	result = (m1.array() + 4).matrix() * m2;
	cout << "-- Combination 1: --" << endl << result << endl << endl;
	result = (m1.array() * m2.array()).matrix() * m2;
	cout << "-- Combination 2: --" << endl << result << endl << endl;
}


/*Block operations*/
//using block as rvalues
void Eigen_Introduction_Block()
{
	Eigen::MatrixXf m(4, 4);
	m << 1, 2, 3, 4,
		 5, 6, 7, 8,
		 9, 10, 11, 12,
		 13, 14, 15, 16;
	cout << "Block in the middle" << endl;
	cout << m.block<2, 2>(1, 1) << endl << endl;
	for (int i = 1; i <= 3; ++i)
	{
		cout << "Block of size " << i << "x" << i << endl;
		cout << m.block(0, 0, i, i) << endl << endl;
	}
}
//using block as lvalues
void Eigen_Introduction_Block001()
{
	Array22f m;
	m << 1, 2,
		 3, 4;
	Array44f a = Array44f::Constant(0.6);
	cout << "Here is the array a:" << endl << a << endl << endl;
	a.block<2, 2>(1, 1) = m;
	cout << "Here is now a with m copied into its central 2x2 block:" << endl << a << endl << endl;
	a.block(0, 0, 2, 3) = a.block(2, 1, 2, 3);
	cout << "Here is now a with bottom-right 2x3 block copied into top-left 2x3 block:" << endl << a << endl << endl;
}

