# WPF 简介

Windows系统平台上 GUI 程序员的开发工具经历了 Win32 API -> MFC -> ActiveX/COM/Visual Basic -> Windows Forms

2007年开始，微软推出了新一代GUI开发工具 **Windows Presentation Foundation** （直译为 Windows呈现基础，WPF）。

https://learn.microsoft.com/zh-cn/previous-versions/dotnet/netframework-4.0/

## 控件分类

**布局控件：** `Panel`

**内容控件：** `ContentControl` 只能容纳一个控件或布局控件

**带标题内容控件：** 可以设置标题 `Header` 父类：`HeaderedContentControl`

**条目控件：** 可以显示一列数据，数据类型一般相同 `ItemControl`

**带标题的条目控件：** 条目控件可以设置标题 `Header` 父类：`HeaderedItemControl`

**特殊内容控件：** 常用的空间：`TextBox` 、`PasswordBox` 、`TextBlock`

# VS WPF .NET Framework 项目文件介绍

## 分支

- **Properties**

  里面的主要内容是程序要用到的一些资源（如图标、图片、静态的字符串）和 配置信息。

- **Reference**

  标记了当前这个项目需要引用哪些其他的项目。

  初始的项目里面罗列的都是 .NET Framework 中的类库，有时候还要添加其他 .NET Framework 类库或其他程序员编写的项目及类库。

- **app.config**

  配置文件 连接字符串 配置信息

- **App.xaml**

  程序的主体。

  Windows系统中，一个程序就是一个进程（Process）；一个GUI进程需要有一个窗口（Window）作为 "主窗口"。

  App.xaml 文件的作用就是声明了程序的进程会是谁，同时指定了程序的主窗体是谁。

  App.xaml.cs 是 App.xaml 的后台代码。

- **MainWindow.xaml**

  程序的主窗体。

## App.xaml

`StartupUri="MainWindow.xaml"` 指定起始文件。

`<Application.Resources>` 定义整个WPF应用程序的相关资源。

一个 XAML 文件至少要有两个命名空间：

- 默认命名空间
- 其他命名空间：一般还会有一个带x前缀命名空间

## 剖析最简单的XAML代码

```xaml
<Window x:Class="_02_CSharp_WPF_NET_Framework.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:_02_CSharp_WPF_NET_Framework"
        mc:Ignorable="d"
        Title="MainWindow" Height="450" Width="800">
    <Grid>
        
    </Grid>
</Window>
```

总体结构：

Windows 标签中包含了一个 Grid 标签。

```xaml
<Window>
    <Grid>
        
    </Grid>
</Window>
```

使用名为Class的Attribute

```xaml
x:Class="_02_CSharp_WPF_NET_Framework.MainWindow"
```

声明命名空间

```xaml
xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
xmlns:local="clr-namespace:_02_CSharp_WPF_NET_Framework"
```

xmlns: XML-Namespace，定义命名空间的好处就是，当来源不同的类重名时，可以使用名称加空间加以区分。

语法：`xmlns[:可选的映射前缀]="名称空间"`

`xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"` 没有前缀的命名空间称为 “默认名称空间”，只能有一个。

Window 和 Grid 都来自默认的命名空间， Class 来自 x 前缀对应的名称空间。

如果改掉默认命名空间，则需要改变对应的标签才能通过编译：

```xaml
<n:Window x:Class="_02_CSharp_WPF_NET_Framework.MainWindow"
        xmlns:n="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:_02_CSharp_WPF_NET_Framework"
        mc:Ignorable="d"
        Title="MainWindow" Height="450" Width="800">
    <n:Grid>
        
    </n:Grid>
</n:Window>
```

# XAML

**XAML** 是微软为构建应用程序用户界面而创建的一种新的“可扩展应用程序标记语言”。提供一种便于扩展和定位的语法来定义和程序业务逻辑分离的用户界面。

## 导入程序集和引用其中的名称空间

在XAML中引用名称空间的语法是：

`xmlns:映射名="clr-namesapce:类库中名称空间的名字;assembly=类库文件名"`

# x 命名空间详解

