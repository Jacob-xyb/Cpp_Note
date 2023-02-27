using System;
using System.Collections.Generic;
using System.ComponentModel;
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
                if (this.PropertyChanged != null)
                {
                    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("m_Name"));
                }
            }
        }

    }

    /// <summary>
    /// BindingTest.xaml 的交互逻辑
    /// </summary>
    public partial class BindingTest : Window
    {
        public BindingTest()
        {
            InitializeComponent();

            TheOriginalBindingMode();
        }


        private Student _stu;
        public void TheOriginalBindingMode()
        {
            this._stu = new Student();

            Binding binding = new Binding();
            binding.Source = this._stu;
            binding.Path = new PropertyPath("m_Name");

            BindingOperations.SetBinding(this.textBoxName, TextBox.TextProperty, binding);
        }

        private void Button_Click1(object sender, RoutedEventArgs e)
        {
            this._stu.m_Name += "Name";
        }
    }
}
