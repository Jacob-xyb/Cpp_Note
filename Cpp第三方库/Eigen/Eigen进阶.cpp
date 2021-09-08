#include "../第三方库测试.h"
using namespace Eigen;

//测试一下random_shuffle	//可行
void Eigen_RandomShuffle()
{
	//创建一个线性向量
	Eigen::VectorXd v = Eigen::VectorXd::LinSpaced(10, 0, 9);
	std::cout << v.transpose()	<< endl;
	//Eigen矩阵也是有begin()和end(),并且是一个指针
	std::cout << "*v.begin():\t"	<< * v.begin()		<< endl;
	std::cout << "*(v.end()-1):\t"	<< * (v.end()-1)	<< endl;
	//random_shuffle
	random_shuffle(v.begin(), v.end());
	std::cout << "转置后"		<< endl;
	std::cout << v.transpose()	<< endl;
}

//Matrix归一化
void Eigen_NormalizationMatrix()
{
	Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
	cout << m << endl;
	int row = m.rows();
	int col = m.cols();
	Eigen::MatrixXd normal(m);
	for (int j = 0; j < col; j++)
	{
		double xmax = m.col(j).maxCoeff();
		double xmin = m.col(j).minCoeff();
		normal.col(j) = (normal.col(j) - Eigen::VectorXd::Constant(row, xmin)) /
			(xmax - xmin);
	}
	cout << normal << endl;
}