

# memset

memset是一个初始化函数，作用是将某一块内存中的全部设置为指定的值。

```cpp
void *memset(void *s, int c, size_t n); 
```

- s指向要填充的内存块。
- c是要被设置的值。
- n是要被设置该值的**字符数**。
- 返回类型是一个指向存储区s的指针。

## memset 初始化的方式

memset函数是按照**字节**对内存块进行初始化，所以不能用它将int数组初始化为0和-1之外的其他值（除非该值高字节和低字节相同）。
其实c的实际范围应该在0~255，因为memset函数只能**取c的后八位**给所输入范围的每个字节。也就是说**无论c多大只有后八位二进制是有效的**。

对于int a[4];
memset(a, -1, sizeof(a)) 与 memset(a, 511, sizeof(a)) 所赋值的结果一样都为-1：
因为 -1 的二进制码为（11111111 11111111 11111111 11111111）；511 的二进制码为（00000000 00000000 00000001 11111111）；
后八位均为（11111111），所以数组中的每个字节都被赋值为（11111111）。
注意int占四个字节，例如a[0]的四个字节都被赋值为（11111111），那么a[0]（11111111 11111111 11111111 11111111），即a[0] = -1。

## 注意所要赋值的数组的元素类型

**例一：对char类型的数组a初始化，设置元素全为’1’**

```cpp
int main(){
    char a[4];
    memset(a,'1',4);
    for(int i=0; i<4; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
```

> 输出： 1 1 1 1

**例二：对int类型的数组a初始化，设置元素值全为1**

```cpp
int main(){
    int a[4];
    memset(a,1,sizeof(a));
    for(int i=0; i<4; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
```

> 输出：16843009 16843009 16843009 16843009

如果长度写成了4:  `memset(a,1,4);`

就会发生下述情况 

>  输出：16843009 0 0 0 

由于memset函数是以字节为单位进行赋值的，所以上述代码是**为数组a的前4个字节进行赋值**

- **为什么第一个程序可以正确赋值1而第二个不可以？**

这就又回到了刚刚说的第一个问题，memset函数中只能取c的后八位赋给每个字节。

