#include "AssetLoader.hpp"

std::ifstream AssetLoader::OpenFile(const char* name)
{
	std::string upPath;
	std::string fullPath;
	std::ifstream file;
	for (int32_t i = 0; i < 10; i++) 
	{
		fullPath.assign(upPath);  // reset to current upPath.

		fullPath.append("Assets/");
		fullPath.append(name);
		file.open(fullPath);
		
		if (file)
		{
			return file;
		}

		upPath.append("../");
	}

	return file;
}