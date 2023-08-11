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

        class People
        {
            public double num = 0.0;
        }

        static void Main(string[] args)
        {
            //DataTypeTest.ArrayTest.FuncTest_ArrayBase();

            //ClassTest.ClassPolymorphic.FuncTest_ClassPolymorphicBase();

            //double d1 = 0;
            //double d2 = 0;
            //double d3 = 0;
            int len = 200 * 5 * 1044;
            People[] dArray = new People[len];

            List<double> l = new List<double>();
            for (int i = 0; i < len; i++)
            {
                dArray[i] = new People();
                l.Add(dArray[i].num);
            }

            Console.WriteLine("success");
            Console.WriteLine(l.Count);

            Console.ReadKey();
        }
    }
}
