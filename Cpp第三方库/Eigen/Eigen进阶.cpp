#include "../第三方库测试.h"
using namespace Eigen;

//测试一下random_shuffle	//可行
void Eigen_RandomShuffle()
{
	//创建一个线性向量
	Eigen::VectorXi v = Eigen::VectorXi::LinSpaced(10, 0, 9);
	std::cout << v.transpose()	<< endl;
	//Eigen矩阵也是有begin()和end(),并且是一个指针
	std::cout << "*v.begin():\t"	<< * v.begin()		<< endl;
	std::cout << "*(v.end()-1):\t"	<< * (v.end()-1)	<< endl;
	//random_shuffle
	random_shuffle(v.begin(), v.end());
	std::cout << "转置后"		<< endl;
	std::cout << v.transpose()	<< endl;
}