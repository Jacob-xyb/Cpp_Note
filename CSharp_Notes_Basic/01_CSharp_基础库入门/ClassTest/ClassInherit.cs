using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_CSharp_基础库入门.ClassTest
{
    public static class ClassInherit
    {
        public static void ClassInheritBase()
        {

        }
    }

    public class PersonBase
    {
        public PersonBase(string name, int age, char gender)
        {
            this.m_sName = name;
            this.m_iAge = age;
            this.m_cGender = gender;
        }

        public PersonBase()
        {

        }

        private string _sName;
        public string m_sName
        {
            get { return _sName; }
            set { _sName = value; }
        }

        private int _iAge;
        public int m_iAge
        {
            get { return _iAge; }
            set { _iAge = value; }
        }

        private char _cGender;
        public char m_cGender
        {
            get { return _cGender; }
            set { _cGender = value; }
        }


        public void DoSomething()
        {
            Console.WriteLine("吃喝拉撒");
        }
    }

    public class Student : PersonBase
    {
        public Student(string name, int age, char gender, int id) : base(name, age, gender)
        {
            this.m_iID = id;
        }

        private int _iID;
        public int m_iID
        {
            get { return _iID; }
            set { _iID = value; }
        }

    }

    public class Teacher : PersonBase
    {
        private double _dSalary;
        public double m_dSalary
        {
            get { return _dSalary; }
            set { _dSalary = value; }
        }

    }
}
