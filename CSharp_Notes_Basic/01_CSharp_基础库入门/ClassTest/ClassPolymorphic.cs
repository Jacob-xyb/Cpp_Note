using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_CSharp_基础库入门.ClassTest
{
    class ClassPolymorphicPerson
    {
        public ClassPolymorphicPerson() { }

        public ClassPolymorphicPerson(string name)
        {
            this.Name = name;
        }

        private int _id;
        public int Id { get; set; }

        private string _name;
        public string Name { get; set; }

        public void SayHello()
        {
            Console.WriteLine("我是人类");
        }

        public virtual void SayHello_Virtual()
        {
            Console.WriteLine("我是人类--Virtual");
        }
    }

    class ClassPolymorphicChinese : ClassPolymorphicPerson
    {
        public ClassPolymorphicChinese(string name) : base(name) { }

        public new void SayHello()
        {
            Console.WriteLine("我是中国人");
        }

        public override void SayHello_Virtual()
        {
            Console.WriteLine("我是中国人--Virtual");
        }

        public void SayHello_Chinese()
        {
            Console.WriteLine("调用父类没有的方法");
        }
    }

    public interface IClassPolymorphicInterface
    {
        void SayHello_Interface();
        string InterfaceName { get; set; }
    }

    class ClassPolymorphicStudent : ClassPolymorphicPerson, IClassPolymorphicInterface
    {
        public void SayHello_Interface()
        {
            Console.WriteLine("调用接口方法");
        }
        public string InterfaceName { get; set; }
    }

    public static class ClassPolymorphic
    {
        public static void FuncTest_ClassPolymorphicBase()
        {
            ClassPolymorphicPerson p1 = new ClassPolymorphicChinese("jx");

            Console.WriteLine("被隐藏的方法：");
            p1.SayHello();
            Console.WriteLine("虚函数调用：");
            p1.SayHello_Virtual();

            ClassPolymorphicStudent p2 = new ClassPolymorphicStudent();
            Console.WriteLine("接口函数调用：");
            p2.InterfaceName = "interface";
            Console.WriteLine(p2.InterfaceName); // get set 会有一个默认实现
        }
    }
}
