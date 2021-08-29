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

  下载解压缩，`项目的包含路径`添加Eigen源代码根目录，代码中包含Eigen头文件即可

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

**Tips:**虽然Eigen官方已经提供了许多命名模板，但是这是对于`X <= 4 ` 的情况比较试用，一般处理大数据时，为了尽可能的多实用固定矩阵，应该熟练掌握利用原始模板创建对象

### 向量

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

- 但是对于列或行向量，允许隐式转置。这意味着可以从单行初始化列向量：

  切记，只有向量才满足

```cpp
VectorXd a {{1.5, 2.5, 3.5}};             // A column-vector with 3 coefficients
RowVectorXd b {{1.0, 2.0, 3.0, 4.0}};     // A row-vector with 4 coefficients
```

### 系数存取器

## 入门案例

- 头文件

  ```cpp
  #include <Eigen/Dense>
  using namespace Eigen;
  ```

- **MatrixXd**

  Eigen头文件定义了许多类型，所有的类型都在Eigen的命名空间内。

  MatrixXd代表的是任意大小（X*X）的矩阵，并且每个元素为double类型。

  当 `X` 为常数时，MatrixXd 代表 `（X*X）` 的方阵，如：二维方阵：Matrix2d；三维方阵：Matrix3d 等。

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

- **MatrixXd** 中的 X

  ```cpp
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
  ```

  输出

  

