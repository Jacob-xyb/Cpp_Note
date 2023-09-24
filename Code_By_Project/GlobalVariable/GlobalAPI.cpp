#include "GlobalAPI.h"

namespace Global
{
	GlobalAPI globalAPI;
}


GlobalAPI::GlobalAPI()
{
	std::cout << "GlobalAPI construct" << std::endl;
}

GlobalAPI::~GlobalAPI()
{
	std::cout << "GlobalAPI destruct" << std::endl;
}
