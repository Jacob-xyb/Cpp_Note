using _01_CSharp_基础库入门.ModifierTest;
using System;  // 引入命名空间
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;


namespace _01_CSharp_基础库入门
{

    internal class Program
    {

        static void Main(string[] args)
        {
            //DataTypeTest.ArrayTest.FuncTest_ArrayBase();

            //ClassTest.ClassPolymorphic.FuncTest_ClassPolymorphicBase();

            Stopwatch sw= new Stopwatch();
            sw.Start();
            Thread.Sleep(1000);
            sw.Stop();
            Console.WriteLine($"{string.Format("{0:.00}", sw.ElapsedMilliseconds / 1000.0)}");

            Console.ReadKey();
        }
    }
}
