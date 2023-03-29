using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace _02_CSharp_WPF_NET_Framework.ItemControlClan
{
    /// <summary>
    /// ListBoxTest.xaml 的交互逻辑
    /// </summary>
    public partial class ListBoxTest : Window
    {
        public ListBoxTest()
        {
            InitializeComponent();
            this.listBoxEmployee.ItemsSource = this.empList;
            this.listBoxEmployee.DisplayMemberPath = "Name";
            this.listBoxEmployee.SelectedValuePath = "Id";
        }

        private void buttonOwen_Click(object sender, RoutedEventArgs e)
        {
            Button btn = sender as Button;
            DependencyObject level1 = VisualTreeHelper.GetParent(btn);
            DependencyObject level2 = VisualTreeHelper.GetParent(level1);
            DependencyObject level3 = VisualTreeHelper.GetParent(level2);
            MessageBox.Show(level3.GetType().ToString());
        }

        public List<Employee> empList = new List<Employee>()
        {
            new Employee() { Id = 1, Name = "Tim", Age = 21 },
            new Employee() { Id = 2, Name = "Tom", Age = 22 },
            new Employee() { Id = 3, Name = "Guo", Age = 23 },
            new Employee() { Id = 4, Name = "Yan", Age = 24 },
            new Employee() { Id = 5, Name = "Bo", Age = 25 },
        };
    }
}
