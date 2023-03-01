using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_CSharp_基础库入门.ClassTest
{
    internal class ClassBase
    {
    }

    public class Person
    {
        /*Tips:
        //类中的成员，如果不加访问修饰符，默认都是private*/

        /// <summary>
        /// 字段
        /// </summary>
        private string _sName;
        /// <summary>
        /// 属性，属性的本质是两个方法
        /// </summary>
        public string sName
        {
            get { return _sName; }
            set { _sName = value; }
        }

        public Person(string sName)
        {
            this.sName = sName;
        }

        /// <summary>
        /// this 调用自身构造函数
        /// </summary>
        public Person(): this("")
        {

        }
    }
}
