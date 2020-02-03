#pragma once
#include <fstream>

class AssetLoader
{
public:
	static std::ifstream OpenFile(const char* name);
	static std::string GetFileRealPath(const char* name);

public:
	static unsigned char* LoadImage(
		const char *filename,
		int *width, int *height, int *channels,
		int force_channels
		);

	static void FreeImageData
	(
		unsigned char *img_data
	);
	
};