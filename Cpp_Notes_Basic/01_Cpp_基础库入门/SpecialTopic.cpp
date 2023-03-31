#include "SpecialTopic.h"

void SpecialTopic::Func_memset() {
	char cFilePath[_MAX_PATH];
	//for (int i = 0; i < sizeof(cFilePath); i++)
	//{
	//	std::cout << cFilePath[i];
	//}
	memset(cFilePath, '\0', _MAX_PATH);
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < sizeof(cFilePath); i++)
	{
		std::cout << cFilePath[i];
	}
}
