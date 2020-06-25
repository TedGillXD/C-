#pragma once
#include <iostream>
#include <sstream>

template<class Type>
Type StringToNum(const std::string& str)
{
	Type Num;
	std::istringstream iss;
	iss >> Num;
	return Num;
}

