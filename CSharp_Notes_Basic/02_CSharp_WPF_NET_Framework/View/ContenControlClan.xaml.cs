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

using _02_CSharp_WPF_NET_Framework.ContenControlClan;

namespace _02_CSharp_WPF_NET_Framework.View
{
    /// <summary>
    /// ContenControlClan.xaml 的交互逻辑
    /// </summary>
    public partial class ContenControlClan : Window
    {
        public ContenControlClan()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Button btn = sender as Button;
            string name = btn.Content.ToString();
            if (name == "NavigationWindow")
            {
                NavigationWindowTest dialog = new NavigationWindowTest();
                dialog.ShowDialog();
            }
            else if (name == "Button")
            {
                ButtonTest dialog = new ButtonTest();
                dialog.ShowDialog();
            } 
        }
    }
}
