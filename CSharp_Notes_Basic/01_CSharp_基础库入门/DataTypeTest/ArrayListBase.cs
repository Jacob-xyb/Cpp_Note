using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_CSharp_基础库入门.DataTypeTest
{
    public static class ArrayListBase
    {
        public static void ArrayListBaseFunction()
        {
            // 集合的好处，长度可以任意改变 类型随便
            ArrayList list = new ArrayList();
            list.Add(1);
            list.Add(3.14);
            list.Add(true);
            Console.WriteLine(list.Count);  // 3
            list.AddRange(new int[] { 1, 2, 3 });
            Console.WriteLine(list.Count);  // 6
            list.Remove(1); // 只删除第一个匹配的项

            Console.WriteLine("删除前[0]:{0}", list[0]);
            list.RemoveAt(0);   // 按index删除
            Console.WriteLine("删除后[0]:{0}", list[0]);
            list.RemoveRange(0, 1);
            list.Clear();
        }

        public static void ArrayListCountAndCapacity()
        {
            ArrayList list = new ArrayList();
            Console.WriteLine("空集合的 Count：{0}, Capacity: {1}", list.Count, list.Capacity);
            list.Add(1);
            Console.WriteLine("空集合的 Count：{0}, Capacity: {1}", list.Count, list.Capacity);
        }

    }
}