大凡包含 XAML 代码的 WPF 程序都需要通过语句 `xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"` 来引入 `http://schemas.microsoft.com/winfx/2006/xaml` 这个名称空间

## x 名称空间的内容

x名称空间中的工具在 XAML 中出现的形式大致分为三种： Attribute、标记扩展和 XAML 指令元素三类。

## x 名称空间中的 Attribute

### x:Class

这个 Attribute 的作用是告诉 XAML 编译器将 XAML 标签的编译结果与后台代码中指定的类合并。在使用 x:Class 时必须遵循以下要求:

- **这个 Attribute 只能用于根结点。**
- **使用 x:Class 的根结点的类型要与 x:Class 的值所指示的类型保持一致。**
- x:Class的值所指示的类型在声明时必须使用partial关键字。

### x:Name

x:Name 可以让编译器声明引用变量的同时，为实例的Name属性赋值。

Name属性定义在 FrameworkElement 中，这个类是WPF控件的基类，所以所有 WPF 控件都具有 Name 这个属性。所以对于 WPF 控件来说， 使用 Name 或 x:Name 是完全等效的，但是对于没有 Name 属性的元素，就只能用 x:Name 了。

为了增强代码的统一性和可读性，一般全部使用 x:Name。

### x:Key

在WPF中，几乎每个元素都有自己的 Resources 属性。

x:Key 就可以在 Resources 中定义 key，然后使用时直接获取其 value。

```xaml
<Window x:Class="_02_CSharp_WPF_NET_Framework.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:_02_CSharp_WPF_NET_Framework"
        xmlns:sys="clr-namespace:System;assembly=mscorlib"
        mc:Ignorable="d"
        Title="MainWindow" Height="160" Width="200">
    <Window.Resources>
        <sys:String x:Key="myString">Hello WPF Resource!</sys:String>
    </Window.Resources>
    <StackPanel Background="Gray">
        <TextBox Text="{StaticResource ResourceKey=myString}" Margin="5"/>
    </StackPanel>
</Window>
```

在C#中也能访问Resource资源：

```xaml
<StackPanel Background="Gray">
    <TextBox Text="{StaticResource ResourceKey=myString}" Margin="5"/>
    <Button Content="Show" Click="Button_Click"/>
    <TextBox x:Name="textBox1" Margin="5"/>
</StackPanel>
```

```c#
private void Button_Click(object sender, RoutedEventArgs e)
{
    string str = this.FindResource("myString") as string;
    this.textBox1.Text = str;
}
```

## x 名称空间中的扩展标记

# Binding

## 控制 Binding 的方向及数据更新

Binding 在源与目标之间架起了沟通的桥梁，默认情况下数据既能通过 Binding 送达目标，也能够从目标返回源（收集用户对数据的修改）。

- **Mode**

  控制 Binding 数据流向的属性是 Mode，它的类型是 BindingMode 枚举。

  枚举取值为：TwoWay、OneWay、OnTime、OneWayToSource 和 Default。

  Default 这里指的是 Binding 的模式会根据目标的实际情况来确定：比如是可编辑的（如 TextBox.Text 属性），Default 就采用双向模式；若是只读的（如 TextBlock.Text）则采用单向模式。

- **UpdateSourceTrigger**

  类型是 UpdateSourceTrigger 枚举。

  枚举取值为：PropertyChanged、LostFocus、Explicit 和 Default。

  显然，TextBox 默认 Default 的行为与 LostFocus 一致。

# Window 窗口

WPF的主界面

[Window类](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.window?redirectedfrom=MSDN&view=windowsdesktop-7.0)

**Window 继承自 ContentControl 因此里面只能有一个 Content**： 所以一般在window里面创建一个StackPanel、Grid 等布局控件来容纳其他控件。

## 注解

用户与独立应用程序之间的交互点是一个窗口。 Windows Presentation Foundation (WPF) 窗口由两个不同的区域组成：

- 非工作区，用于托管窗口装饰，包括图标、标题、系统菜单、最小化按钮、最大化按钮、还原按钮、关闭按钮和边框。
- 一个工作区，用于托管特定于应用程序的内容。

下图显示了一个标准窗口：

