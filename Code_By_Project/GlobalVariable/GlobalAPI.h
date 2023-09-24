#pragma once
#include <iostream>
#include "People.h"

class GlobalAPI
{
public:
	GlobalAPI();
	~GlobalAPI();

	People m_people;
	std::string m_name;
};

namespace Global
{
	extern GlobalAPI globalAPI;
}

