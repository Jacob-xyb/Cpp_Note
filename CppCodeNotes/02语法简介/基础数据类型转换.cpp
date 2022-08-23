#include "Transfer.h"
#include <string>

void dataType_TypeConversion()
{
	// num to string
	int numI = 100;
	double numD = 100;
	float numF = 100;
	std::string strI = std::to_string(numI);
	std::string strD = std::to_string(numD);
	std::string strF = std::to_string(numF);

	// string to num
	std::string str = "100";
	numI = std::stoi(str);
	numD = std::stod(str);
	numF = std::stof(str);
}
