using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _03_CSharp_标准库使用
{
    static class PathTest
    {
        public static void FuncTest_PathBase()
        {
            string str = @"C:\Users\Administrator\Desktop\test.txt";
            Console.WriteLine(Path.GetFileName(str)); 
            Console.WriteLine(Path.GetFileNameWithoutExtension(str));
            Console.WriteLine(Path.GetDirectoryName(str));
            Console.WriteLine(Path.Combine(@"C:\Users\Administrator\Desktop", "data.txt"));
        }
    }
}
