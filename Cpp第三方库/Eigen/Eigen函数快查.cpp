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
	//用熟以后其实感觉就没必要了
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
	cout << "原矩阵"	<< endl << m1				<< endl;
	cout << "转置矩阵"	<< endl << m1.transpose()	<< endl;
	cout << "共轭矩阵"	<< endl << m1.conjugate()	<< endl;
	cout << "逆矩阵"	<< endl << m1.inverse()		<< endl;
	cout << "伴随矩阵"	<< endl << m1.adjoint()		<< endl;


	//colwise() 以列为单位，不能单独输出
	cout << "逆90°旋转"<< endl << m1.transpose().colwise().reverse() << endl;
	cout << "垂直镜像"	<< endl	<< m1.colwise().reverse().transpose() << endl;
	cout << "矩阵逆序"	<< endl	<< m1.reverse()		<< endl;	//取决于矩阵是列优先还是行优先
}

//Eigen常用函数
void Eigen_QuickCheck_005()
{
	MatrixXd A = MatrixXd::Zero(2, 2);
	RowVectorXd v1 = RowVectorXd::LinSpaced(4, 1, 4);	//（size,low,high）

	cout << "查看矩阵系数个数"	<< A.size() << endl;	// length(A)	// 系数个数
	cout << "查看矩阵行数"		<< A.rows() << endl;	// size(A,1)	// 矩阵行数
	cout << "查看矩阵列数"		<< A.cols() << endl;	// size(A,2)	// 矩阵列数
	//x(i);				// x(i+1)             // 下标0开始
	//A(i, j);          // C(i+1,j+1)         // 下标0开始

	/*少见*/
	//setUnit(index i)	//vector(i) = 1，其余均为0
	v1.setUnit(1);
	cout << "向量重置" << endl << v1 << endl;
	//setUnit(new size num, index i)	//vector.size() = num ; vector(i) = 1，其余均为0
	v1.setUnit(3,1);
	cout << "向量重设大小" << endl << v1 << endl;
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
	cout << MatrixXd(v.head(3).asDiagonal())    << endl;	//将向量设置为对角阵
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
	//m.diagonal()										// m矩阵的对角线
														
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
	cout << "矩阵对角线向量" << endl << m.diagonal()	<< endl;

	cout << "左上二阶子矩阵" << endl << m.topLeftCorner(2, 2)		<< endl;
	cout << "右上二阶子矩阵" << endl << m.topRightCorner(2, 2)		<< endl;
	cout << "左下二阶子矩阵" << endl << m.bottomLeftCorner(2, 2)	<< endl;
	cout << "右下二阶子矩阵" << endl << m.bottomRightCorner(2,2)	<< endl;

}

//Matrix元素操作
void Eigen_QuickCheck_008()
{
	MatrixXd m(4, 4);
	m << 1, 2, 3, 4,
		 5, 6, 7, 8,
		 9, 10, 11, 12,
		 13, 14, 15, 16;
	cout << "矩阵行列赋值" << endl;
	m.col(0) = m.row(0);
	cout << m << endl;
	cout << "矩阵行列交换" << endl;
	m.col(0).swap(m.col(3));
	cout << m << endl;
}


