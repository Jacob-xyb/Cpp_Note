using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _03_CSharp_标准库使用
{
    public static class FileStreamTest
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
            using (FileStream fsWrite = new FileStream(FileStreamTest.path, FileMode.Create, FileAccess.Write))
            {
                string str = "字节流写入文件";
                byte[] buffers = Encoding.Default.GetBytes(str);
                fsWrite.Write(buffers, 0, buffers.Length);
            }
        }

        public static void FuncTest_FileStreamModeTest()
        {
            using (FileStream fs = new FileStream(FileStreamTest.path, FileMode.Create, FileAccess.Write))
            {
                ////读取数据
                //byte[] buffer = new byte[1024 * 1024 * 5];
                //// 返回本次实际读取到的有效字节数
                //int rst = fs.Read(buffer, 0, buffer.Length);
                //string content = Encoding.Default.GetString(buffer, 0, rst);
                //Console.WriteLine(content);

                //写入数据
                string str = "字节流读取写入文件";
                byte[] buffers = Encoding.Default.GetBytes(str);
                fs.Write(buffers, 0, buffers.Length);
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

        public static List<List<double>> Read_DataFile(string path)
        {
            List<List<double>> data = new List<List<double>>();
            char[] splitChar = new char[] { '\t', ' ' };
            double tempD = 0.0;
            using (StreamReader sRead = new StreamReader(path, Encoding.Default))
            {
                while (!sRead.EndOfStream)
                {
                    string[] tmp = sRead.ReadLine().Split(splitChar, StringSplitOptions.RemoveEmptyEntries);
                    if (tmp.Contains("-nan") || tmp.Contains("nan"))
                    {
                        break;
                    }
                    else if (!Double.TryParse(tmp[0], out tempD))
                    {
                        continue;
                    }
                    List<double> tmpData = new List<double>();
                    foreach (string item in tmp)
                    {
                        tmpData.Add(Convert.ToDouble(item));
                    }
                    data.Add(tmpData);
                }
            }
            return data;
        }

        public static void Write_DataFile(string path, List<List<double>> data)
        {
            using (StreamWriter sWriter = new StreamWriter(path, false, Encoding.Default))
            {
                for (int i = 0; i < data.Count; i++)
                {
                    StringBuilder sb = new StringBuilder();
                    for (int j = 0; j < data[0].Count; j++)
                    {
                        sb.Append(data[i][j].ToString("f6") + " ");
                    }
                    sWriter.WriteLine(sb);
                }
            }
        }


        public static void FuncTest_StreamReaderAndWriter_Case1()
        {
            string path = @"C:\Users\Administrator\Desktop\fangfang\HadamardData-SE0.dat";
            List<List<double>> data = FileStreamTest.Read_DataFile(path);
            int row = data.Count;
            int colMax = data[0].Count;
            int FrameNumberAll = colMax - 1;
            int FrameNumPerPeriod = 50;
            int PeriodNum = (FrameNumberAll - 2) / FrameNumPerPeriod;
            double[] waveList = new double[row];
            double[,] temhadmardData = new double[row, PeriodNum / 2 * FrameNumPerPeriod];
            
            double tmpd = 0;
            //bool bInavgRange = true;
            for (int i = 0; i < row; i++)
            {
                waveList[i] = data[i][0];
                for (int mm = 0; mm < FrameNumPerPeriod; mm += 2)
                {
                    tmpd = 0;
                    for (int j = 0; j < PeriodNum; j++)
                    {
                        if ((j == 0) && (mm < 2))
                        {
                            tmpd += data[i][PeriodNum * FrameNumPerPeriod + mm];
                        }
                        else
                        {
                            tmpd += data[i][j * FrameNumPerPeriod + mm];
                        }

                    }
                    temhadmardData[i, mm] = tmpd / FrameNumPerPeriod;
                }
            }
        }
    }
}
