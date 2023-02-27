using _02_CSharp_WPF_NET_Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02_CSharp_WPF_NET_Framework
{
    public class GridTestViewModel
    {
        private GridTest _window = null;

        public GridTestViewModel(GridTest window)
        {
            this._window = window;
        }
    }
}
