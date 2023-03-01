using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_CSharp_基础库入门.DataTypeTest
{
    public static class StringBase
    {
        public static void StringBaseFunction()
        {
            string name = "JacobXyb";
            Console.WriteLine("Length: 获取当前字符串中字符的个数: {0}", name.Length);

            string name2 = "jacobxyb";

            Console.WriteLine("Equals: 判断两个字符串是否相等: {0}", name.Equals(name2));
            Console.WriteLine("Equals: 判断两个字符串是否相等（不区分大小写）: {0}", name.Equals(name2, StringComparison.OrdinalIgnoreCase));

            Console.WriteLine("Substring(int startIndex): 子字符串: {0}", name.Substring(5));
            Console.WriteLine("Substring(int startIndex, int length): 子字符串: {0}", name.Substring(0, 5));
        }

        public static void StringSplit()
        {
            string time = "yyyy-mm-dd HH:MM:SS";
            char[] arrSplit = { '-', ' ', ':' };

            Console.WriteLine("Split(): 默认分割空格；\n数组长度: {0}", time.Split().Length);
            foreach (var item in time.Split())
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("Split(params char[] separator): 按多个字符分割;\n数组长度: {0}", time.Split('-', ' ').Length);
            foreach (var item in time.Split('-', ' '))
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("Split(params char[] separator): 按多个字符分割;\n数组长度: {0}", time.Split(arrSplit).Length);
            foreach (var item in time.Split(arrSplit))
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("Split(char[] separator, int count): count 限制返回的最大长度\n数组长度: {0}", time.Split(new char[] { '-' }, 2).Length);
            foreach (var item in time.Split(new char[] { '-' }, 1))
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("Split(char[] separator, int count): count 限制返回的最大长度\n数组长度: {0}", time.Split(arrSplit, 4).Length);
            foreach (var item in time.Split(arrSplit, 4))
            {
                Console.WriteLine(item);
            }


            // 两个都满足条件的分隔符连在一起，会产生一个空字符串，收尾都有分隔符时会产生空字符串
            // 可以设置 StringSplitOptions.RemoveEmptyEntries 移除空字符串
            string time1 = "-yyyy- mm-dd-";
            Console.WriteLine("Split(char[] separator, StringSplitOptions options): options 可以选择是否保留空字符串\n数组长度: {0}", time1.Split(arrSplit).Count());
            foreach (var item in time1.Split(arrSplit))
            {
                Console.WriteLine(item == "");
            }

            Console.WriteLine("Split(char[] separator, StringSplitOptions options): options 可以选择是否保留空字符串\n数组长度: {0}", time1.Split(arrSplit, StringSplitOptions.RemoveEmptyEntries).Count());
            foreach (var item in time1.Split(arrSplit, StringSplitOptions.RemoveEmptyEntries))
            {
                Console.WriteLine(item == "");
            }
        }

        public static void StringReplace()
        {
            string str = "xxyyzz";
            string new_str = "";
            if (str.Contains("zz"))
            {
                new_str = str.Replace("zz", "bb");
            }
            Console.WriteLine(new_str);
        }
    }
}
