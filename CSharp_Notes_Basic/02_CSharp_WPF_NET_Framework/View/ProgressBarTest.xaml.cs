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
    /// ProgressBarTest.xaml 的交互逻辑
    /// </summary>
    public partial class ProgressBarTest : Window
    {
        public ProgressBarTest()
        {
            InitializeComponent();
        }

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
    }
}