using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace _02_CSharp_WPF_NET_Framework
{
    public class ItemControlClanViewModel
    {
        private ItemControlClan _window;

        public ItemControlClanViewModel(ItemControlClan window)
        {
            this._window = window;
        }

        private ICommand _CommandBtnClick;
        public ICommand CommandBtnClick
        {
            get
            {
                if (_CommandBtnClick == null)
                {
                    _CommandBtnClick = new CommandBase()
                    {
                        DoAction = new Action<object>(Btn_Click)
                    };
                }
                return _CommandBtnClick;
            }
        }


        public void Btn_Click(object value)
        {
            string _content = (value as Button).Content.ToString().Trim();

            if (_content == "ListBox")
            {
                ListBoxTest dialog = new ListBoxTest();
                dialog.ShowDialog();
            }
        }
    }
}
