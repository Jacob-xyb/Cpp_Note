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

namespace _02_CSharp_WPF_NET_Framework
{
    /// <summary>
    /// LabelTest.xaml 的交互逻辑
    /// </summary>
    public partial class LabelTest : Window
    {
        public LabelTest()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            string label1_content = this.Label1.Content.ToString();
            StackPanel stack1 = this.Label2.Content as StackPanel;
            string label2_content = (stack1.Children[0] as TextBlock).Text + " " + (stack1.Children[1] as TextBlock).Text;
        }
    }
}
