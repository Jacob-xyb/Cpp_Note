using System;  // 引入命名空间
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_CSharp_基础库入门
{
    public class Person
    {
        public string m_Name;
        public string m_Description;
        public int m_Age;
        public int m_Id;

        public Person(string name, string description, int age, int id)
        {
            m_Name = name;
            m_Description = description;
            m_Age = age;
            m_Id = id;
        }

        public Person(int age, int id) : this("", "", age, id)
        {

        }

        public void M1()
        {

        }

        public static void M2()
        {

        }
    }

    internal class Program
    {

        static void Main(string[] args)
        {
            Person p1 = new Person(0, 3);
            Console.WriteLine(p1.m_Name + p1.m_Age + p1.m_Id);
            Console.ReadKey();
        }
    }
}