![](https://learn.microsoft.com/zh-cn/dotnet/media/windowoverviewfigure1.png?view=windowsdesktop-7.0)

## 属性

**ShowInTaskbar** ：任务栏是否显示此窗口，默认为 True。

**WindowStartupLocation** ： window启动出现的位置。

- CenterScreen：当前屏幕中央
- Manual： 默认，手动设置。

**WindowState**： 窗口状态

**Topmost** : 是否一直处于最顶层

**Icon** : 图标设置

## C# 对象

`using System.Windows;`

**SystemParameters.MaximizedPrimaryScreenWidth** : 最大屏幕可用宽度

**SystemParameters.MaximizedPrimaryScreenHeight** ：最大屏幕可用高度（不包含任务栏）

**SystemParameters.WorkArea** : 工作区是系统任务栏或应用程序桌面工具栏未遮盖的屏幕部分。

- 返回 **Rect** 对象（`<Rect X="10" Y="100" Width="150" Height="100" />`）

## C# 方法

**ShowDialog**：窗体显示为模式窗体，逻辑代码会暂停，窗口关闭后，再继续执行后续代码。

**Show** ：窗体窗口显示为无模式窗口，直到关闭对话框后，才执行后面的代码。

# 布局控件

可以容纳多个控件或嵌套其他布局控件，用于在UI上组织和排列控件。

有 **Grid、StackPanel、DockPanel** 等控件，他们拥有共同的父类 **Panel**。

## 布局的基本原则

- 一个窗口中只能包含一个元素

- 不应使用坐标设置元素的位置

- 大多数情况不应显示定义元素尺寸

- 支持多元素时, 可使用嵌套容器

## Grid

### 属性

**宽高**：

![image.png](https://s2.loli.net/2023/02/24/kZ5jiHyrUDuEQmS.png)

Auto 表示自动适应显示内容的宽度, 如自动适应文本的宽度,文本有多长,控件就显示多长.

# 内容控件

只能容纳一个其他控件或布局控件作为它的内容。

有 **Window、Button** 等控件，他们拥有共同的父类 **ContentControl** 。

## Button

### 属性

**Content**： Button显示的内容

**IsDefault** ：True/False 窗体的确认默认按钮，可以敲击回车键来触发

**IsCancel** ：True/False 窗体的取消默认按钮，可以敲击ESC键来触发

## RadioButton

### 属性

**GroupName** ： 设置组名，同组成员互斥。

### 事件

**Checked** : 勾选时触发事件

## CheckBox

**IsThreeState** ： True/False 允许出现第三种状态

# 带标题内容控件

相当于一个内容控件，但可以加一个标题（**Header**），标题部分亦可容纳一个控件或布局。

有 **GroupBox、TabItem** 等，共同父类是 **HeaderedContentControl** 。

# 条目控件

可以显示一列数据，一般情况下这列数据的类型相同。

有 **ListBox、ComboBox** 等，共同父类是 **ItemControl**。

# 带标题条目控件

相当于一个条目控件加上一个标题显示区。

有 **TreeViewItem、MenuItem** 等，共同父类是 **HeaderedItemsControl**

这类控件往往用于显示层级关系数据，节点显示在其 **Header** 区域。

# 特殊内容控件

**TextBox** 容纳的是字符串；

**TextBlock** 可以容纳可自由控制格式的文本；

**Image** 容纳图片类型数据。

## Label

# RelativeSource 属性

我们进行Bingding时，如果明确知道数据源的Name，就能用Source或者ElementName进行绑定，但是有时候我们需要绑定的数据源可能没有明确的Name，此时我们就需要利用Bingding的RelativeSource进行绑定，这种办法的意思是指当前元素和绑定源的位置关系。

（1）控件关联自身的属性——Self

`CommandParameter="{Binding RelativeSource={x:Static RelativeSource.Self}}"`

# VS 代码片段

## 自带代码片段

- **ctor** ： 构造函数代码片段
- **propfull** : 完整属性代码片段

# 插件

## WPF开源UI控件库MaterialDesign

http://materialdesigninxaml.net/

[Super Quick Start](https://github.com/MaterialDesignInXAML/MaterialDesignInXamlToolkit/wiki/Super-Quick-Start)

