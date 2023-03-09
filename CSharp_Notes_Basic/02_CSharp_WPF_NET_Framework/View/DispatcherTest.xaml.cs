using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
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
    /// DispatcherTest.xaml 的交互逻辑
    /// </summary>
    public partial class DispatcherTest : Window
    {
        public DispatcherTest()
        {
            InitializeComponent();
        }

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
    }
}
