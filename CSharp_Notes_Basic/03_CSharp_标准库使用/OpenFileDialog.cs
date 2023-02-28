using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Microsoft.Win32;

namespace _03_CSharp_标准库使用
{
    public class OpenFileDialogTest
    {
        public OpenFileDialog dlg = new OpenFileDialog();

        public void TestFunc_OpenFileDialog()
        {
            dlg.Reset();
            dlg.Title = "Open File";

            dlg.ShowDialog();
        }

    }
}
