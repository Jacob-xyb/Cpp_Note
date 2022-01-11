# 入门篇

[Eigen官网](http://eigen.tuxfamily.org/index.php?title=Main_Page)

[Eigen官方文档](http://eigen.tuxfamily.org/dox/)

对于一个优质第三库最好的入门学习方式就是去读官方文档。

- 速查

  [头文件检索](https://eigen.tuxfamily.org/dox/group__QuickRefPage.html#QuickRef_Headers) 
  
  [Array, matrix and vector types](https://eigen.tuxfamily.org/dox/group__QuickRefPage.html#QuickRef_Types)

## 简介

Eigen是C++中可以用来调用并进行矩阵计算的一个库，简单了说它就是一个c++版本的matlab包。

Eigen是一个开源库，从3.1.1版本开始遵从MPL2许可。

- **快速参考页面（quick reference pages）**

  以非常简洁的格式提供非常完整的 API 描述，目前只有两个功能集：

  - [矩阵和数组操作](http://eigen.tuxfamily.org/dox/group__QuickRefPage.html)
  - [线性代数](http://eigen.tuxfamily.org/dox/group__SparseQuickRefPage.html)

- [MATLAB对应表](http://eigen.tuxfamily.org/dox/AsciiQuickReference.txt)

- [扩展/自定义特征](UserManual_CustomizingEigen.html)

  有关扩展特征特征和支持自定义标量类型的讨论和示例

- [Eigen内部见解](https://eigen.tuxfamily.org/dox/UserManual_Generalities.html)

  例如预处理器指令、控制断言、多线程、MKL 支持、一些Eigen的内部见解等等..

- [Eigen不受支持的模块](http://eigen.tuxfamily.org/dox/unsupported/index.html)

- 如何安装

  [官网下载地址](http://eigen.tuxfamily.org/index.php?title=Main_Page#Download)

  下载解压缩，`项目的包含路径`添加Eigen源代码根目录，代码中包含Eigen头文件即可。

  但是往往还会用到Eigen的[unsupported](http://eigen.tuxfamily.org/) 模块，因此最好的做法的是将 `Eigen-3.X `和 `Eigen-3.X\unsupported` 均放在include：
  
  项目include：
  
  ```cpp
  "..\Eigen\Eigen-3.X"
  "..\Eigen\Eigen-3.X\unsupported"
  ```
  
  这样是为了在导入  `unsupported` 时会不知道来源，直接用`Eigen`反而比较省事，
  
  引用时：
  
  ```cpp
  //Eigen
  #include <Eigen/Dense>
  #include <Eigen/NonLinearOptimization>
  ```
  
  实际上，`Eigen`子目录中的头文件是使用[Eigen](namespaceEigen.html)编译程序所需的唯一文件。所有平台的头文件都相同。没有必要使用 CMake 或安装任何东西。

## 模块和头文件

Eigen库被分为一个Core模块和其他一些模块，每个模块有一些相应的头文件。 为了便于引用，Dense模块整合了一系列模块；Eigen模块整合了所有模块。一般情况下，`include<Eigen/Dense>`就够了。

![](https://img-blog.csdnimg.cn/20201208114004847.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L01heWJlVG5U,size_16,color_FFFFFF,t_70)

## Hello Eigen

- 头文件

  使用Eigen添加以下头文件即可

```cpp
#include <Eigen/Dense>
using namespace Eigen;
```

- 快速写一个Eigen代码让你第一次接触Eigen

```cpp
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
```

输出

```cpp
-6.27744e+66 -6.27744e+66
-6.27744e+66 -6.27744e+66
  3  -1
2.5 1.5
```

解释一下上述程序

- Eigen头文件定义了多种类型，但对于简单的应用，可能足以只使用`MatrixXd`类型。

- 矩阵是任意大小，因此是 `X in MatrixXd`
- 其中每个条目都是一个`double`，因此是 `d in MatrixXd`

## Matrices and vectors

现在结合矩阵和向量进行练习

- example 1

```cpp
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
```

- example 2

```cpp
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
```

- 总结

  使用固定大小的矩阵和向量有两个优点。编译器生成更好（更快）的代码，因为它知道矩阵和向量的大小。在类型中指定大小还允许在编译时进行更严格的检查。例如，如果您尝试将 a `Matrix4d`（4×4 矩阵）与 a `Vector3d`（大小为 3 的向量）相乘，编译器会报错。但是，使用多种类型会增加编译时间和可执行文件的大小。在编译时也可能不知道矩阵的大小。经验上是对 4×4 或更小的大小使用固定大小的矩阵。

# 矩阵和数组操作

## 矩阵类（**The Matrix class**）

在[Eigen 中](https://eigen.tuxfamily.org/dox/namespaceEigen.html)，所有矩阵和向量都是[Matrix](https://eigen.tuxfamily.org/dox/classEigen_1_1Matrix.html)模板类的对象。向量只是矩阵的一种特殊情况，具有 1 行或 1 列。

### Matrix的前三个模板参数

该[矩阵](https://eigen.tuxfamily.org/dox/classEigen_1_1Matrix.html)类需要六个模板参数，但是现在了解前三个参数已经足够了。

剩下的三个参数有默认值，现在我们将保持不变，我们将[在下面讨论](https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html#TutorialMatrixOptTemplParams)。

Matrix的三个强制性模板参数是：

`Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>`

- `Scalar`是标量类型，即系数的类型。也就是说，如果您想要一个浮点矩阵，请在此处选择`float`。有关所有支持的标量类型的列表以及如何扩展对新类型的支持，请参阅[标量](https://eigen.tuxfamily.org/dox/TopicScalarTypes.html)类型。
- `RowsAtCompileTime`和`ColsAtCompileTime`是编译时已知的矩阵的行数和列数（如果在编译时不知道该数字，请参见[下文](https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html#TutorialMatrixDynamic)了解该怎么做）。

我们提供了很多方便的 typedef 来涵盖通常的情况。例如，`Matrix4f`是一个 4x4 的浮点矩阵。这是[Eigen](https://eigen.tuxfamily.org/dox/namespaceEigen.html)定义的方式：

`typedef Matrix<float, 4, 4> Matrix4f;`

Eigen里面用到了很多的typedef简化名称长度，例如：

```cpp
typedef Matrix<float, 3, 1> Vector3f;
typedef Matrix<int, 1, 2> RowVector2i;
typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
typedef Matrix<int, Dynamic, 1> VectorXi;

typedef Array<float,Dynamic,Dynamic>       ArrayXXf
typedef Array<double,Dynamic,1>            ArrayXd
typedef Array<int,1,Dynamic>               RowArrayXi
typedef Array<float,3,3>                   Array33f
typedef Array<float,4,1>                   Array4f
······
```

**Tips:** 虽然Eigen官方已经提供了许多命名模板，但是这是对于`X <= 4 ` 的情况比较试用，一般处理大数据时，为了尽可能的多实用固定矩阵，应该熟练掌握利用原始模板创建对象

### Vector

如上所述，在[Eigen 中](https://eigen.tuxfamily.org/dox/namespaceEigen.html)，向量只是矩阵的一种特殊情况，具有 1 行或 1 列。他们有 1 列的情况是最常见的；这样的向量称为列向量，通常简称为向量。在它们有 1 行的另一种情况下，它们被称为行向量。

例如，方便的 typedef `Vector3f`是 3 个浮点数的（列）向量。它由[Eigen](https://eigen.tuxfamily.org/dox/namespaceEigen.html)定义如下：

`typedef Matrix<float, 3, 1> Vector3f;`

我们还为行向量提供方便的 typedef，例如：

`typedef Matrix<int, 1, 2> RowVector2i;`

### The special value Dynamic

当然，Eigen不限于其维度在编译时已知的矩阵。在RowsAtCompileTime和ColsAtCompileTime模板参数可以采取特殊值Dynamic这表明大小在编译时是未知的，所以必须作为运行时变量来处理。在Eigen术语中，这样的大小被称为动态 大小；而在编译时已知的大小称为固定 大小。

例如，方便的 typedef `MatrixXd` 表示具有动态大小的双精度矩阵，定义如下：

`typedef Matrix<double, Dynamic, Dynamic> MatrixXd;`

同样，我们定义了一个动态大小的 typedef `VectorXi`如下：

`typedef Matrix<int, Dynamic, 1> VectorXi;`

还可以固定某行或某列的大小：

`Matrix<float, 3, Dynamic>;`

### 构造函数

- 默认构造函数始终可用，从不执行任何动态内存分配，也从不初始化矩阵系数。你可以做：

`Matrix3f a;	//a 是一个 3×3 矩阵，带有未初始化系数的普通 float[9] 数组，`

`MatrixXf b;	//b 是一个动态大小的矩阵，其大小当前为 0×0，并且其系数数组尚未分配。`

- 也可以使用获取尺寸的构造函数。

  对于矩阵，总是首先传递行数。对于向量，只需传递向量大小。他们分配给定大小的系数数组，但不初始化系数本身：

`MatrixXf a(10,15); //a 是一个 10x15 动态大小的矩阵，具有已分配但当前未初始化的系数。`

`VectorXf b(30); //b 是大小为 30 的动态大小向量，具有已分配但当前未初始化的系数。 `

- 为了提供跨固定大小和动态大小矩阵的统一 API，在固定大小矩阵上使用这些构造函数是合法的，即使在这种情况下传递大小是无用的。所以这是合法的：

`Matrix3f a(3,3); //虽然没有意义，但是是合法的 `

- 矩阵和向量也可以从系数列表中初始化。在 C++11 之前，此功能仅限于固定大小的小列或最大大小为 4 的向量：

`Vector4d c(5.0, 6.0, 7.0, 8.0);  //C++11之前只能用于固定尺寸的矩阵和向量，且尺寸不大于4`

- 如果启用 C++11，则可以通过传递任意数量的系数来初始化任意大小的固定大小的列或行向量：

```cpp
Vector2i a(1, 2);                      // A column vector containing the elements {1, 2}
Matrix<int, 5, 1> b {1, 2, 3, 4, 5};   // A row-vector containing the elements {1, 2, 3, 4, 5}
Matrix<int, 1, 5> c = {1, 2, 3, 4, 5}; // A column vector containing the elements {1, 2, 3, 4, 5}
```

- 无论是固定还是动态矩阵，系数必须按行分组：

```cpp
MatrixXi a {      // construct a 2x2 matrix
      {1, 2},     // first row
      {3, 4}      // second row
};
Matrix<double, 2, 3> b {
      {2, 3, 4},
      {5, 6, 7},
};
```

- 但是对于列或行向量，允许隐式转置。这意味着可以用行向量初始化列向量：

  切记，只有向量才可以这样

```cpp
VectorXd a {{1.5, 2.5, 3.5}};             // A column-vector with 3 coefficients
RowVectorXd b {{1.0, 2.0, 3.0, 4.0}};     // A row-vector with 4 coefficients
```

### 系数存取器

Eigen重载了圆括号`()`操作符，因此采用 `(i,j)` 取索引访问系数，对于向量只需要传递一个索引`(i)`即可，需要注意的是下标索引均是先行后列。

```cpp
#include <iostream>
#include <Eigen/Dense>
 
using namespace Eigen;
 
int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << "Here is the matrix m:\n" << m << std::endl;
  VectorXd v(2);
  v(0) = 4;
  v(1) = v(0) - 1;
  std::cout << "Here is the vector v:\n" << v << std::endl;
}
```

- **注意**：

  语法`m(index)`不限于向量，它也可用于一般矩阵，这意味着在系数数组中进行基于索引的访问。然而，这取决于矩阵的存储顺序。所有[特征](http://eigen.tuxfamily.org/dox/namespaceEigen.html)矩阵默认为列优先存储顺序，但这可以更改为行优先。

  `operator[]` 也被重载用于向量中基于索引的访问，但请记住，C++ 不允许 operator[] 接受多个参数。我们将 `operator[]` 限制为向量，因为 C++ 语言中的一个笨拙会使 matrix[i,j] 编译为与 matrix[j] 相同的东西！

### 逗号初始化

矩阵和向量系数可以使用所谓的`逗号初始化`语法方便地设置，后续会介绍更高级的初始化方式。

```cpp
Matrix3f m;
m << 1, 2, 3,
     4, 5, 6,
     7, 8, 9;
std::cout << m;

//输出
1 2 3
4 5 6
7 8 9
```

### 调整大小

- `resize()` 、`conservativeResize()`

可以通过rows()、cols()和size()检索矩阵的当前大小。这些方法分别返回行数、列数和系数数。调整动态大小矩阵的大小是通过resize()方法完成的。

- **注意：**

1. 只有动态矩阵才能调整大小**（为了 API 的一致性，所有这些方法在固定大小的矩阵上仍然可用。当然，您实际上无法调整固定大小的矩阵的大小。尝试将固定大小更改为实际不同的值将触发断言失败。）

2. `resize()` 如果没有改变矩阵大小，则不会对其进行操作；否则就会重置矩阵；如果您想要不改变系数的 resize() 的保守变体，请使用[conservativeResize()](http://eigen.tuxfamily.org/dox/classEigen_1_1PlainObjectBase.html#a712c25be1652e5a64a00f28c8ed11462)

**例1：**

```cpp
void Eigen_MatrixClass_Resizeing_001()
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
```

输出

```cpp
1 1
1 1
The matrix m is of size 4x3
It has 12 coefficients
The vector v is of size 5
As a matrix, v is of size 5x1
```

**例2：**

```cpp
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
```

输出

```cpp
调整前:
1 1
1 1
不改变尺寸:
1 1
1 1
保留调整后:
           1            1 -6.27744e+66
           1            1 -6.27744e+66
-6.27744e+66 -6.27744e+66 -6.27744e+66
-6.27744e+66 -6.27744e+66 -6.27744e+66
保留调整后:
           1            2 -6.27744e+66 -6.27744e+66 -6.27744e+66
```

### 分配和调整大小

Eigen 采用 `operator=`  进行赋值，自动调整左侧矩阵的大小，使其与右侧矩阵的大小匹配。

结合前面的描述，对于 `动态矩阵 = 随意矩阵` 这样赋值是可以随意进行的，但是对于固定矩阵，只有  `固定矩阵 = 同尺寸的矩阵` 才可行，因为在调整大小时，`resize()`并不会对其进行操作，或者理解为 `固定矩阵不能改变大小`。

### 固定尺寸与动态尺寸

什么时候应该使用固定尺寸（例如`Matrix4f`），什么时候应该使用动态尺寸（例如`MatrixXf`）？

简单的答案是：尽可能对非常小的尺寸使用固定尺寸，对较大尺寸或必须使用的尺寸使用动态尺寸。对于小尺寸，尤其是小于（大约）16 的尺寸，使用固定尺寸对性能非常有益，因为它允许Eigen避免动态内存分配并展开循环。在内部，固定大小的特征矩阵只是一个普通数组。

- 固定尺寸

  `Matrix4f mymatrix; ` 等价于 `float mymatrix[16]; `

  零成本的运行，所以非常快

- 动态尺寸

  `MatrixXf mymatrix(rows,columns);`  等价于 `float *mymatrix = new float[rows*columns];`

  相比之下，动态大小矩阵的数组总是分配在堆上。

  除此之外，MatrixXf 对象将其行数和列数存储为成员变量。

- 较大尺寸时，请用动态矩阵

  对于足够大的尺寸，比如大于（大约）32 的尺寸，使用固定尺寸的性能优势变得可以忽略不计。

  更糟糕的是，尝试在函数内部使用固定大小创建一个非常大的矩阵可能会导致栈溢出，因为Eigen会尝试将数组自动分配为局部变量，而这通常是在栈上完成的。

  最后，根据情况，当使用动态大小时，Eigen也可以更积极地尝试矢量化（使用 SIMD 指令），请参阅[Vectorization](http://eigen.tuxfamily.org/dox/TopicVectorization.html)。

### 可选模板参数

我们在本章开头提到[Matrix](http://eigen.tuxfamily.org/dox/classEigen_1_1Matrix.html)类需要六个模板参数，但到目前为止我们只讨论了前三个。其余三个参数是可选的。以下是模板参数的完整列表：

```cpp
Matrix<typename Scalar,
       int RowsAtCompileTime,
       int ColsAtCompileTime,
       int Options = 0,
       int MaxRowsAtCompileTime = RowsAtCompileTime,
       int MaxColsAtCompileTime = ColsAtCompileTime>
```

- `Options` 是一个位域。在这里，我们只讨论一点：`RowMajor`or `1` . 它指定这种类型的矩阵使用行优先存储顺序；默认情况下，存储顺序为列优先，`ColMajor` or `0`。请参阅有关[StorageOrders](http://eigen.tuxfamily.org/dox/group__TopicStorageOrders.html)的页面。例如，这种类型表示行主 3x3 矩阵：矩阵<float, 3, 3, RowMajor>
- `MaxRowsAtCompileTime` and `MaxColsAtCompileTime` 预分配动态矩阵的行列上限，避免动态内存分配。

```cpp
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

//输出
0
4
9
```

### 方便的类型定义

- Eigen定义了以下矩阵类型定义：

  MatrixNt 用于 Matrix<type, N, N>。例如，MatrixXi 表示 Matrix<int, Dynamic, Dynamic>。

  Matrix<type, N, 1> 的 VectorNt。例如，用于 Matrix<float, 2, 1> 的 Vector2f。

  Matrix<type, 1, N> 的 RowVectorNt。例如，用于 Matrix<double, 1, 3> 的 RowVector3d。

- 参数：

  N 可以是2、3、4、 或X（意思是Dynamic）中的任何一个。(大于4的时候需要自己改写)

  t 可以是i（表示 int）、f（表示 float）、d（表示双精度）、cf（表示 `complex<float>`）或cd（表示 `complex<double>`）中的任何一种。

  typedef 仅针对这五种类型定义的事实并不意味着它们是唯一受支持的标量类型。例如，支持所有标准整数类型，请参阅 [Scalar types](http://eigen.tuxfamily.org/dox/TopicScalarTypes.html)。

  

## 矩阵和向量算术（**Matrix and vector arithmetic**）

本章旨在提供有关如何使用Eigen在矩阵、向量和标量之间执行算术的概述和一些详细信息。

### 介绍

Eigen通过重载常见的 C++ 算术运算符（例如 +、-、*）或通过特殊方法（例如 dot()、cross() 等）提供矩阵/向量算术运算。对于Matrix类（矩阵和向量），运算符仅重载以支持线性代数运算。

例如，matrix1 * matrix2表示矩阵-矩阵乘积，这对于vector和scalar是不允许的。

如果要执行非线性代数的各种数组运算，得依靠数组来进行运算，后续会讲到。

### 加减

操作符左右对象必须具有相同的行列以及数据类型。

值得一提的是 `一元运算符 - 就是 -a`

```cpp
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
```

输出

```cpp
a + b =
3 5
4 8
a - b =
-1 -1
 2  0
Doing a += b;
Now a =
3 5
4 8
-v + w - v =
-1 -4 -6
```

### 标量乘除

so easy

```cpp
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
```

输出

```cpp
a * 2.5 =
2.5   5
7.5  10
0.1 * v =
0.1
0.2
0.3
Doing v *= 2;
Now v =
2
4
6
```

### 关于表达式模板的说明

这虽然是一个高级主题，但是有必要在此提及。

在Eigen 中，诸如算术运算符operator+本身不执行任何计算，它们只返回一个描述要执行的计算的“表达式对象”。实际计算发生在稍后，当整个表达式被评估时，通常在operator=. 虽然这听起来很沉重，但任何现代优化编译器都能够优化掉这种抽象，结果是完美优化的代码。

简单点说就是，尽可能的将所有运算写在一起，这样才可以更好的优化代码。

```cpp
VectorXf a(50), b(50), c(50), d(50);
...
a = 3*b + 4*c + 5*d;
```

全部写在一起的好处就是可以只遍历一次向量，下面是编译后的结果：

```cpp
for ( int i = 0; i < 50; ++i)
  a[i] = 3*b[i] + 4*c[i] + 5*d[i];
```

### 转置和共轭

转置 transpose()：$a^T$；共轭 conjugate()：$\bar a$ ；伴随 adjoint ()：$a^*$；

```cpp
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
```

输出

```cpp
Here is the matrix a
 (0.127171,-0.997497) (-0.0402539,0.170019)
 (0.617481,-0.613392)  (0.791925,-0.299417)
Here is the matrix a^T
 (0.127171,-0.997497)  (0.617481,-0.613392)
(-0.0402539,0.170019)  (0.791925,-0.299417)
Here is the conjugate of a
   (0.127171,0.997497) (-0.0402539,-0.170019)
   (0.617481,0.613392)    (0.791925,0.299417)
Here is the matrix a^*
   (0.127171,0.997497)    (0.617481,0.613392)
(-0.0402539,-0.170019)    (0.791925,0.299417)
Here is the conjugate of b
  0.64568 -0.651784
  0.49321  0.717887
```

- 对于实矩阵，`conjugate()`是无运算，因此`adjoint()`等价于`transpose()`。

- **aliasing issue:** 

  例如`b = a.transpose() ;`，此时矩阵a在开始转置的同时就将结果写入了矩阵b，那么问题就来了，`a = a.transpose() ;` 就会导致，a在转置的过程中在不断的写入a，会导致程序崩坏，这种问题被称之为`aliasing issue`。

  ```cpp
  Matrix2i a; a << 1, 2, 3, 4;
  cout << "Here is the matrix a:\n" << a << endl;
   
  a = a.transpose(); // !!! do NOT do this !!!
  cout << "and the result of the aliasing effect:\n" << a << endl
  ```

  如果采用断点找到断言并注释掉进行debug，结果发现

  ```cpp
  Here is the matrix a:
  1 2
  3 4
  and the result of the aliasing effect:
  1 2
  2 4
  ```

  断言在`Transpose.h`文件中，记住用完得还原，因为有更好的方法。

  ![image-20210830153122657](https://i.loli.net/2021/08/30/8PINCqzt2kmnR6d.png)

- 转置自身

  如果需要转置自身，使用 [transposeInPlace()](http://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#ac501bd942994af7a95d95bee7a16ad2a) 即可；还有复数矩阵的伴随矩阵 [transposeInPlace()](http://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#ac501bd942994af7a95d95bee7a16ad2a) 。

  ```cpp
  void Eigen_MatrixArithmetic_Transposition_002()
  {
  	Matrix2i a; a << 1, 2, 3, 4;
  	cout << "Here is the matrix a:\n" << a << endl;
  
  	//a = a.transpose(); // !!! do NOT do this !!!
  	//cout << "and the result of the aliasing effect:\n" << a << endl;
  
  	a.transposeInPlace();
  	cout << "and the result of the transposeInPlace():\n" << a << endl;
  }
  ```

  输出

  ```cpp
  Here is the matrix a:
  1 2
  3 4
  and the result of the transposeInPlace():
  1 3
  2 4
  ```

### 矩阵-矩阵和矩阵-向量乘法

对于操作符`*`不用担心 `m = m * m` 发生 `aliasing issue`，因为Eigen在计算矩阵乘法时都会引入一个临时变量`temp`：

```cpp
m = m * m;

//会被编译为
temp = m * m;
m = temp;
```

如果您知道您的矩阵乘积是安全的、不会造成 `aliasing issue` 的情况下，可以使用 [noalias()](http://eigen.tuxfamily.org/dox/classEigen_1_1MatrixBase.html#a2c1085de7645f23f240876388457da0b) 函数来避免创建临时变量；

`c.noalias() += a * b;`

- 优化问题

  `c.noalias() -= 2 * a.adjoint() * b;` 

  这样的表达式已经完全进行了优化，放心使用

```cpp
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
```

输出

```cpp
Here is mat* mat:
 7 10
15 22
Here is mat * u:
1
1
Here is u^T * mat:
2 2
Here is u^T * v:
-2
Here is u * v^T:
-2 -0
 2  0
Let's multiply mat by itself
Now mat is mat:
 7 10
15 22
```

### 点积和叉积

点积： [dot()](http://eigen.tuxfamily.org/dox/classEigen_1_1MatrixBase.html#adfd32bf5fcf6ee603c924dde9bf7bc39) ；叉积： [cross()](http://eigen.tuxfamily.org/dox/group__Geometry__Module.html#ga0024b44eca99cb7135887c2aaf319d28)

`dot()` 等价于 `u.adjoint()*v`

```cpp
void Eigen_MatrixArithmetic_DotAndCross_001()
{
	Vector3d v(1, 2, 3);
	Vector3d w(0, 1, 2);

	cout << "Dot product: " << v.dot(w) << endl;
	double dp = v.adjoint() * w; // automatic conversion of the inner product to a scalar
	cout << "Dot product via a matrix product: " << dp << endl;
	cout << "Cross product:\n" << v.cross(w) <<	 endl;
}
```

输出

```cpp
Dot product: 8
Dot product via a matrix product: 8
Cross product:
 1
-2
 1
```

- **注意**

  叉积仅适用于大小为3的向量！点积适用于任何大小的向量。

  使用复数时，Eigen的点积在第一个变量中是共轭线性的，在第二个变量中是线性的。

### 基本算术归约运算

Eigen还提供了一些归约操作来将给定的矩阵或向量归约为单个值，例如总和（由sum()计算）、乘积（prod()）或最大值（maxCoeff()）和最小值（minCoeff() ) 的所有系数。

其中 `trace()` 等价于  `a.diagonal().sum()`

```cpp
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
```

还存在通过参数返回相应系数坐标的`minCoeff`和`maxCoeff`函数的变体：

```cpp
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
```

输出

```cpp
这是矩阵 m:
  0.842586    0.36906   0.853816
0.00411999  0.0541093  -0.511826
 -0.180944  0.0358592  -0.813776
它的最小系数 (-0.813776) 位于 (2,2)

这是向量 v： -5082 -13404 -11318 -11799
它的最大系数 (-5082) 在位置 0
```

### 操作的有效性

Eigen检查您执行的操作的有效性。如果可能，它会在编译时检查它们，从而产生编译错误。这些错误消息可能又长又丑，但Eigen将重要消息写入 UPPERCASE_LETTERS_SO_IT_STANDS_OUT。

```cpp
Matrix3f m;
Vector4f v;
v = m*v;      // Compile-time error: YOU_MIXED_MATRICES_OF_DIFFERENT_SIZES
```

当然，在很多情况下，例如在检查动态大小时，无法在编译时进行检查。Eigen然后使用运行时断言。这意味着如果程序在“调试模式”下运行，程序将在执行非法操作时中止并显示错误消息，如果断言关闭，它可能会崩溃。

```cpp
MatrixXf m(3,3);
VectorXf v(4);
v = m * v; // Run-time assertion failure here: "invalid matrix product
```

## 数组（**The Array class**）

数组是比较通用的类，不像矩阵专注于线性代数。

此外，Array类提供了一种简单的方法来执行系数操作，这可能没有线性代数含义，例如向数组中的每个系数添加一个常数或将两个数组按系数相乘。

### 数组类型

Array是一个类模板，它采用与Matrix相同的模板参数。与Matrix 一样，前三个模板参数是必需的：

`Array<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>`

后面三个参数和矩阵类完全相同，详情请参考 [矩阵类](https://blog.csdn.net/weixin_44560698/article/details/120000460)

Eigen还为一些常见情况提供了 typedef，其方式类似于Matrix typedef，但有一些细微差别，因为“数组”一词用于一维和二维数组。

Eigen采用这样的约定，即 ArrayNt 形式的 typedef 代表一维数组，其中 N 和 t 是大小和标量类型，如本页中解释的矩阵typedef所示。对于二维数组，我们使用 ArrayNNt 形式的 typedef。

**示例：**

| Type                          | Typedef  |
| ----------------------------- | :------- |
| Array<float,Dynamic,1>        | ArrayXf  |
| Array<float,3,1>              | Array3f  |
| Array<double,Dynamic,Dynamic> | ArrayXXd |
| Array<double,3,3>             | Array33d |

### 访问数组

Eigen重载了括号运算符访问数组。

同时，左移运算符也被重载用于(逗号)初始化，和打印输出。

```cpp
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
```

输出：

```cpp
a
1 2
3 4
b
4 3
2 1
```

### 四则运算

- 加减运算

两个数组的加减与矩阵相同。如果两个数组具有相同的大小，并且加法或减法是按系数进行的，则该操作是有效的。

数组还支持 `array + scalar` 将标量添加到数组中的每个系数的形式的表达式。`(这提供了不能直接用于Matrix对象的功能)`

- 乘除运算

首先，`array * scalar` 数组乘标量的运算当然是可行的，与矩阵完全一致。

但是！！！，`array*array` 与 `matrix*matrix`是不一样的：

​	矩阵相乘的结果为矩阵乘积；`(m,n)*(n,p)=(m,p)`

​	数组相乘的结果为系数乘积；`(m,n)*(m,n)=(m,n)`

```cpp
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
```

输出：

```cpp
a + b =
 2  4  6
 5  7  9
 8 10 12
a - 2 =
-1  0  1
 2  3  4
 5  6  7
a * b =
 1  4  9
 4 10 18
 7 16 27
a / b =
  1   1   1
  4 2.5   2
  7   4   3
```

### 其他函数操作

`.abs()`、`.sqrt()`等等，

`.min(.)`返回两个同规模数组对应系数最小值的新数组。

```cpp
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
		<< a.minCoeff() << endl;		//最小系数
	cout << "a.maxCoeff() = " << endl
		<< a.maxCoeff() << endl;		//最大系数
	cout << "a.min(b)" << endl
		<< a.min(b).transpose() << endl;			//对应最小值
	cout << "a.max(b)" << endl
		<< a.max(b).transpose() << endl;			//对应最大值
}
```

输出：

```cpp
a =
 -0.113254  -0.110202   0.632496 -0.0588702  -0.971007
b =
 0.851558  0.741935  0.148534  0.241005 -0.610828
a.abs() =
 0.113254  0.110202  0.632496 0.0588702  0.971007
a.sqrt() =
0.336533 0.331967 0.795296 0.242632 0.985397
a.minCoeff() =
-0.971007
a.maxCoeff() =
0.632496
a.min(b)
 -0.113254  -0.110202   0.148534 -0.0588702  -0.971007
a.max(b)
 0.851558  0.741935  0.632496  0.241005 -0.610828
```

### 数组和矩阵相互转换

线性代数运算时需要用矩阵类，系数运算时需要用数组类；但是往往需要两种类型交替使用。

所以数组和矩阵的相互转换就显得尤为重要了，`.array() ` 和 `.matrix() ` 就出现了。



Eigen禁止在表达式中混合矩阵和数组。例如，您不能直接添加矩阵和数组；运算+符的操作数要么都是矩阵，要么都是数组。但是，使用.array()和.matrix()很容易从一种转换到另一种。

这条规则的例外是赋值运算符：允许将矩阵表达式赋值给数组变量，或将数组表达式赋值给矩阵变量。

因此两个同尺寸的矩阵转换成数组相乘再分配给矩阵的语法也是合法的：`result = m1.array()*m2.array()`



事实上，这种用法非常普遍，以至于Eigen为矩阵提供了一个const .cwiseProduct(.)方法来计算系数乘积。

```cpp
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
```

输出：

```cpp
/*	Matrix to Array*/
-- Matrix m*n: --
 6  6
14 14

-- Array m*n: --
2 4
6 8

-- With cwiseProduct: --
2 4
6 8

-- Array m + 4: --
5 6
7 8

/*	Array to Matrix*/
-- Combination 1: --
22 22
30 30

-- Combination 2: --
12 12
28 28
```

## 块操作

块操作既可以作为右值，还可以作为左值！

### 基本操作

| **Block** **operation**                    | **dynamic-size block expression** | **fixed-size block expression** |
| ------------------------------------------ | --------------------------------- | ------------------------------- |
| Block of size `(p,q)`, starting at `(i,j)` | `matrix.block(i,j,p,q);`          | `matrix.block<p,q>(i,j);`       |

两个版本都可用于固定大小和动态大小的矩阵和数组。这两个表达式在语义上是等价的。

唯一的区别是，如果块大小很小，固定大小的版本通常会给你更快的代码，但需要在编译时知道这个大小。

```cpp
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
```

输出：

```cpp
Block in the middle
 6  7
10 11

Block of size 1x1
1

Block of size 2x2
1 2
5 6

Block of size 3x3
 1  2  3
 5  6  7
 9 10 11
```

### 块的左值操作

```cpp
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
```

输出

```cpp
Here is the array a:
0.6 0.6 0.6 0.6
0.6 0.6 0.6 0.6
0.6 0.6 0.6 0.6
0.6 0.6 0.6 0.6

Here is now a with m copied into its central 2x2 block:
0.6 0.6 0.6 0.6
0.6   1   2 0.6
0.6   3   4 0.6
0.6 0.6 0.6 0.6

Here is now a with bottom-right 2x3 block copied into top-left 2x3 block:
  3   4 0.6 0.6
0.6 0.6 0.6 0.6
0.6   3   4 0.6
0.6 0.6 0.6 0.6
```

### 列和行

单独的行和列是块的特殊情况，Eigen提供了对应的函数。

`matrix.row(i);` 和 `matrix.col(j);`

```cpp
void Eigen_Introduction_Block002()
{
	Eigen::MatrixXf m(3, 3);
	m << 1, 2, 3,
		 4, 5, 6,
		 7, 8, 9;
	cout << "Here is the matrix m:" << endl << m << endl;
	cout << "2nd Row: " << m.row(1) << endl;
	m.col(2) += 3 * m.col(0);
	cout << "After adding 3 times the first column into the third column, the matrix m is:\n";
	cout << m << endl;
}
```

输出：

```cpp
Here is the matrix m:
1 2 3
4 5 6
7 8 9
2nd Row: 4 5 6
After adding 3 times the first column into the third column, the matrix m is:
 1  2  6
 4  5 18
 7  8 30
```

### 角操作

| **Block** **operation**       | **dynamic-size block expression** | **fixed-size block expression** |
| ----------------------------- | --------------------------------- | ------------------------------- |
| Top-left p by q block         | `matrix.topLeftCorner(p,q);`      | `matrix.topLeftCorner<p,q>();`  |
| Bottom-left p by q block      | `matrix.bottomLeftCorner(p,q);`   | `()  ->  <>()`                  |
| Top-right p by q block        | `matrix.topRightCorner(p,q);`     | `()  ->  <>()`                  |
| Bottom-right p by q block     | `matrix.bottomRightCorner(p,q);`  | `()  ->  <>()`                  |
| the first q rows              | `matrix.topRows(q);`              | `()  ->  <>()`                  |
| the last q rows               | `matrix.bottomRows(q);`           | `()  ->  <>()`                  |
| the first p columns           | `matrix.leftCols(p);`             | `()  ->  <>()`                  |
| the last q columns            | `matrix.rightCols(q);`            | `()  ->  <>()`                  |
| the q columns starting from i | `matrix.middleCols(i,q);`         | `()  ->  <>()`                  |
| the q rows starting from i    | `matrix.middleRows(i,q);`         | `()  ->  <>()`                  |

```cpp
void Eigen_Introduction_Block003()
{
	Eigen::Matrix4f m;
	m << 1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16;
	cout << "m.leftCols(2) =" << endl << m.leftCols(2) << endl << endl;
	cout << "m.bottomRows<2>() =" << endl << m.bottomRows<2>() << endl << endl;
	m.topLeftCorner(1, 3) = m.bottomRightCorner(3, 1).transpose();
	cout << "After assignment, m = " << endl << m << endl;
}
```

输出：

```cpp
m.leftCols(2) =
 1  2
 5  6
 9 10
13 14

m.bottomRows<2>() =
 9 10 11 12
13 14 15 16

After assignment, m =
 8 12 16  4
 5  6  7  8
 9 10 11 12
13 14 15 16
```

### 向量的块操作

同样对一维向量和数组提供了块操作

| **Block** **operation**                | **dynamic-size block expression** | **fixed-size block expression** |
| -------------------------------------- | --------------------------------- | ------------------------------- |
| the first `n` elements                 | `vector.head(n);`                 | `vector.head<n>();`             |
| the last `n` elements                  | `vector.tail(n);`                 | `()  ->  <>()`                  |
| `n` elements, starting at position `i` | `vector.segment(i,n);`            | `()  ->  <>()`                  |

```cpp
//Block operations for vectors
void Eigen_Introduction_Block004()
{
	Eigen::ArrayXf v(6);
	v << 1, 2, 3, 4, 5, 6;
	cout << "v.head(3) =" << endl << v.head(3).transpose() << endl << endl;
	cout << "v.tail<3>() = " << endl << v.tail<3>().transpose() << endl << endl;
	v.segment(1, 4) *= 2;
	cout << "after 'v.segment(1,4) *= 2', v =" << endl << v.transpose() << endl;
}
```

输出：

```cpp
v.head(3) =
1 2 3

v.tail<3>() =
4 5 6

after 'v.segment(1,4) *= 2', v =
 1  4  6  8 10  6
```

## 切片和索引

` operator() `重载赋值运算符提供切片和索引

所有上述操作都通过通用 `DenseBase::operator()(const RowIndices&, const ColIndices&) `方法处理。每个参数可以是：

- 索引单个行或列的整数，包括符号索引。
- 符号[Eigen::all](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga790ab6c4226ef5f678b9eb532a3eab14)以递增的顺序表示整个行或列的集合。
- 由[Eigen::seq](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a0c04400203ca9b414e13c9c721399969)、[Eigen::seqN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#a3a3c346d2a61d1e8e86e6fb4cf57fbda)或[Eigen::lastN](http://eigen.tuxfamily.org/dox/namespaceEigen.html#acc01e5c7293dd3af76e79ae68cc87f77)函数构造的[ArithmeticSequence](http://eigen.tuxfamily.org/dox/classEigen_1_1ArithmeticSequence.html)。
- 任何一维向量/整数数组，包括 Eigen 的向量/数组、表达式、std::vector、std::array 以及普通的 C 数组：`int[N]`。

### 基本切片

通过`Eigen::seq`或`igen::seqN`函数获取矩阵或向量内均匀间隔的一组行、列或元素，其中“seq”代表算术序列。

总结如下：

| **功能**                      | 描述                                     |
| ----------------------------- | ---------------------------------------- |
| `seq (firstIdx,lastIdx)`      | from `firstIdx` to `lastIdx`             |
| `seq (firstIdx,lastIdx,incr)` | 增量`incr`                               |
| `seqN (firstIdx,size)`        | `size` integers starting from `firstIdx` |
| `seqN (firstIdx,size,incr)`   | 增量`incr`                               |

```cpp
void Eigen_Introduction_Slicing()
{
	VectorXd v1 = VectorXd::LinSpaced(10, 0, 9);
	cout << "v1\n"<< v1.transpose() << endl;
	//seq (firstIdx,lastIdx)		// [fIdx,lIdx]
	cout << "v1(seq(0,3))\n" << v1(seq(0, 3)).transpose() << endl;
	VectorXd v2 = v1(seq(0, 9, 2));
	cout << "v1(seq(0,9,2))\n" << v2.transpose() << endl;
	cout << "v1(seqN(0, 4))\n" << v1(seqN(0, 4)).transpose() << endl;
	v2 = v1(seqN(0, 4, 2));
	cout << "v1(seqN(0, 4, 2))\n" <<v2.transpose() << endl;
}
```

输出：

```cpp
v1
0 1 2 3 4 5 6 7 8 9
v1(seq(0,3))
0 1 2 3
v1(seq(0,9,2))
0 2 4 6 8
v1(seqN(0, 4))
0 1 2 3
v1(seqN(0, 4, 2))
0 2 4 6
```

- **last**

`Eigen::last` 可以在代表最后行，列或底层矩阵/向量的元素的索引，然后进行传递。

| **Intent**                                               | Code                        | **Block-API equivalence**          |
| -------------------------------------------------------- | --------------------------- | ---------------------------------- |
| Bottom-left corner starting at row `i` with `n` columns  | `A(seq(i,last), seqN(0,n))` | `A.bottomLeftCorner(A.rows()-i,n)` |
| Block starting at `i`,j having `m` rows, and `n` columns | `A(seqN(i,m), seqN(i,n))`   | `A.block(i,j,m,n)`                 |
| Block starting at `i0`,`j0` and ending at `i1`,`j1`      | `A(seq(i0,i1), seq(j0,j1))` | `A.block(i0,j0,i1-i0+1,j1-j0+1)`   |
| Even columns of A                                        | `A(all, seq(0,last,2))`     | ``                                 |
| First `n` odd rows A                                     | `A(seqN(1,n,2), all)`       | ``                                 |
| The last past one column                                 | `A(all, last-1)`            | `A.col(A.cols()-2)`                |
| The middle row                                           | `A(last/2,all)`             | `A.row((A.rows()-1)/2)`            |
| Last elements of v starting at i                         | `v(seq(i,last))`            | `v.tail(v.size()-i)`               |
| Last `n` elements of v                                   | `v(seq(last+1-n,last))`     | `v.tail(n)`                        |

```cpp
//	Eigen::last
void Eigen_Introduction_Slicing001()
{
	VectorXd v1 = VectorXd::LinSpaced(10, 0, 9);
	cout << "v1(seq(0, last - 3))\n" << v1(seq(0, last - 3)).transpose() << endl;
	cout << "v1(seq(0, 6))\n" << v1(seq(0, 6)).transpose() << endl;
	//因此推断 last = 9
	cout << "the middle of v1\n" << v1(last / 2) << endl;
}
```

输出：

```cpp
v1(seq(0, last - 3))
0 1 2 3 4 5 6
v1(seq(0, 6))
0 1 2 3 4 5 6
the middle of v1
4
```

- **lastN**

| **Intent**                                     | Code                    | **Block-API equivalence**  |
| ---------------------------------------------- | ----------------------- | -------------------------- |
| Last `n` elements of v                         | `v(lastN(n))`           | `v.tail(n)`                |
| Bottom-right corner of A of size `m` times `n` | `v(lastN(m), lastN(n))` | `A.bottomRightCorner(m,n)` |
| Last `n` columns taking 1 column over 3        | `A(all, lastN(n,3))`    | ``                         |

### 编译时间大小和增量

在性能方面，Eigen 和编译器可以利用编译时大小和增量。为此，您可以使用[Eigen::fix](http://eigen.tuxfamily.org/dox/group__Core__Module.html#gac01f234bce100e39e6928fdc470e5194)强制执行编译时参数。这样的编译时值可以与[Eigen::last](http://eigen.tuxfamily.org/dox/group__Core__Module.html#ga2dd8b20d08336af23947e054a17415ee)符号结合使用：

`v( seq ( last -fix<7>, last -fix<2>))`

在上述例子中，Eigen知道在编译时会返回6个元素，等价于

`v(seqN(last-7, fix<6>))`

再来看看偶数列矩阵怎么写

`A(all, seq(0,last,fix<2>))`

```cpp
//Fix<val>
void Eigen_Introduction_Slicing002()
{
	VectorXd v1 = VectorXd::LinSpaced(10, 0, 9);
	cout << v1(seqN(0, fix<4>)).transpose() << endl;
	cout << v1(lastN(fix<4>)).transpose() << endl;
}
```

### 逆序

也可以使用负增量以降序枚举行/列索引。

`A( seqN ( last , n, fix<-1>), all )`

您还可以使用 ArithmeticSequence::reverse() 方法来反转其顺序。因此，前面的例子也可以写成：

`A( lastN (n).reverse(), all )`

### 索引数组

`operator()`重载还提供了任意的 `ArrayXi, a std::vector<int>, std::array<int,N>, etc.`

```cpp
//Array of indices
void Eigen_Introduction_Slicing004()
{
	MatrixXi A = MatrixXi::Random(4, 6);
	A = A - A / 10 * 10;		//resize in [-10, 10]
	cout << "Initial matrix A:\n" << A << "\n\n";

	//传入一个vector
	std::vector<int> ind{0,2,4};
	cout << "A(all,ind):\n" << A(all, ind) << "\n\n";

	//或者直接用数组
	cout << "A(all,{0,2,4}):\n" << A(all, { 0,2,4 }) << "\n\n";

	//还可以用表达式
	ArrayXi idx(3);
	idx << 0, 2, 4;
	cout << "A(all,idx+1):\n" << A(all, idx+1) << "\n\n";
}
```

输出：

```cpp
Initial matrix A:
-5 -4 -1  3 -8  6
-7  8  9 -8 -4  5
-3 -7  4  0  6  7
 3 -6  0 -1 -8 -5

A(all,ind):
-5 -1 -8
-7  9 -4
-3  4  6
 3  0 -8

A(all,{0,2,4}):
-5 -1 -8
-7  9 -4
-3  4  6
 3  0 -8

A(all,idx+1):
-4  3  6
 8 -8  5
-7  0  7
-6 -1 -5
```

如果输入时是固定尺寸的对象，那么返回的也是固定尺寸的对象。

### 自定义索引列表

更一般地，`operator()`可以接受与以下`ind`类型`T`兼容的任何对象作为输入：

```cpp
Index s = ind.size(); or Index s = size(ind);
Index i;
i = ind[i];
```

这意味着您可以轻松构建自己的花哨序列生成器并将其传递给`operator()`. 这是一个放大给定矩阵的示例，同时通过重复填充额外的第一行和列：

```
struct pad {
  Index size() const { return out_size; }
  Index operator[] (Index i) const { return std::max<Index>(0,i-(out_size-in_size)); }
  Index in_size, out_size;
};
 
void Eigen_Introduction_Slicing006()
{
	Matrix3i A;
	A.reshaped() = VectorXi::LinSpaced(9, 1, 9);
	cout << "Initial matrix A:\n" << A << "\n\n";
	MatrixXi B(5, 5);
	B = A(pad{ 3,5 }, pad{ 3,5 });
	cout << "A(pad{3,N}, pad{3,N}):\n" << B << "\n\n";
}
```

输出：

```cpp
Initial matrix A:
1 4 7
2 5 8
3 6 9

A(pad{3,N}, pad{3,N}):
1 1 1 4 7
1 1 1 4 7
1 1 1 4 7
2 2 2 5 8
3 3 3 6 9
```

# 扩展内容

## 存储顺序

[官方文档](http://eigen.tuxfamily.org/dox/group__TopicStorageOrders.html)

矩阵和二维数组有两种不同的存储顺序：列优先和行优先。

本章介绍了这些存储顺序以及如何选择应使用的存储顺序。

### 列优先和行优先存储

矩阵的条目形成二维网格。然而，当矩阵存储在内存中时，条目必须以某种方式线性排列。有两种主要方法可以做到这一点，按行和按列。

果矩阵是**逐行**存储的，我们就说它是按**行优先**顺序存储的。首先存储整个第一行，然后是整个第二行，依此类推。考虑例如矩阵
$$
A = {\begin{bmatrix} 
8 &2 &2 &9 \\
9 &1 &4 &4 \\
3 &5 &4 &5 \\
\end{bmatrix}}
$$
如果此矩阵以行优先顺序存储，则条目在内存中的布局如下:

`8 2 2 9 9 1 4 4 3 5 4 5`

在另一方面，一个矩阵被存储在**列优先**顺序，如果它是由列存储的列，从整个第一列，接着整个第二列，等等。如果上述矩阵以列优先顺序存储，则其布局如下：

`8 9 3 2 1 5 2 4 4 9 4 5 `

此示例由以下`Eigen`代码说明。它使用[PlainObjectBase::data()](http://eigen.tuxfamily.org/dox/classEigen_1_1PlainObjectBase.html#ad12a492bcadea9b65ccd9bc8404c01f1)函数，该函数返回一个指向矩阵第一个条目的内存位置的指针。

```cpp
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
```

输出：

```cpp
The matrix A:
8 2 2 9
9 1 4 4
3 5 4 5

In memory (column-major):
8  9  3  2  1  5  2  4  4  9  4  5

In memory (row-major):
8  2  2  9  9  1  4  4  3  5  4  5
```

### Eigen中的存储顺序

矩阵或二维数组的存储顺序可以通过`Options`为[Matrix](http://eigen.tuxfamily.org/dox/classEigen_1_1Matrix.html)或[Array](http://eigen.tuxfamily.org/dox/classEigen_1_1Array.html)指定模板参数来设置。以[Matrix类](http://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html)为例，Matrix类模板有六个模板参数，其中三个是强制性的（`Scalar`，`RowsAtCompileTime`和`ColsAtCompileTime`）和三个是可选的（`Options`，`MaxRowsAtCompileTime`和`MaxColsAtCompileTime`）。

如果`Options`参数设置为`RowMajor`，则矩阵或数组按行主序存储；如果设置为`ColMajor`，则以列优先顺序存储。上面的[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)程序中使用了这种机制来指定存储顺序。

如果未指定存储顺序，则[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)默认将条目存储在 column-major 中。如果使用了方便的类型定义(Matrix3f、ArrayXXd等)，也会出现这种情况。

使用一种存储顺序的矩阵和数组可以分配给使用另一种存储顺序的矩阵和数组，就像上面程序中`Arowmajor`使用`Acolmajor`来初始化一样。[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)将自动重新排序条目。更一般地，可以根据需要在表达式中混合行主矩阵和列主矩阵。

- 注意：

  ColMajor为0；RowMajor为1

  列向量必须为列优先；行向量必须为行优先

  - Matrix<int, dynamic, 1> option 默认为ColMajor且必须为ColMajor
  - Matrix<int, 1, dynamic> option 默认为RowMajor且必须为RowMajor

```cpp
//	Storage orders
void Eigen_introduction_Storage_orders_001()
{
	//ColMajor为0；RowMajor为1
	//列向量必须为列优先；行向量必须为行优先
	//	Matrix<int, dynamic, 1> option 默认为ColMajor且必须为ColMajor
	//	Matrix<int, 1, dynamic> option 默认为RowMajor且必须为RowMajor
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
```

输出：

```cpp
The matrix A:
1 2 3
4 5 6
7 8 9

In memory (column-major):
1  4  7  2  5  8  3  6  9

In memory (row-major):
1  2  3  4  5  6  7  8  9
```



### 选择哪种存储顺序？

那么，您应该在程序中使用哪种存储顺序？这个问题没有简单的答案。这取决于您的应用程序。以下是一些需要牢记的要点：

- 您的用户可能希望您使用特定的存储顺序。或者，您可以使用[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)以外的其他库，并且这些其他库可能需要特定的存储顺序。在这些情况下，在整个程序中使用此存储顺序可能是最简单和最快的。
- 由于更好的数据局部性，当矩阵以行优先顺序存储时，逐行遍历矩阵的算法将运行得更快。类似地，对于列主矩阵，逐列遍历速度更快。进行一些试验以找出对您的特定应用程序来说更快的方法可能是值得的。
- [Eigen 中](http://eigen.tuxfamily.org/dox/namespaceEigen.html)的默认值是列[优先](http://eigen.tuxfamily.org/dox/namespaceEigen.html)。自然，[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)库的大部分开发和测试都是使用列主矩阵完成的。这意味着，即使我们的目标是透明地支持列优先和行[优先](http://eigen.tuxfamily.org/dox/namespaceEigen.html)存储顺序，[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)库也可能最适合列优先矩阵。 