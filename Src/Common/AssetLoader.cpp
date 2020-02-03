#include "AssetLoader.hpp"
#include "SOIL.h"
#include <iostream>

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

std::string AssetLoader::GetFileRealPath(const char* name)
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
			return fullPath;
			file.close();
		}

		upPath.append("../");
	}
	return "";
}

unsigned char* AssetLoader::LoadImage(
	const char *filename,
	int *width, int *height, int *channels,
	int force_channels)
{
	unsigned char* imageData = SOIL_load_image(AssetLoader::GetFileRealPath(filename).c_str(), width, height, channels, force_channels);
	if (imageData == NULL)
	{
		std::cout << "ERROR::LoadImage FAIL!" << std::endl;
	}
	return imageData;
}

void AssetLoader::FreeImageData(
	unsigned char *img_data
)
{
	SOIL_free_image_data(img_data);
}

