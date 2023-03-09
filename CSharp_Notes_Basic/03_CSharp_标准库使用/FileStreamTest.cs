using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _03_CSharp_标准库使用
{
    static class FileStreamTest
    {
        static string path = @"C:\Users\Administrator\Desktop\test.txt";

        public static void FuncTest_FileStreamBase()
        {
            FileStream fsRead = new FileStream(FileStreamTest.path, FileMode.OpenOrCreate, FileAccess.Read);

            //读取数据
            byte[] buffer = new byte[1024 * 1024 * 5];
            // 返回本次实际读取到的有效字节数
            int rst = fsRead.Read(buffer, 0, buffer.Length);
            string content = Encoding.Default.GetString(buffer, 0, rst);
            Console.WriteLine(content);
            // 关闭流
            fsRead.Close();
            fsRead.Dispose();
            
            //写入数据
            //将创建文件流对象的过程中写在 using 中，会自动释放资源
            using (FileStream fsWrite = new FileStream(FileStreamTest.path, FileMode.OpenOrCreate, FileAccess.Write))
            {
                string str = "字节流写入文件";
                byte[] buffers = Encoding.Default.GetBytes(str);
                fsWrite.Write(buffers, 0, buffers.Length);
            }
        }

        public static void FuncTest_StreamReaderAndWriter()
        {
            using (StreamReader sRead = new StreamReader(FileStreamTest.path, Encoding.Default))
            {
                while (!sRead.EndOfStream)
                {
                    Console.WriteLine(sRead.ReadLine());
                }
            }

            using (StreamWriter sWriter = new StreamWriter(FileStreamTest.path, false, Encoding.Default))
            {
                sWriter.Write("StreamWriter覆盖写入");
            }
        }

    }
}
