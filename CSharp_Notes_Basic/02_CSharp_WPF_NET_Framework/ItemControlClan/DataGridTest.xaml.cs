using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace _02_CSharp_WPF_NET_Framework.ItemControlClan
{
    class GenerateIndexConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            DataGridRow row = value as DataGridRow;
            if (row != null)
                return row.GetIndex() + 1;
            else
                return -1;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }

    public class DataGridTestData : NotifyObject
    {
        private string _Name;
        public string Name
        {
            get {
                return _Name;
            }
            set
            {
                _Name = value;
                RaisePropertyChanged();
            }
        }
        public int Age { get; set; }
        public int Id { get; set; }
    }

    /// <summary>
    /// DataGridTest.xaml 的交互逻辑
    /// </summary>
    public partial class DataGridTest : Window
    {

        private ObservableCollection<DataGridTestData> _Data = new ObservableCollection<DataGridTestData>() {
            new DataGridTestData() { Name="Bob", Age=10, Id=0},
            new DataGridTestData() { Name="Tom", Age=30, Id=1},
            new DataGridTestData() { Name="Tim", Age=24, Id=2},
            new DataGridTestData() { Name="Jacob", Age=18, Id=3},
        };
        public ObservableCollection<DataGridTestData> Data
        {
            get { return _Data; }
            set { _Data = value; }
        }

        public DataGridTest()
        {
            InitializeComponent();
            this.dataGrid1.DataContext = this.Data;
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            int count = this.Data.Count;
            this._Data[0].Name = "修改后的名字";
            this.Data.Add(new DataGridTestData() { Name = "new User", Age = 18, Id = count });
        }
    }
}
