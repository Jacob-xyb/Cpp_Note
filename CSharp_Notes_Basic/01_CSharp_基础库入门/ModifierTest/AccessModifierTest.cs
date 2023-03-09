using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_CSharp_基础库入门.ModifierTest
{
    public static class AccessModifierTest
    {
    }

    #region Class 层面
    public class PublicClassObject
    {
        public string Name { get; set; }
    }

    internal class InternalClassObject
    {
        public string Name { get; set; }
    }
    #endregion
}
