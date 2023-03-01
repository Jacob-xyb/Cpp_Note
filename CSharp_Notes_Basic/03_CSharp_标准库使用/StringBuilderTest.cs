using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _03_CSharp_标准库使用
{
    public static class StringBuilderTest
    {

        public static void TestFunc_StringBuilder()
        {
            // StringBuilder 没有一直在开辟空间，所以对字符串频繁操作时，应该用 StringBuilder
            StringBuilder tmp = new StringBuilder();
            string str = null;
            Stopwatch sw = new Stopwatch();
            sw.Start();
            for (int i = 0; i < 100000; i++)
            {
                str += i;
            }
            sw.Stop();
            Console.WriteLine(sw.Elapsed);  // 00:00:10.5140174
           
            sw.Restart();
            for (int i = 0; i < 100000; i++)
            {
                tmp.Append(i);
            }
            sw.Stop();
            Console.WriteLine(sw.Elapsed);  // 00:00:00.0096750
        }
    }
}
