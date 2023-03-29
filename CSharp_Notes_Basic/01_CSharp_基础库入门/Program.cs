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
            byte[] dest = new byte[1024];
            byte[] bts = new byte[0];
            byte[] cts = Encoding.Default.GetBytes("");
            Console.WriteLine(bts.Length);
            Array.Copy(cts, 0, dest, 512, cts.Length);

            Console.ReadKey();
        }
    }
}
