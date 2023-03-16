# WPF 简介

Windows系统平台上 GUI 程序员的开发工具经历了 Win32 API -> MFC -> ActiveX/COM/Visual Basic -> Windows Forms

2007年开始，微软推出了新一代GUI开发工具 **Windows Presentation Foundation** （直译为 Windows呈现基础，WPF）。

https://learn.microsoft.com/zh-cn/previous-versions/dotnet/netframework-4.0/

## 相关资料

[入门教程-博客园](https://www.cnblogs.com/zh7791/category/1528742.html)

## 控件分类

**布局控件：** `Panel`

**内容控件：** `ContentControl` 只能容纳一个控件或布局控件

**带标题内容控件：** 可以设置标题 `Header` 父类：`HeaderedContentControl`

**条目控件：** 可以显示一列数据，数据类型一般相同 `ItemControl`

**带标题的条目控件：** 条目控件可以设置标题 `Header` 父类：`HeaderedItemControl`

**特殊内容控件：** 常用的空间：`TextBox` 、`PasswordBox` 、`TextBlock`

# [WPF 中的树](https://learn.microsoft.com/zh-cn/dotnet/desktop/wpf/advanced/trees-in-wpf?view=netframeworkdesktop-4.8)

 WPF 中有两中“树”：一种叫逻辑树（**Logical Tree**）;一种叫可视化元素树（**Visual Tree**）。

## 逻辑树 和 LogicalTreeHelper

逻辑树在 WPF 框架级别定义。这意味着，与逻辑树操作关系最密切的 WPF 基元素是 [FrameworkElement](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement) 或 [FrameworkContentElement](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement)。 但是你会发现，如果实际使用 [LogicalTreeHelper](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper) API，则逻辑树有时会包含既不是 [FrameworkElement](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkelement)，也不是 [FrameworkContentElement](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.frameworkcontentelement) 的节点。 例如，逻辑树会报告 [TextBlock](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock) 的 [Text](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.controls.textblock.text) 值，该值是一个字符串。

| 方法                                                         | 介绍                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [BringIntoView](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.logicaltreehelper.bringintoview?view=netframework-4.7.2#System_Windows_LogicalTreeHelper_BringIntoView_System_Windows_DependencyObject_) | 尝试将请求的用户界面元素放入视图                             |
| FindLogicalNode                                              | 尝试查找并返回具有指定的名称的对象。 搜索从指定的对象开始，并持续到逻辑树的子节点。 |
| GetChildren                                                  | 通过处理逻辑树返回指定的对象的即时子对象集合。               |
| GetParent                                                    | 通过处理逻辑树中返回指定对象的父对象。                       |

## 可视化树 和 VisualTreeHelper 

| 方法                                                         | 介绍                                             |
| ------------------------------------------------------------ | ------------------------------------------------ |
| [GetChild](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.getchild?view=netframework-4.7.2#System_Windows_Media_VisualTreeHelper_GetChild_System_Windows_DependencyObject_System_Int32_) | 返回子可视对象从指定的父级范围内指定的集合索引。 |
| [GetChildrenCount](https://docs.microsoft.com/zh-cn/dotnet/api/system.windows.media.visualtreehelper.getchildrencount?view=netframework-4.7.2#System_Windows_Media_VisualTreeHelper_GetChildrenCount_System_Windows_DependencyObject_) | 返回的包含指定的可视对象的子级的个数。           |

## 测试和说明

```xaml
<Window x:Class="WpfAppResource1.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:WpfAppResource1" xmlns:system="clr-namespace:System;assembly=mscorlib" 
        mc:Ignorable="d" Loaded="Window_Loaded"
        Title="MainWindow" Height="450" Width="800">
    <Grid x:Name="grid">
        <TextBox x:Name="textBox">
            <TextBox.Template>
                <ControlTemplate TargetType="TextBox">
                    <Rectangle x:Name="rectangle"/>
                </ControlTemplate>
            </TextBox.Template>
        </TextBox>
 
        <StackPanel x:Name="stackPanel">
            <Button x:Name="button" >
                <CheckBox x:Name="checkBox"/>
            </Button>
        </StackPanel>
 
        <DockPanel x:Name="dockPanel">
            <ToggleButton x:Name="toggleButton">
                <TextBlock x:Name="textBlock"/>
            </ToggleButton>
        </DockPanel>
 
        <Border x:Name="border">
            <RepeatButton x:Name="repeatButton"/>
        </Border>
    </Grid>
</Window>
```

```c#
namespace WpfAppResource1
{
    using System.Text;
    using System.Windows;
    using System.Windows.Media;
 
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
 
        public MainWindow()
        {
            InitializeComponent();
        }
 
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
        }
 
        string getTree(FrameworkElement container)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("********Logical Tree********");
            getLogicalChildren(container, sb, 0);
            sb.AppendLine();
 
            sb.AppendLine("********Visual Tree********");
            getVisualChildren(container, sb, 0);
            sb.AppendLine();
 
            return sb.ToString();
        }
 
        void appendLine(FrameworkElement frameworkElement, StringBuilder sb, int num)
        {
            sb.Append("".PadLeft(num));
            string name = frameworkElement.Name;
            if (string.IsNullOrWhiteSpace(name))
            {
                name = $"({frameworkElement.GetType().Name})";
            }
            sb.AppendLine($"{num}.{name}");
        }
 
        void getLogicalChildren(FrameworkElement container, StringBuilder sb, int num)
        {
            appendLine(container, sb, num);
            foreach (var child in LogicalTreeHelper.GetChildren(container))
            {
                FrameworkElement frameworkElement = child as FrameworkElement;
                if (frameworkElement != null)
                {
                    getLogicalChildren(frameworkElement, sb, num + 1);
                }
            }
        }
 
        void getVisualChildren(FrameworkElement container, StringBuilder sb, int num)
        {
            appendLine(container, sb, num);
            int count = VisualTreeHelper.GetChildrenCount(container);
            for (int i = 0; i < count; i++)
            {
                FrameworkElement frameworkElement = VisualTreeHelper.GetChild(container, i) as FrameworkElement;
                if (frameworkElement != null)
                {
                    getVisualChildren(frameworkElement, sb, num + 1);
                }
            }
        }
 
    }
}
```

构造函数里遍历两个树(Window)

```c#
public MainWindow()
{
    InitializeComponent();
    string tree = getTree(this);
}
```

```c#
********Logical Tree********
0.(MainWindow)
 1.grid
  2.textBox
  2.stackPanel
   3.button
    4.checkBox
  2.dockPanel
   3.toggleButton
    4.textBlock
  2.border
   3.repeatButton
 
 
********Visual Tree********
0.(MainWindow)
```

构造函数里遍历两个树(Grid)

```c#
 public MainWindow()
 {
     InitializeComponent();
     string tree = getTree(this.grid);
 }
```

```c#
********Logical Tree********
0.grid
 1.textBox
 1.stackPanel
  2.button
   3.checkBox
 1.dockPanel
  2.toggleButton
   3.textBlock
 1.border
  2.repeatButton
 
 
********Visual Tree********
0.grid
 1.textBox
 1.stackPanel
  2.button
 1.dockPanel
  2.toggleButton
 1.border
  2.repeatButton
```

Loaded完成后遍历两个树

```c#
 private void Window_Loaded(object sender, RoutedEventArgs e)
 {
     string tree = getTree(this);
 }
```

```c#
********Logical Tree********
0.(MainWindow)
 1.grid
  2.textBox
  2.stackPanel
   3.button
    4.checkBox
  2.dockPanel
   3.toggleButton
    4.textBlock
  2.border
   3.repeatButton
 
 
********Visual Tree********
0.(MainWindow)
 1.(Border)
  2.(AdornerDecorator)
   3.(ContentPresenter)
    4.grid
     5.textBox
      6.rectangle
     5.stackPanel
      6.button
       7.border
        8.contentPresenter
         9.checkBox
          10.templateRoot
           11.checkBoxBorder
            12.markGrid
             13.optionMark
             13.indeterminateMark
           11.contentPresenter
     5.dockPanel
      6.toggleButton
       7.border
        8.contentPresenter
         9.textBlock
     5.border
      6.repeatButton
       7.border
        8.contentPresenter
   3.(AdornerLayer)
```

 通过对比可以发现：

- 逻辑树只能遍历出非模板的元素，可视化树可以遍历出所有属于Visual的元素
- 可视化树在界面未加载前不能遍历Window，但可以遍历Window中的元素
- 逻辑树的遍历在整个过程都可以的，而可视化树在界面没有加载显示完成后不能遍历出Content中和Template中的元素

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

  程序的主体。**设置应用程序起始文件与系统级资源**

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

**xmlns: XML-Namespace，定义命名空间的好处就是，当来源不同的类重名时，可以使用名称加空间加以区分。**

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

xmal 的命名空间与.NET中的命名空间不是一一对应的，而是一对多的。

`xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"` ： 默认命名空间（所有wpf类，包括构建用户界面使用的控件）

`xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"` : 对应一些与XAML语法和编译相关的 **CLR名称空间**

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

# 事件

## 附加事件

元素可以响应由 XAML 树中的其他元素引发的事件，即使元素本身并不定义这些事件也可以。 例如，包含 [Button](https://msdn.microsoft.com/zh-cn/library/ms609089(v=vs.100)) 控件的 [Window](https://msdn.microsoft.com/zh-cn/library/ms590112(v=vs.100)) 可以响应由该 [Button](https://msdn.microsoft.com/zh-cn/library/ms609089(v=vs.100)) 引发的 [Click](https://msdn.microsoft.com/zh-cn/library/ms521565(v=vs.100)) 事件，即使 [Window](https://msdn.microsoft.com/zh-cn/library/ms590112(v=vs.100)) 本身并不定义 [Click](https://msdn.microsoft.com/zh-cn/library/ms521565(v=vs.100)) 事件也可以。 这是通过在 [Window](https://msdn.microsoft.com/zh-cn/library/ms590112(v=vs.100)) 定义中为 Button.Click（或 ButtonBase.Click）事件指定处理程序来实现的。 每当该窗口 XAML 树中的 [Button](https://msdn.microsoft.com/zh-cn/library/ms609089(v=vs.100))（或从 [ButtonBase](https://msdn.microsoft.com/zh-cn/library/ms611651(v=vs.100)) 继承的任何控件）被单击时，都将执行此处理程序。 下面的过程和示例演示如何使用附加事件。

```xaml
<Window x:Class="_02_CSharp_WPF_NET_Framework.View.ContenControlClan"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:_02_CSharp_WPF_NET_Framework.View"
        mc:Ignorable="d"
        Title="ContenControlClan" Height="450" Width="800"
        ButtonBase.Click="Button_Click">
```

此 Window 下的所有 Button 都会响应 Button_Click 事件，但是**响应对象均是 ContenControlClan 本身。**

# Binding

[wpf数据绑定](https://learn.microsoft.com/zh-cn/dotnet/desktop/wpf/data/?view=netdesktop-7.0&viewFallbackFrom=netdesktop-5.0)

## 原始的 Binding 方式

```c#
public class Student : INotifyPropertyChanged
{
    public event PropertyChangedEventHandler PropertyChanged;

    private string _Name;

    public string m_Name
    {
        get { return _Name; }
        set
        {
            _Name = value;

            //if (this.PropertyChanged != null)
            //{
            //    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("m_Name"));
            //}

            //简化
            this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("m_Name"));
        }
    }

}

// ...
    
public void TheOriginalBindingMode()
{
    this._stu = new Student();

    Binding binding = new Binding();
    binding.Source = this._stu;
    binding.Path = new PropertyPath("m_Name");

    BindingOperations.SetBinding(this.textBoxName, TextBox.TextProperty, binding);
}

// 简写（因为Binding构造器有默认Path参数）
public void TheOriginalBindingMode()
{
    this._stu = new Student();

    Binding binding = new Binding("m_Name") {Source=this._stu};
    BindingOperations.SetBinding(this.textBoxName, TextBox.TextProperty, binding);
}
```

## Binding的源和路径

```xaml
<TextBox Width="40" Margin="5" Text="{Binding Path=Text, ElementName=textNum1}" IsEnabled="False"/>
```

这一句使用了 Binding 语法，因为 Binding 类的构造器本身可以接收 Path 作为参数，所以会有这种简写方法：

```xaml
<TextBox Width="40" Margin="5" Text="{Binding Text, ElementName=textNum1}" IsEnabled="False"/>
```

### 把控件作为 Binding 的源

```xaml
<TextBlock Text="Num1" Margin="5"/>
<TextBox x:Name="textNum1" Width="40" Margin="5"/>
<TextBlock Text="Num2" Margin="5"/>
<TextBox Width="40" Margin="5" Text="{Binding Path=Text, ElementName=textNum1}" IsEnabled="False"/>
```

### 控制 Binding 的方向及数据更新

Binding 在源与目标之间架起了沟通的桥梁，默认情况下数据既能通过 Binding 送达目标，也能够从目标返回源（收集用户对数据的修改）。

- **Mode**

  控制 Binding 数据流向的属性是 Mode，它的类型是 BindingMode 枚举。

  枚举取值为：TwoWay、OneWay、OnTime、OneWayToSource 和 Default。

  Default 这里指的是 Binding 的模式会根据目标的实际情况来确定：比如是可编辑的（如 TextBox.Text 属性），Default 就采用双向模式；若是只读的（如 TextBlock.Text）则采用单向模式。

  **OneWay:**

  textNum1 变化时，textNum2 实时变化；textNum2变化时，textNum1不变化。

  可以理解为，自身随着绑定的源变化，但并不能改变源。

  ```xaml
  <TextBox x:Name="textNum1" Width="40" Margin="5"/>
  <TextBox x:Name="textNum2" Width="40" Margin="5" Text="{Binding Path=Text, ElementName=textNum1, UpdateSourceTrigger=PropertyChanged, Mode=OneWay}"/>
  ```

  **OneWayToSource:**

  textNum1 变化时，textNum2 不变化；textNum2变化时，textNum1实时变化。

  可以理解为，自身能改变源，但是源不能影响自己。

  ```xaml
  <TextBox x:Name="textNum1" Width="40" Margin="5"/>
  <TextBox x:Name="textNum2" Width="40" Margin="5" Text="{Binding Path=Text, ElementName=textNum1, UpdateSourceTrigger=PropertyChanged, Mode=OneWay}"/>
  ```

- **UpdateSourceTrigger**

  类型是 UpdateSourceTrigger 枚举。

  枚举取值为：PropertyChanged、LostFocus、Explicit 和 Default。

  显然，TextBox 默认 Default 的行为与 LostFocus 一致。
  
  - **PropertyChanged** ：实时更新
  
- **NotifyOnSourceUpdated** 、**NotifyOnTargetUpdated** 

  如果设为 true，则当源或目标被更新后 Binding 会激发相应的 `SourceUpdated` 和 `TargetUpdated` 事件。

  实际工作中，可以通过监听这两个事件找出有哪些数据或控件被更新了。

### Binding 的路径

Bing的路径支持多级路径，即 `Text="{Binding Path=Text.Length, ElementName=textBox1}"`

---

对于集合类型，集合类型的索引器（Indexer）又称为带参属性。既然是属性，那么索引器也能作为Path使用。

首先用 DataContext 可以为控件设置数据源：

```c#
public List<string> labelArray = new List<string> { "label1", "label2", "label3" };
//...
	this.CollectionPanel.DataContext = this.labelArray;
```

```xaml
<StackPanel Orientation="Horizontal" x:Name="CollectionPanel">
    <TextBlock Text="{Binding [0]}" Margin="5"/>
</StackPanel>
```

1. 直接使用索引

   `Property.[index]` ，简写 `Property[index]`

   ```xaml
   <TextBlock Text="{Binding [0]}" Margin="5"/>
   ```

   显示：`label1`

2. 可以多级索引

   ```xaml
   <TextBlock Text="{Binding [1][5]}" Margin="5"/>
   ```

   显示：`2`

3. 默认元素作为 Path 使用

   ```xaml
   <TextBlock Text="{Binding /}" Margin="5"/>
   <TextBlock Text="{Binding /Length}" Margin="5"/>
   <TextBlock Text="{Binding /[5]}" Margin="5"/>
   ```

   显示：`label1` 和  `6` 和 `1`

4. 直接写Path就是调用自身属性

   ```xaml
   <TextBlock Text="{Binding Count}" Margin="5"/>
   ```

   显示：`3`

5. 没有 “PATH” 的 Binding

   其实就是调用 Binding 源本身，因为 Binding 源本身就是数据，所以不需要 Path 来指明属性。

   正规写法是 `Path=.` ，在 xaml 中可以省略，但是 C# 中不能省略。

   类似于：

   ```xaml
   Text="{Binding ., Source={StaticResource ResourceKey=myString}}"
   ```

   可以简写成

   ```xaml
   Text="{Binding Source={StaticResource ResourceKey=myString}}"
   ```

### 为 Binding 指定源（Source）的几种方法

- 把容器的 DataContext 指定为 Source（WPF Data Binding 的默认行为）

  有时候会遇到这样的情况，明确知道将从哪个 **属性** 获取数据，但具体把哪个对象作为 Binding 源还不知道。这时候，只能先建立一个 Binding，只设置 Path 而不设置 Source，让这个 Binding 自己去寻找 Source。这时候，Binding 会自动把控件的 DataContext 当作自己的 Source（沿着控件树一层一层向外找，直到找到带有 Path 指定属性的对象为止）

### 使用集合对象作为列表控件的 ItemsSource

**注意：**在使用集合类型作为列表控件的 ItemsSource 时一般会考虑使用 ObservableCollection\<T> 代替 List\<T>，因为ObservableCollection\<T> 实现了 INotifyCollectionChanged 和 INotifyPropertyChanged 接口，能把集合的变化立刻通知显示她它的列表控件，改变实时显示。

### 使用 Binding 的 RelativeSource

- **RelativeSourceMode**：枚举：

  - **FindAncestor** : 在UI结构树上找寻祖先元素

    ```xaml
    <TextBlock Text="{Binding Name, RelativeSource={RelativeSource Mode=FindAncestor, AncestorType={x:Type StackPanel}}}" Margin="5" x:Name=textBlock/>
    ```

    C# 代码：

    ```c#
    RelativeResource rs = new RelativeResource(RelativeSourceMode.FindAncestor);
    rs.AncestorLevel = 1;
    rs.AncestorType = typeof(StackPanel);
    Binding binding = new Binding("Name"){ RelativeSource = rs };
    this.textBlock.SetBinding(TextBlock.TextProperty, binding);
    ```

    其中：

    **AncestorLevel**：以 Binding 目标控件为起点的层级偏移量

    **AncestorType**: 寻找的类型

# Window 窗口

WPF的主界面

[Window类](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.window?redirectedfrom=MSDN&view=windowsdesktop-7.0)

**Window 继承自 ContentControl 因此里面只能有一个 Content**： 所以一般在window里面创建一个StackPanel、Grid 等布局控件来容纳其他控件。

## Window 生存期

**SourceInitiated** -> **Activated** -> **Loaded** -> **ContentRendered**（If a window has content）-> 【Deactivated ↔ Activated】 -> **Closing** -> **Deactivated** -> **Closed**

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

**WindowStyle** ： 窗口的边框样式

**Topmost** : 是否一直处于最顶层

**Icon** : 图标设置

**ShowActivated** ：首次显示时是否激活窗口，默认 true。

**ResizeMode** ： 设置调整尺寸的模式

## C# 对象

`using System.Windows;`

**SystemParameters.MaximizedPrimaryScreenWidth** : 最大屏幕可用宽度

**SystemParameters.MaximizedPrimaryScreenHeight** ：最大屏幕可用高度（不包含任务栏）

**SystemParameters.WorkArea** : 工作区是系统任务栏或应用程序桌面工具栏未遮盖的屏幕部分。

- 返回 **Rect** 对象（`<Rect X="10" Y="100" Width="150" Height="100" />`）

## C# 方法

**ShowDialog**：窗体显示为模式窗体，逻辑代码会暂停，窗口关闭后，再继续执行后续代码。

**Show** ：窗体窗口显示为无模式窗口，直到关闭对话框后，才执行后面的代码。

## 自定义窗口时允许窗口拖动

```xaml
<TextBlock x:Name="TitleRoot" TextAlignment="Center" FontSize="25" Text="{Binding TitleText}" MouseLeftButtonDown="TitleRoot_MouseLeftButtonDown"/>
```

```c#
private void TitleRoot_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
{
    this.DragMove();
}
```

# 布局控件

可以容纳多个控件或嵌套其他布局控件，用于在UI上组织和排列控件。

有 **Grid、StackPanel、DockPanel** 等控件，他们拥有共同的父类 **Panel**。

- WPF布局原则
  - 一个窗口中只能包含一个元素
  - 不应显示设置元素尺寸
  - 不应使用坐标设置元素的位置
  - 可以嵌套布局容器
- WPF布局容器
  - *StackPanel*: 水平或垂直排列元素、Orientation属性分别: Horizontal / Vertical
  - *WrapPanel* : 水平或垂直排列元素、针对剩余空间不足会进行换行或换列进行排列
  - *DockPanel* : 根据容器的边界、元素进行Dock.Top、Left、Right、Bottom设置
  - *Grid* : 类似table表格、可灵活设置行列并放置控件元素、比较常用
  - *UniformGrid* : 指定行和列的数量, 均分有限的容器空间
  - *Canvas* : 使用固定的坐标设置元素的位置、不具备锚定停靠等功能。

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

## StackPanel

将子元素排列成水平或垂直的一行。超出部分将隐藏，不能自动切换到下一行，子元素是依次排列，位置不能随意拖动，但可以通过Margin设置各子元素的间隔。

### 属性

**FlowDirection** ：流动方向，只对 Orientation = “Horizontal” 有效，可选择从左至右、从右至左。

## WrapPanel

环绕面板，显示不够时，后续元素显示将 **自动换行**

### 属性

**Orientation**

**ItemWidth**

**ItemHeight**

## Canvas

定义一个区域，可在其中使用相对于 Canvas 区域的坐标来显式定位子元素。

两个元素重叠，后添加的会显示在上面。

### 属性

**Left、Right、Top、Bottom**

**ClipToBounds** : 是否剪切此元素内容。

**Panel.Index** ：值大的，显示在上层。

## DockPanel

定义一个区域，从中可以按 相对位置 水平或垂直排列各个子元素。

**特征**：

- 按照添加的顺序进行堆叠，所有空间不会堆叠；
- 最后一个控件必填充整个剩余空间，除非在 `DockPanel` 中设置 `LastChildFill=False`；（其实意义不大，不设置宽高的均填充，不填充的也不会设置宽高）

### 属性

**.Dock**：设置停靠的位置

**LastChildFill**： 最后一个子元素是否拉伸填充剩余空间

## TabControl

选项卡页面，包含多个共享相同的空间。

父类：`Selector` 其中的项：`TabItem` 的父类是：`HeaderedContentControl`

可以根据视觉树结构，重写控件模板，改变 TabControl 的外观显示，可定义控件模板或样式或重写 TabItem 的样式或模板，也可以重写 TabItem 的 HeaderTemplate

### 属性

**TabStripPlacement**： 选项卡标题栏显示的位置

**SelectedContent** ：选择的选项卡的Content

**ContentTemplate** ： TabItem的内容模板

**SelectedItem**：TabControl 中选中的 TabItem

# 内容控件

只能容纳一个其他控件或布局控件作为它的内容。

有 **Window、Button** 等控件，他们拥有共同的父类 **ContentControl** 。

## Label

## [Border](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.controls.border?view=windowsdesktop-7.0)

```xaml
<Border Background="LightBlue" 
        BorderBrush="Black" 
        BorderThickness="2" 
        CornerRadius="45" 
        Padding="25">
```

## Button

### 属性

**Content**： Button显示的内容

**IsDefault** ：True/False 窗体的确认默认按钮，可以敲击回车键来触发

**IsCancel** ：True/False 窗体的取消默认按钮，可以敲击ESC键来触发

**ClickMode** ：Hover、Press、Release

## RadioButton

### 属性

**Content**： 内容

**GroupName** ： 设置组名，同组成员互斥。

**isChecked**：单选按钮的选中状态

**Tag**： 控件上Tag值。

### [事件](https://learn.microsoft.com/zh-cn/dotnet/api/system.windows.controls.button?view=windowsdesktop-7.0#events)

**Checked** : 勾选时触发事件

**Click**：

**Unchecked** ：

## CheckBox

**IsThreeState** ： True/False 允许出现第三种状态

## GroupBox

分组容器 创建具有边框和标题的容器

父类：`HeaderedContentControl`

### 属性

**Header**：标题

**HeaderTemplate**：标题模板

## Expander

可折叠内容的控件

父类：`HeaderedContentControl`

### 属性

**Header**

**ExpandDirection** ：展开方向

**IsExpanded**：是否展开内容

## Frame

支持导航的内容控件

父类：`ContentControl`

### 属性

**BackStack/ForwardStack**：枚举 后退/前进 导航历史记录中的条目

**NavigationUIVisibility**：是否可以显示其导航UI

**Source**：包含 URI 当前的内容

**NavigationService**：Frame相关。提供导航服务

### 方法

**.Navigate()** ：导航到指定的内容。（可以传入 URI 或者 页面对象）

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

## TextBox

默认是单行文本框

### 事件

**TextChanged** : 文本改变事件

## PasswordBox 控件

### 属性

**Password** ：密码文本信息

**PasswordChar** ： 密码字符

### 事件

**PasswordChanged**

## TextBlock

### 控件介绍

简单的使用方式：

```xaml
<TextBlock Text="This is a TextBlock" FontSize="30"/>
```

如果标签内设置了内容，内容会紧跟 Text:

```xaml
<TextBlock Text="This is a TextBlock" FontSize="30">标签内的内容</TextBlock>
```

显示：This is a TextBlock标签内的内容

### 追加流元素

此方法不常用

```c#
tbText.inlines.Add("aaa");
Label lbl = new Label();
lbl.Content = "xxx";
tbText.inlines.Add(lbl);
```

## Image

图像控件

### 属性

**Stretch** ： 拉伸方式

- **Fill**：不保持纵横比全部填充
- **Uniform** ：保持纵横比
- **UniformToFill** ： 保持纵横比填充，如果不一致则进行裁剪

**StretchDirection** ：如何缩放

- **DownOnly** ：仅缩小
- **UpOnly** ： 仅放大
- **Both** ： 根据 Stretch 模式进行拉伸

### C# 方法

Source 图片文件路径

```c#
img0.Source = new BitmapImage(new Uri("images/xx.png", UriKind.Relative));
```

## ProgressBar

进度条；父类 **RangeBase**

### 属性

**Orientation** ： 进度条方向

**Maximum/Minimum**

**IsIndeterminate** : 是否隐藏当前值；True，就会一直滚动。

### 事件

**ValueChanged**

### 使用

显示循环修改进度的动态过程，而不卡UI线程：

```c#
Task.Run(()=>{
    for (int i = 0; i < 100; i++){
        pbar1.Dispatcher.Invoke(()=>{
            pbar1.Value = i;
        });
        Thread.Sleep(100);
    }
});
```

如果只是想显示进度条滚动，那么直接更改属性即可：

```c#
private void btnStart_Click(object sender, RoutedEventArgs e)
{
    Task.Run(() =>
    {
        this.proceeBar.Dispatcher.Invoke(() =>
        {
            this.proceeBar.IsIndeterminate = !this.proceeBar.IsIndeterminate;
        });
    });
}
```

## ComboBox

### 属性

**IsDropDownOpen**：是否打开下拉菜单，默认 false。

**SelectedValue**：选择项的对应的值

**SelectedIndex**：选择项的索引

**ItemSource** ：用于显示的项的集合

**IsEditable**：是否可编辑

# RelativeSource 属性

我们进行Bingding时，如果明确知道数据源的Name，就能用Source或者ElementName进行绑定，但是有时候我们需要绑定的数据源可能没有明确的Name，此时我们就需要利用Bingding的RelativeSource进行绑定，这种办法的意思是指当前元素和绑定源的位置关系。

（1）控件关联自身的属性——Self

`CommandParameter="{Binding RelativeSource={x:Static RelativeSource.Self}}"`

# Dispatcher

Dispatcher 用于管理线程工作项队列。

以下方式调用线程方式是错误的，因为几乎所有的UI控件都继承于 **DispatcherObject**，由 Dispatcher 线程管理，不能在新的线程中直接修改UI元素。

```c#
private void btnLogin_Click(object sender, RoutedEventArgs e)
{
    Thread th = new Thread(() =>
    {
       this.lbShow.Content = "Welcome to WPF";
    });
    th.Start();
}
```

利用 **Dispatcher** 的 `Invoke` 和 `BegInInvoke` ，作用是把委托放到界面元素关联的 Dispatcher 里的工作项里，然后此 Dispatcher 关联的线程进行执行。

`Invoke` 是在关联的线程里 **同步执行** 委托；`BegInInvoke` 是在关联的线程里 **异步执行** 委托。

```c#
private void btnLogin_Click(object sender, RoutedEventArgs e)
{
    Thread th = new Thread(() =>
    {
        this.Dispatcher.Invoke(() =>
        {
            this.lbShow.Content = "Welcome to WPF";
        });
    });
    th.Start();
}
```

# Convert

构造一个 Convert 类 继承 `IValueConverter`

```c#
public class BoolToVisibilityConvert : IValueConverter
{
    public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
    {
        bool bValue = (bool)value;

        if (bValue)
        {
            return Visibility.Visible;
        }
        else
        {
            return Visibility.Collapsed;
        }
    }

    public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }
}
```

Resource 中引入类

```xaml
<Window.Resources>
    <local:BoolToVisibilityConvert x:Key="BoolToVisibilityConvert"/>
</Window.Resources>
```

再使用 Convert 类

```xaml
<Button Content="Load Thick" Margin="5" Visibility="{Binding Path=IsChecked, ElementName=radioButtonSimulate, Converter={StaticResource BoolToVisibilityConvert}}"/>
```

# 浅谈布局

## Margin

**VerticalAlignment** 和 **HorizontalAlignment** 属性是计算 Margin 后生效的。

# WPF数据绑定

## 元素绑定

```xaml
<Grid>
    <StackPanel>
        <Slider x:Name="sd" Width ="200" />
        <TextBox Text ="{Binding ElementName=sd, Path=Value}" />
    </StackPanel>
</Grid>
```

## 非元素绑定（绑定到静态资源）

```xaml
<Window.Resources>
    <TextBox x:Key="txt">Hello,WPF</TextBox>
</Window.Resources>

<TextBox Text ="{Binding Source={StaticResource txt},Path=Text}"/>
```

# 数据模板

https://devblogs.microsoft.com/?WT.mc_id=DT-MVP-5003986
微软文档与学习:
https://docs.microsoft.com/zh-cn/?WT.mc_id=DT-MVP-5003986
微软开发者平台:
https://developer.microsoft.com/en-us/?WT.mc_id=DT-MVP-5003986

数据模板常用在3种类型的控件, 下图形式:

![](https://img2020.cnblogs.com/blog/1161656/202012/1161656-20201228130825259-95107469.png)



# VS 代码片段

## 自带代码片段

- **ctor** ： 构造函数代码片段
- **propfull** : 完整属性代码片段

# 插件

## WPF开源UI控件库MaterialDesign

http://materialdesigninxaml.net/

[Super Quick Start](https://github.com/MaterialDesignInXAML/MaterialDesignInXamlToolkit/wiki/Super-Quick-Start)

