using _01_CSharp_基础库入门.ClassTest;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace _03_CSharp_标准库使用
{
    [Serializable]
    class XmlSerializerTest_Person
    {
        private string _Name;
        public string Name
        {
            get { return _Name; }
            set { _Name = value; }
        }

        private int _Age;
        public int Age
        {
            get { return _Age; }
            set { _Age = value; }
        }

        private char _Gender;
        public char Gender
        {
            get { return _Gender; }
            set { _Gender = value; }
        }

    }

    static class XmlSerializerTest
    {
        public static void FuncTest_SerializerBase()
        {
            XmlSerializerTest_Person p1 = new XmlSerializerTest_Person() { Name = "jx", Age = 18, Gender = '男' };
            using (FileStream fs = new FileStream(@"C:\Users\Administrator\Desktop\Serializer.txt", FileMode.Create))
            {
                BinaryFormatter bf = new BinaryFormatter();
                bf.Serialize(fs, p1);
            }

            XmlSerializerTest_Person p2;
            using (FileStream fs = new FileStream(@"C:\Users\Administrator\Desktop\Serializer.txt", FileMode.OpenOrCreate))
            {
                BinaryFormatter bf = new BinaryFormatter();
                p2 = bf.Deserialize(fs) as XmlSerializerTest_Person;
            }
            Console.WriteLine(p2.Name + p2.Age + p2.Gender);
        }
    }
}
