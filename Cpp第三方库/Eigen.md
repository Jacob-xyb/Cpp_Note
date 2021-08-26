# 入门篇

[Eigen官网](http://eigen.tuxfamily.org/index.php?title=Main_Page)

[Eigen官方文档](http://eigen.tuxfamily.org/dox/)

## 简介

Eigen是C++中可以用来调用并进行矩阵计算的一个库，简单了说它就是一个c++版本的matlab包。

Eigen是一个开源库，从3.1.1版本开始遵从MPL2许可。

## 模块和头文件

Eigen库被分为一个Core模块和其他一些模块，每个模块有一些相应的头文件。 为了便于引用，Dense模块整合了一系列模块；Eigen模块整合了所有模块。一般情况下，`include<Eigen/Dense>`就够了。

![](https://img-blog.csdnimg.cn/20201208114004847.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L01heWJlVG5U,size_16,color_FFFFFF,t_70)

## 入门案例

- 头文件

  ```cpp
  #include <Eigen/Dense>
  using namespace Eigen;
  ```

- **MatrixXd**

  Eigen头文件定义了许多类型，所有的类型都在Eigen的命名空间内。MatrixXd代表的是任意大小（X*X）的矩阵，并且每个元素为double类型。

  ```cpp
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
  ```

  输出

  ```cpp
  -6.27744e+66 -6.27744e+66
  -6.27744e+66 -6.27744e+66
  1 2
  3 4
  ```

- **矩阵切片 和 VectorXd**

  