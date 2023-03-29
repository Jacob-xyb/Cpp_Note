using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NumSharp;
using _03_CSharp_标准库使用;

namespace _07_CSharp_ThirdLibraryTest
{
    static class NumSharpTest
    {
        public static void FuncTest_NumSharpInit()
        {
            List<double> list = new List<double>() { 1, 2, 3, 4, 5 };
            NDArray arr = list.ToArray();

            // 二维暂时不知道怎么转
            List<List<double>> list2 = new List<List<double>>();
            for (int i = 0; i < 5; i++)
            {
                list2.Add(list);
            }
            //var data = np.(list2);

            // fromfile 方法有问题
            //var data = np.fromfile(@"C:\Users\Administrator\Desktop\fangfang\HadamardData-SE0.dat", NPTypeCode.Double);

            NDArray arrArange = np.arange(0, 10);


            // 二维数组
            int[,] arrDims2 = new int[3, 3] { { 1, 2, 3 }, { 4, 5, 6 }, { -1, 7, 10 } };
            NDArray arrDims2np = np.array(arrDims2);

            Console.WriteLine(arrDims2np[Slice.All, 0].ToString());
            NDArray data = np.max(arrDims2np[Slice.All, 0]);
            data = np.abs(arrDims2np - 10)[Slice.All, 0];
            data = np.argmax(data);
            Console.WriteLine((int)data.GetAtIndex(0));
            Console.WriteLine(arrArange.ToString());
        }

        public static void FuncTest_DataProcessing_Case1()
        {
            string path = @"C:\Users\Administrator\Desktop\fangfang\HadamardData-SE-240.dat";
            List<List<double>> data = FileStreamTest.Read_DataFile(path);

            string path2 = @"C:\Users\Administrator\Desktop\fangfang\HadamardData-SE.dat";
            FileStreamTest.Write_DataFile(path2, data);

            int row = data.Count;
            int col = data[0].Count;

            int startIndex = 0;
            int closestIndex = 0;
            int endIndex = 0;

            double[,] dataArray = new double[row, col];
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    dataArray[i, j] = data[i][j];
                }
            }
            NDArray dataNumpy = np.array(dataArray);  // 全数组
            NDArray waveAbsDiff = np.abs(dataNumpy[":,0"] - 240);
            closestIndex = np.argmin(waveAbsDiff);
            startIndex = Math.Max(closestIndex - 20, 0);
            endIndex = Math.Min(closestIndex + 20, row);

            NDArray Indexs = np.zeros(endIndex - startIndex + 1);

            NDArray dataNumpySlice = dataNumpy[$"{startIndex}:{endIndex + 1},1:"];
            NDArray tempIndex = np.argmax(dataNumpySlice, 0);  // 最大列

            for (int i = 0; i < tempIndex.size; i++)
            {
                //Console.WriteLine((int)tempIndex.GetAtIndex(i));
                Indexs[tempIndex.GetValue(i)] += 1;
            }

            int iMax = Indexs.argmax();
            
            Console.WriteLine(iMax + startIndex);

            Console.WriteLine(tempIndex.ToString());
        }
    }
}
