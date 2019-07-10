#pragma once
#include <fstream>

class AssetLoader
{
public:
	static std::ifstream OpenFile(const char* name);
};