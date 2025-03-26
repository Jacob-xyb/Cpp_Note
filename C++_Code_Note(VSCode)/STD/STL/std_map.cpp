/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2025-03-17 10:52:43
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2025-03-17 10:54:39
 * @Description: Life is struggle.
 */
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> myMap;

    // 插入元素
    myMap.insert({1, "apple"});
    myMap[2] = "banana";
    myMap[3] = "cherry";

    // 访问元素
    std::cout << "Key 1: " << myMap[1] << std::endl;
    // ++ 访问不存在的元素，会产生未知行为，但是此键会在此时被插入
    std::cout << "Key 4: " << myMap[4] << std::endl;

    // 查找元素
    auto it = myMap.find(4);
    if (it != myMap.end()) {
        std::cout << "Found: " << it->second << std::endl;
    }

    // 删除元素
    myMap.erase(1);

    // 遍历元素
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}