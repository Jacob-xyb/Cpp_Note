#include "../第三方库测试.h"

//template + using 自定义数据类型
template<typename T>
using Mat2 = Matrix<T, 2, 2>;
void Eigen_QuickCheck_001()
{
	Mat2<int> m1;
	m1 << 1, 1,
		1, 1;
	cout << "m1:" << endl <<m1 << endl;
	//感觉有点花里胡哨..
	Matrix<int, 2, 2> m2(m1);
	cout << "m2:" << endl << m2 << endl;
}

//Eigen矩阵定义
void Eigen_QuickCheck_002()
{
	//未初始化对象
	Matrix<double, 3, 3> A;                 // 固定了行数和列数的矩阵和Matrix3d一致.
	Matrix<double, 3, Dynamic> B;           // 固定行数.
	Matrix<double, Dynamic, Dynamic> C;     // 和MatrixXd一致.
	Matrix<double, 3, 3, RowMajor> E;       // 按行存储; 默认按列存储.
	Matrix3f P, Q, R;                       // 3x3 float 矩阵.
	Vector3f x, y, z;                       // 3x1 float 列向量.
	RowVector3f a, b, c;                    // 1x3 float 行向量.
	VectorXd v;                             // 动态长度double型列向量
	// Eigen			// Matlab             // comments
	A.size();	//9		// length(A)          // 系数个数
	A.rows();			// size(A,1)          // 矩阵行数
	A.cols();			// size(A,2)          // 矩阵列数
	//x(i);				// x(i+1)             // 下标0开始
	//A(i, j);          // C(i+1,j+1)         // 下标0开始
}

//Eigen常用矩阵
void Eigen_QuickCheck_003()
{
	//常用矩阵构建
	MatrixXd m1 = MatrixXd::Zero(2, 2);					//零矩阵
	MatrixXd m2 = MatrixXd::Ones(2, 2);					//全一矩阵
	MatrixXd m3 = MatrixXd::Identity(2, 2);				//单位矩阵
	MatrixXd m4 = MatrixXd::Random(2, 2);				//随机矩阵[-1,1]
	RowVectorXd v1 = RowVectorXd::LinSpaced(4, 1, 4);	//线性分布（size,low,high）
	cout << "线性向量： " << v1 << endl;
	//常用矩阵设置操作
	m1.setOnes();
	cout << "矩阵设为1" << endl << m1 << endl;
	m1.setZero();
	cout << "矩阵设为0" << endl << m1 << endl;
	m1.setRandom();
	cout << "矩阵随机" << endl << m1 << endl;
	m1.setConstant(6);
	cout << "矩阵设为确认常数(setConstant)" << endl << m1 << endl;
	m1.setIdentity();
	cout << "矩阵设为对角矩阵" << endl << m1 << endl;
	//m1.setLinSpaced(4,1,4);	//只能用于向量
	m1.fill(6);
	cout << "矩阵设为确认常数(fill)" << endl << m1 << endl;
}


//Eigen常用特殊矩阵
void Eigen_QuickCheck_004()
{
	MatrixXd m1 = MatrixXd::Random(2, 2);
	cout << "原矩阵" << endl << m1 << endl;
	cout << "转置矩阵" << endl << m1.transpose() << endl;
	cout << "共轭矩阵" << endl << m1.conjugate() << endl;
	cout << "逆矩阵" << endl << m1.inverse() << endl;
	cout << "伴随矩阵" << endl << m1.adjoint() << endl;
}


//Eigen常用函数
void Eigen_QuickCheck_005()
{
	MatrixXd m1 = MatrixXd::Zero(2, 2);
	RowVectorXd v1 = RowVectorXd::LinSpaced(4, 1, 4);	//（size,low,high）

	/*少见*/
	//setUnit(index i)	//vector(i) = 1，其余均为0
	v1.setUnit(1);
	cout << "向量重置" << endl << v1 << endl;
	//setUnit(new size num, index i)	//vector.size() = num ; vector(i) = 1，其余均为0
	v1.setUnit(3,1);
	cout << "矩阵设为对角单位矩阵" << endl << v1 << endl;
}


