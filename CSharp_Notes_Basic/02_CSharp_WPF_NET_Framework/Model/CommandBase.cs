using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace _02_CSharp_WPF_NET_Framework
{
    public class CommandBase : ICommand
    {
        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            //throw new NotImplementedException();
            if (DoCanExecute == null) return true;
            return DoCanExecute(parameter);
        }

        public void Execute(object parameter)
        {
            //throw new NotImplementedException();
            DoAction?.Invoke(parameter);
        }

        public Action<object> DoAction { get; set; }
        public Func<object, bool> DoCanExecute { get; set; }
    }
}
