﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Microsoft.Win32;

namespace _03_CSharp_标准库使用
{
    internal class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            OpenFileDialogTest test = new OpenFileDialogTest();
            test.TestFunc_OpenFileDialog();
            
            Console.ReadKey();
        }
    }
}
