/*
 * @Author: Jacob-xyb 949782197@qq.com
 * @Date: 2025-03-14 17:19:56
 * @LastEditors: Jacob-xyb 949782197@qq.com
 * @LastEditTime: 2025-03-17 09:31:58
 * @Description: Life is struggle.
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void split_by_stream();
void split_by_substr();

/// @brief Stream方法，此种方法只适用于字符分割
/// @param str 
/// @param delimiter 
/// @return 
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;
    while (std::getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

/// @brief find+substr方法,通用性较强
/// @param str 
/// @param delimiter 
/// @return 
std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);

    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }

    tokens.push_back(str.substr(start, end));
    return tokens;
}

int main() {

    split_by_stream();
    split_by_substr();
    return 0;
}

void split_by_stream()
{
	printf("** Start split_by_stream **\n");

    std::string str = "Hello,World,This,Is,A,Test";
    char delimiter = ',';
    std::vector<std::string> tokens = split(str, delimiter);

    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }
}

void split_by_substr()
{
    printf("** Start split_by_substr **\n");

    std::string str = "Hello,World,This,Is,A,Test";
    std::string delimiter = ",";
    std::vector<std::string> tokens = split(str, ",");

    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }
}