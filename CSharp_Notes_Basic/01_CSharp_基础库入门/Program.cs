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

        static void Test(params char[] arr)
        {
            Console.WriteLine(arr.Length);
        }

        static void Main(string[] args)
        {
            DataTypeTest.HashtableBase.HashtableBaseFunction();
            Console.ReadKey();
        }
    }
}
