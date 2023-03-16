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

namespace _02_CSharp_WPF_NET_Framework.ContenControlClan
{
    /// <summary>
    /// ButtonTest.xaml 的交互逻辑
    /// </summary>
    public partial class ButtonTest : Window
    {
        public ButtonTest()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("响应单击事件");
        }

        private void Button_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            // 双击不分左右键
            MessageBox.Show("响应双击事件");
        }

        private void Button_MouseEnter(object sender, MouseEventArgs e)
        {
            MessageBox.Show("响应MouseEnter事件");
        }

        private void Button_MouseRightButtonUp(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("响应右键事件");
        }
    }
}
