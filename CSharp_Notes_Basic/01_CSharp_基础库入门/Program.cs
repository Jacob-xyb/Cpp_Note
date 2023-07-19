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

            double d1 = 0;
            double d2 = 0;
            double d3 = 0;
            double[] dArray = new double[3] { d1, d2, d3};

            dArray[0] = 100;
            Console.WriteLine(d1);

            Console.ReadKey();
        }
    }
}
