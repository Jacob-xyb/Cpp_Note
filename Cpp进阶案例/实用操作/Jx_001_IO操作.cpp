//#include "../Jx_进阶案例.h"
//
////简单获取数据
//template<typename T>
//vector<T> JxTool_GetData(string filePath)
//{
//    vector<T> Array;
//    T temp;
//    std::ifstream infile(filePath);
//    if (!infile)
//    {
//        std::cout << "Unable to read file." << std::endl;
//        return Array;
//    }
//    while (!infile.eof())            // 若未到文件结束一直循环
//    {
//        infile >> temp;
//        Array.push_back(temp);
//    }
//    return Array;
//}