- **VectorXd 和 矩阵 运算**

  ```cpp
  void Eigen_introduction_Jx002()
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
  	VectorXd v(3);
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

-  **comma-initializer**

  Eigen提供了一种逗号初始化器语法，该语法使用户可以轻松设置矩阵，向量或数组的所有系数。只需列出系数，从左上角开始，从左到右，从上到下移动。需要预先指定对象的大小。`如果列出的系数太少或太多，编译器就会报错。`
  此外，初始化列表的元素本身可以是向量或矩阵。通常的用途是将向量或矩阵连接在一起。例如，这是如何将两个行向量连接在一起。`请记住，必须先设置大小，然后才能使用逗号初始化程序`。

  ```cpp
  void Eigen_introduction_Jx003()
  {
  	//comma-initializer
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
  ```

  输出

  ```cpp
  vec1 = 1 2 3
  vec2 =  1  4  9 16
  joined =  1  2  3  1  4  9 16
  ```

- 常用的初始化方法

  ```cpp
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
  ```

  输出

  ```cpp
  m0 =
   -0.997497   0.617481  -0.299417
    0.127171   0.170019   0.791925
   -0.613392 -0.0402539    0.64568
  m1 =
  2.4 2.4 2.4
  2.4 2.4 2.4
  2.4 2.4 2.4
  m2 =
  0 0
  0 0
  m3 =
  1 1 1
  1 1 1
  1 1 1
  m4 =
  1 0 0 0
  0 1 0 0
  0 0 1 0
  0 0 0 1
  m5 =
  1 2 3
  4 5 6
  7 8 9
  before:
  1 1 1
  1 1 1
  
  after:
  1 1 1
  2 2 2
  ```

- 调整矩阵大小

  矩阵的当前大小可以通过`rows()`，`cols()`和`size()`检索。这些方法分别返回行数，列数和系数数。

  调整动态大小矩阵的大小是通过`resize()`方法完成的。

  动态矩阵可以随意调整矩阵大小，固定尺寸的矩阵无法调整大小。

  ```cpp
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

- 如何抉择 固定尺寸 和 动态尺寸

  什么时候应该使用固定尺寸（例如Matrix4f），什么时候应该使用动态尺寸（例如MatrixXf）？简单的答案是：在可能的地方使用固定尺寸来显示非常小的尺寸，在需要的地方使用动态尺寸来显示较大的尺寸。对于小尺寸，尤其是对于小于（大约）16的尺寸，使用固定尺寸对性能有极大的好处，因为它使Eigen避免了动态内存分配并展开了循环。

  在内部，固定大小的本征矩阵只是一个简单的数组，即
  Matrix4f mymatrix;
  等同于： float mymatrix[16];
  因此，这确实具有零运行时间成本。

  相比之下，动态大小矩阵的数组始终分配在堆上，因此
  MatrixXf mymatrix(rows,columns);
  等同于： float mymatrix = new float[rowscolumns];

# 矩阵类（The Matrix class）

在Eigen中，所有matrices和vectors都是Matrix模板类的对象。vectors只是matrices的一种特殊情况，具有1行或1列。

## 基础讲解

### Matrix的前三个模板参数

该矩阵类需要六个模板参数，但一般只需了解前三个参数即可。剩下的三个参数具有默认值，现在我们将保持不变，下面将进行讨论。

[关于后面三个参数的详细解释](http://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html#TutorialMatrixOptTemplParams)

Matrix的三个必需模板参数是：
`Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>`

Scalar 是标量类型，即系数的类型。也就是说，如果要使用浮点数矩阵，请在此处选择float。有关所有受支持的标量类型的列表以及如何将支持扩展到新类型的信息，请参见标量类型。
RowsAtCompileTime和ColsAtCompileTime是在编译时已知的矩阵的行数和列数（如果在编译时不知道该数，该怎么办）请参见下文。

我们提供了许多方便的typedef来覆盖通常的情况。

例如，Matrix4f是一个4x4的浮点矩阵。这是Eigen定义的：

`typedef Matrix <float，4，4> Matrix4f;`

Eigen里面用到了很多的typedef简化名称长度，例如下面：

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

### vectors

在Eigen中，vectors只是Matrix的一种特殊情况，具有1行或1列。他们只有1列的情况最为常见；这样的向量称为列向量，通常缩写为向量。在另一行有1行的情况下，它们称为行向量。
`typedef Matrix<float, Dynamic, 1> VectorXf;	//列向量`

`typedef Matrix<float, 1, Dynamic> RowVectorXf;	//行向量`

### 动态矩阵

动态矩阵在编译的时候不知道其大小，需要在运行的时候才能确定其大小。
typedef Matrix <double，Dynamic，Dynamic> MatrixXd;
例如我们可以这样定义一个动态矩阵：

`MatrixXd m(3,4) ;  *// 指定矩阵大小为3X4，也可以不指定*`

### 简单测试

```cpp
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
}
```

输出

```cpp
-9.25596e+61 -9.25596e+61
-9.25596e+61 -9.25596e+61
-9.25596e+61 -9.25596e+61
2 2 2
2 2 2
2 2 2
-4.31602e+08
-4.31602e+08
-4.31602e+08
-4.31602e+08
```

# Array类（The Array class）

## 基础讲解

Eigen 不仅提供了Matrix和Vector结构，还提供了Array结构。区别如下，Matrix和Vector就是线性代数中定义的矩阵和向量，所有的数学运算都和数学上一致。但是存在一个问题是数学上的定义并不一定能完全满足现实需求。比如，数学上并没有定义一个矩阵和一个标量的加法运算。但是如果我们想给一个矩阵的每个元素都加上同一个数，那么这个操作就需要我们自己去实现，这显然并不方便。
Array 提供了一个Array类，为我们提供了大量的矩阵未定义的操作，且Array和Matrix之间很容易相互转换 ，所以相当于给矩阵提供更多的方法。也为使用者的不同需求提供了更多的选择。

### Array的前三个模板参数

下面看一下Array类的实现。Array类和Matrix有相同的参数。

`Array<typename Scalar, int RowsAtCompileTime , int ColsAtCompileTime >`

上面参数的意义和Matrix中参数的意义是相同的。

Array也对常用的情况作了一些类型定义。

```cpp
typedef Array<double,Dynamic ,Dynamic > ArrayXXd;
typedef Array<float ,Dynamic,1> ArrayXf;
typedef Array<int,1,Dynamic> RowArrayXi;

typedef Array<float,3,1> Array3f;
typedef Array<double ,3,3 > Array33d;
······
```

### Array初始化，加减乘除操作

Eigen::Array类重载了+ ， - ，* ,/ 运算符，可以直接用这些运算符对Array对象进行操作。相乘操作是对应的数字相乘，相除是对应的元素相除。

```cpp
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
```

输出

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

### Array其他函数

Array 还定义了 绝对值 abs() ，开平方根sqrt() , 以及找对应元素最小值minCoeff()等操作  ;

```cpp
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
```

输出

```cpp
a =
-1.99499 -1.22678
0.254341  1.23496
a.abs() =
 1.99499  1.22678
0.254341  1.23496
a.sqrt() =
 1.41244   1.1076
0.504323  1.11129
a.minCoeff() =
0.254341
a.maxCoeff() =
1.99499
```

###  Matrix和Array之间的相互转换

Matrix类和Array类之间可以相互转换，必须显式转换，才能对他们进行加减乘除运算。



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

### 选择哪种存储顺序？

那么，您应该在程序中使用哪种存储顺序？这个问题没有简单的答案。这取决于您的应用程序。以下是一些需要牢记的要点：

- 您的用户可能希望您使用特定的存储顺序。或者，您可以使用[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)以外的其他库，并且这些其他库可能需要特定的存储顺序。在这些情况下，在整个程序中使用此存储顺序可能是最简单和最快的。
- 由于更好的数据局部性，当矩阵以行优先顺序存储时，逐行遍历矩阵的算法将运行得更快。类似地，对于列主矩阵，逐列遍历速度更快。进行一些试验以找出对您的特定应用程序来说更快的方法可能是值得的。
- [Eigen 中](http://eigen.tuxfamily.org/dox/namespaceEigen.html)的默认值是列[优先](http://eigen.tuxfamily.org/dox/namespaceEigen.html)。自然，[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)库的大部分开发和测试都是使用列主矩阵完成的。这意味着，即使我们的目标是透明地支持列优先和行[优先](http://eigen.tuxfamily.org/dox/namespaceEigen.html)存储顺序，[Eigen](http://eigen.tuxfamily.org/dox/namespaceEigen.html)库也可能最适合列优先矩阵。