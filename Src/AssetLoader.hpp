#pragma once
#include <fstream>

class AssetLoader
{
public:
	static std::ifstream OpenFile(const char* name);
	static std::string GetFileRealPath(const char* name);
};