using System;  // 引入命名空间
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _01_CSharp_基础库入门
{

    internal class Program
    {

        static void Main(string[] args)
        {
            int num = 5;
            string str1 = "zhangsan";
            string str2 = str1;
            str1 = "lisi";
            Console.WriteLine(str1 + " " + str2);
            Console.ReadKey();
        }
    }
}
