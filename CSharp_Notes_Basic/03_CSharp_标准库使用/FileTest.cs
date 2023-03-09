using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _03_CSharp_标准库使用
{
    static class FileTest
    {
        public static void FuncTest_FileBase()
        {
            string filePath = @"C:\Users\Administrator\Desktop\test.txt";
            string filePath2 = @"C:\Users\Administrator\Desktop\test2.txt";
            FileStream s = File.Create(filePath);
            s.Dispose();
            //File.Delete(filePath);
            File.Copy(filePath, filePath2);
        }

        public static void FuncTest_FileReadWriteByBytesBase()
        {
            string filePath = @"C:\Users\Administrator\Desktop\test.txt";

            //读取
            byte[] s = File.ReadAllBytes(filePath);
            //将字节数组中的每个元素都按照指定的编码格式解码成字符串
            string res = Encoding.Default.GetString(s);
            Console.WriteLine(res);

            //写入
            string context = "你好，世界";
            byte[] buffers = Encoding.Default.GetBytes(context);
            File.WriteAllBytes(filePath, buffers);
        }

        public static void FuncTest_FileReadWriteByLinesBase()
        {
            string filePath = @"C:\Users\Administrator\Desktop\test.txt";

            //读取
            string[] read_contents = File.ReadAllLines(filePath);
        }

        public static void FuncTest_FileReadWriteByTextBase()
        {
            string filePath = @"C:\Users\Administrator\Desktop\test.txt";

            //读取
            string read_contents = File.ReadAllText(filePath);
        }

    }
}