第一个程序中，数组a是字符型的，字符型占据的内存大小就是1Byte，而memset函数也是以字节为单位进行赋值的，所以输出正确。
第二个程序中，数组a是整型的，整型占据的内存大小为4Byte，而memset函数还是按照字节为单位进行赋值，将1（00000001）赋给每一个字节。那么对于a[0]来说，其值为(00000001 00000001 00000001 00000001），即十进制的16843009。

## 实际开发可能遇到的问题

### 数组指针

```cpp
#include<bits/stdc++.h>
using namespace std;

void fun1(int a[]){
    memset(a,-1,sizeof(a)); 
}

int main(){
    int a[6];
    fun1(a);
    for(int i=0; i<6; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
```

当数组作为参数传递时，其**传递的实际上是一个指针**，这个指针指向数组的首地址，如果用**sizeof(a)函数得到的只是指针的长度**，而不是数组的长度。

解决方案：在函数中加入数组长度参数，在传递前先获取数组长度，然后将数组长度作为参数传递进去。

```cpp
#include<bits/stdc++.h>
using namespace std;

void fun1(int a[], int len){
    memset(a,-1,len); 
}

int main(){
    int a[6];
    int len = sizeof(a);
    fun1(a,len);
    for(int i=0; i<6; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
```

## ZeroMemory与memset区别 
　　ZeroMemory是微软的SDK提供的，memset属于C Run-time Library,所以ZeroMemory只能用于Windows系统，memset可用于别的系统。 
　　ZeroMemory是一个宏，只是用于把一段内存的内容置零，内部是用memset实现的，memset可将内存置成别的字符。 
　　如果你的程序是Win32程序而且不想连接c运行时库，那就用ZeroMemory，如果需要跨平台，那就用memset。

## 常用场景

- 初始化数组

```cpp
char str[100];
memset(str,0,100);

char str[100];
memset(str,'\0',100);
```

- 清空结构体类型的变量

```cpp
typedef struct Stu{
	char name[20];
	int cno;
}Stu;
Stu stu1; 
memset(&stu1, 0 ,sizeof(Stu));

Stu stu2[10]; //数组
memset(stu2, 0, sizeof(Stu)*10);
```

此外，如果结构体中有数组的话还是需要对数组单独进行初始化处理的。

# Path 相关

## _access

Linux下，该函数为access，位于头文件<unistd.h>中，而在标准C++中，该函数为_access，位于头文件<io.h>中，两者的使用方法基本相同，只是在一些参数方面可能会有一些不同的宏定义。

### C++

**头文件**：<io.h>

**函数原型**：int _access(const char *pathname, int mode);

**参数**：

- pathname 为文件路径或目录路径 

- mode 为访问权限（在不同系统中可能用不能的宏定义重新定义）

  00——只检查文件是否存在

  02——写权限

  04——读权限

  06——读写权限

**返回值**：如果文件具有指定的访问权限，则函数返回0；如果文件不存在或者不能访问指定的权限，则返回-1.

**备注**：当pathname为文件时，\_access函数判断文件是否存在，并判断文件是否可以用mode值指定的模式进行访问。当pathname为目录时，\_access只判断指定目录是否存在，在Windows NT和Windows 2000中，所有的目录都只有读写权限。

## _getcwd

`#include <direct.h>`

```cpp
getcwd(path,sizeof(path));
```

这样会将工作目录的绝对路径复制到buff所指向的空间中,但如果路径长度大于size,则会返回NULL,错误代码为ERANGE.所以我们在定义path的时候得定义的足够大,但这样又会使得内存浪费,Linux的文件名长度限制为255个英文字符,理论上绝对路径的大小应该可以足够大,故而这样使用总有返回NULL的时候,所以getcwd()个我们提供了下面的一种用法:

```cpp
char *path = NULL;
path = getcwd(NULL,0);
puts(path);
free(path);
```

可以采取令 buf 为 NULL并使 size 为零(百度百科里介绍可以使用负值但我测试的时候是段错误)来使 getcwd 调用 malloc 动态给 buf 分配,但是这种情况要特别注意使用后释放缓冲以防止内存泄漏

## GetModuleFileName

`#include <Windows.h>`

![image-20230403104748424](https://s2.loli.net/2023/04/03/VkHAYI1o2zMRJtX.png)

```cpp
#ifdef UNICODE
#define GetModuleFileName  GetModuleFileNameW
#else
#define GetModuleFileName  GetModuleFileNameA
#endif // !UNICODE
```

如果字符集选择为 **多字节字符集** ，就会调用 `GetModuleFileNameA` ；选择 **Unicode 字符集**，就会调用 `GetModuleFileNameW`

### 参数

```cpp
WINBASEAPI
DWORD
WINAPI
GetModuleFileNameA(
    __in_opt HMODULE hModule,
    __out_ecount_part(nSize, return + 1) LPCH lpFilename,
    __in    DWORD nSize
    );
WINBASEAPI
DWORD
WINAPI
GetModuleFileNameW(
    __in_opt HMODULE hModule,
    __out_ecount_part(nSize, return + 1) LPWCH lpFilename,
    __in    DWORD nSize
    );
#ifdef UNICODE
#define GetModuleFileName GetModuleFileNameW
#else
#define GetModuleFileName GetModuleFileNameA
#endif // !UNICODE
```

- 参数

  **hModule** ：模块的句柄，或者设置为NULL表示当前模块（当前进程）。
  **lpFilename** : 保存路径的缓冲区。
  **nSize** : 缓冲区的大小。

- 返回值

  如果函数运行成功，返回值为字符串的长度。如果字符串的长度大于nSize字节，返回值为nSize。如果函数运行失败，返回值为0。

## _mkdir

`#include <direct.h>`

`int __cdecl _mkdir(_In_z_ char const* _Path);`