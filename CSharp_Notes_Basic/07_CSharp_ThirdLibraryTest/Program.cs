using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _07_CSharp_ThirdLibraryTest
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //NumSharpTest.FuncTest_DataProcessing_Case1();

            int x = 983815946;
            float y1 = Convert.ToSingle(x);
            double y2 = BitConverter.ToSingle(BitConverter.GetBytes(x),0);
            Console.WriteLine(y1);
            Console.WriteLine(y2);


            Console.ReadKey();
        }
    }
}
