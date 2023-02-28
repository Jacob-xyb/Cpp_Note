using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;

using _02_CSharp_WPF_NET_Framework;

using CommunityToolkit.Mvvm.ComponentModel;

namespace _02_CSharp_WPF_NET_Framework
{
    public class MainViewModel : ObservableObject
    {
        private MainWindow _mainWindow = null;

        public MainViewModel(MainWindow mainWindow)
        {
            _mainWindow = mainWindow;
        }

        private ICommand _BtnClick = null;
        public ICommand BtnClick
        {
            get
            {
                if (_BtnClick == null)
                {
                    _BtnClick = new CommandBase(){
                        DoAction = new Action<object>(FuncBtnClick)
                    };
                }
                return _BtnClick;
            }
        }


        public void FuncBtnClick(object value)
        {
            string _content = (value as Button).Content.ToString().Trim();

            if (_content == "GridTest")
            {
                GridTest dialog = new GridTest();
                dialog.ShowDialog();
            }
            else if (_content == "BindingTest")
            {
                BindingTest dialog = new BindingTest();
                dialog.ShowDialog();
            }
            //Console.WriteLine(_content);
        }
    }
}