//TODO
/*
//矩阵乘积
// 与Matlab一致, 但是matlab不支持*=等形式的运算.
// Matrix-vector.  Matrix-matrix.   Matrix-scalar.
y  = M*x;          R  = P*Q;        R  = P*s;
a  = b*M;          R  = P - Q;      R  = s*P;
a *= M;            R  = P + Q;      R  = P/s;
				   R *= Q;          R  = s*P;
				   R += Q;          R *= s;
				   R -= Q;          R /= s;

//矩阵运算
// Vectorized operations on each element independently
// Eigen                  // Matlab
R = P.cwiseProduct(Q);    // R = P .* Q 对应点相乘
R = P.array() * s.array();// R = P .* s 对应点相乘
R = P.cwiseQuotient(Q);   // R = P ./ Q 对应点相除
R = P.array() / Q.array();// R = P ./ Q对应点相除
R = P.array() + s.array();// R = P + s对应点相加
R = P.array() - s.array();// R = P - s对应点相减
R.array() += s;           // R = R + s全加s
R.array() -= s;           // R = R - s全减s
R.array() < Q.array();    // R < Q 以下的都是针对矩阵的单个元素的操作
R.array() <= Q.array();   // R <= Q矩阵元素比较，会在相应位置置0或1
R.cwiseInverse();         // 1 ./ P
R.array().inverse();      // 1 ./ P
R.array().sin()           // sin(P)
R.array().cos()           // cos(P)
R.array().pow(s)          // P .^ s
R.array().square()        // P .^ 2
R.array().cube()          // P .^ 3
R.cwiseSqrt()             // sqrt(P)
R.array().sqrt()          // sqrt(P)
R.array().exp()           // exp(P)
R.array().log()           // log(P)
R.cwiseMax(P)             // max(R, P) 对应取大
R.array().max(P.array())  // max(R, P) 对应取大
R.cwiseMin(P)             // min(R, P) 对应取小
R.array().min(P.array())  // min(R, P) 对应取小
R.cwiseAbs()              // abs(P) 绝对值
R.array().abs()           // abs(P) 绝对值
R.cwiseAbs2()             // abs(P.^2) 绝对值平方
R.array().abs2()          // abs(P.^2) 绝对值平方
(R.array() < s).select(P,Q);  // (R < s ? P : Q)这个也是单个元素的操作

//矩阵化简
// Reductions.
int r, c;
// Eigen                  // Matlab
R.minCoeff()              // min(R(:))最小值
R.maxCoeff()              // max(R(:))最大值
s = R.minCoeff(&r, &c)    // [s, i] = min(R(:)); [r, c] = ind2sub(size(R), i);
s = R.maxCoeff(&r, &c)    // [s, i] = max(R(:)); [r, c] = ind2sub(size(R), i);
R.sum()                   // sum(R(:))求和
R.colwise().sum()         // sum(R)列求和1×N
R.rowwise().sum()         // sum(R, 2) or sum(R')'行求和N×1
R.prod()                  // prod(R(:))所有乘积
R.colwise().prod()        // prod(R)列乘积
R.rowwise().prod()        // prod(R, 2) or prod(R')'行乘积
R.trace()                 // trace(R)迹
R.all()                   // all(R(:))且运算
R.colwise().all()         // all(R) 且运算
R.rowwise().all()         // all(R, 2) 且运算
R.any()                   // any(R(:)) 或运算
R.colwise().any()         // any(R) 或运算
R.rowwise().any()         // any(R, 2) 或运算

//矩阵点乘
// Dot products, norms, etc.
// Eigen                  // Matlab
x.norm()                  // norm(x).    模
x.squaredNorm()           // dot(x, x)   平方和
x.dot(y)                  // dot(x, y)
x.cross(y)                // cross(x, y) Requires #include <Eigen/Geometry>

//矩阵类型转换
//Type conversion
// Eigen                           // Matlab
A.cast<double>();                  // double(A)
A.cast<float>();                   // single(A)
A.cast<int>();                     // int32(A) 向下取整
A.real();                          // real(A)
A.imag();                          // imag(A)
// if the original type equals destination type, no work is done

//简单的解方程应用
// Solve Ax = b. Result stored in x. Matlab: x = A \ b.
x = A.ldlt().solve(b));  // #include <Eigen/Cholesky>LDLT分解法实际上是Cholesky分解法的改进
x = A.llt() .solve(b));  // A sym. p.d.      #include <Eigen/Cholesky>
x = A.lu()  .solve(b));  // Stable and fast. #include <Eigen/LU>
x = A.qr()  .solve(b));  // No pivoting.     #include <Eigen/QR>
x = A.svd() .solve(b));  // Stable, slowest. #include <Eigen/SVD>
// .ldlt() -> .matrixL() and .matrixD()
// .llt()  -> .matrixL()
// .lu()   -> .matrixL() and .matrixU()
// .qr()   -> .matrixQ() and .matrixR()
// .svd()  -> .matrixU(), .singularValues(), and .matrixV()

//矩阵特征值
// Eigen                          // Matlab
A.eigenvalues();                  // eig(A);特征值
EigenSolver<Matrix3d> eig(A);     // [vec val] = eig(A)
eig.eigenvalues();                // diag(val)与前边的是一样的结果
eig.eigenvectors();               // vec 特征值对应的特征向量
*/