//Vector块操作
void Eigen_QuickCheck_006()
{
	RowVectorXd v(9);
	v << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	//Eigen									// Matlab
	//v.head(n) \ v.head<n>()				// v(1:n)	用于数组提取前n个[vector]
	//v.tail(n) \ v.tail<n>()				// v(end - n + 1: end)同理
	//v.segment(i, n) \ v.segment<n>(i)     // v(i+1 : i+n)同理

	//操作
	cout << "原向量： "		<< v				<< endl;
	cout << "前三个： "		<< v.head(3)		<< endl;
	cout << "后三个： "		<< v.tail(3)		<< endl;
	cout << "中间三个："	<< v.segment(3, 3)	<< endl;
}


//Matrix块操作
void Eigen_QuickCheck_007()
{
	MatrixXd m(4, 4);
	m << 1, 2, 3, 4,
		 5, 6, 7, 8,
		 9, 10, 11, 12,
		 13, 14, 15, 16;
	cout << "原矩阵" << endl << m << endl;

	//Eigen												// Matlab
	//m.row(i)											// m(i+1, :) 第i行向量
	//m.col(j)											// m(:, j+1) 第j列向量
	//m.topRows(rows) \ m.topRows<rows>()				// m(1:rows, :) 前rows行 
	//m.middleRows(i, rows) \ m.middleRows<rows>(i)		// m(i+1:i+rows, :) 第[i:rows]行 
	//m.bottomRows(rows) \ m.bottomRows<rows>()			// m(end-rows+1:end, :) 后rows行 
	//m.leftCols(cols) \ m.leftCols<cols>()				// m(:, 1:cols) 前cols列
	//m.middleCols(j, cols) \ m.middleCols<cols>(j)	    // m(:, j+1:j+cols) 第[j:cols]列
	//m.rightCols(cols) \ m.rightCols<cols>()			// m(:, end-cols+1:end) 后cols列 
	//m.block(i, j, rows, cols) \ m.block<rows, cols>(i, j)	
														// m(i+1 : i+rows, j+1 : j+cols)i,j开始，rows行cols列
	//	取角 \ (rows, cols) == <rows, cols>()
	//m.topLeftCorner(rows, cols)        // m(1:rows, 1:cols)上左角rows行，cols列
	//m.topRightCorner(rows, cols)       // m(1:rows, end-cols+1:end)上右角rows行，cols列
	//m.bottomLeftCorner(rows, cols)     // m(end-rows+1:end, 1:cols)下左角rows行，cols列
	//m.bottomRightCorner(rows, cols)    // m(end-rows+1:end, end-cols+1:end)下右角rows行，cols列
									
	//操作
	cout << "第一行"	<< endl << m.row(0)				<< endl;
	cout << "第一列"	<< endl << m.col(0).transpose()	<< endl;
	cout << "前两行"	<< endl << m.topRows(2)			<< endl;
	cout << "中间两行"	<< endl << m.middleRows(1,2)	<< endl;
	cout << "后两行"	<< endl << m.bottomRows(2)		<< endl;
	cout << "前两列"	<< endl << m.leftCols(2)		<< endl;
	cout << "中间两列"	<< endl << m.middleCols(1, 2)	<< endl;
	cout << "后两列"	<< endl << m.rightCols(2)		<< endl;
	cout << "子矩阵"	<< endl << m.block(0,0,2,2)		<< endl;

	cout << "左上二阶子矩阵" << endl << m.topLeftCorner(2, 2)		<< endl;
	cout << "右上二阶子矩阵" << endl << m.topRightCorner(2, 2)		<< endl;
	cout << "左下二阶子矩阵" << endl << m.bottomLeftCorner(2, 2)	<< endl;
	cout << "右下二阶子矩阵" << endl << m.bottomRightCorner(2,2)	<< endl;

}

