using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_CSharp_基础库入门.DataTypeTest
{
    public static class HashtableBase
    {
        public static void HashtableBaseFunction()
        {
            Hashtable dict = new Hashtable();

            dict.Add(1, "张三");
            dict.Add(2, "李四");
            dict.Add(false, "王五");

            Console.WriteLine(dict["c#"] == null);  // True; 如果没有此键，则返回空
            foreach (var item in dict.Keys)
            {
                Console.WriteLine(item);
            }
        }
    }
}
