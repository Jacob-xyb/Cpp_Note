using _01_CSharp_基础库入门.ModifierTest;
using System;  // 引入命名空间
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _01_CSharp_基础库入门
{

    internal class Program
    {

        static void Main(string[] args)
        {
            //DataTypeTest.HashtableBase.HashtableBaseFunction();
            PublicClassObject obj1 = new PublicClassObject();
            InternalClassObject obj2 = new InternalClassObject();
            Console.ReadKey();
        }
    }
}
