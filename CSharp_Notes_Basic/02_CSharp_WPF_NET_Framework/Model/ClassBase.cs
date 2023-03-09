using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02_CSharp_WPF_NET_Framework
{
    public class Employee
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
    }

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

                //if (this.PropertyChanged != null)
                //{
                //    this.PropertyChanged.Invoke(this, new PropertyChangedEventArgs("m_Name"));
                //}

                //简化
                this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("m_Name"));
            }
        }

    }
}
