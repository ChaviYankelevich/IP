#pragma once
#include <fstream>
#include <string>
#include <vector>
class BMP
{
public:
	/*template<typename T>
	void WriteBytes(std::ofstream& ofs, T t);*/
	void BMP_WriteHeader(int width, int height, std::ofstream& ofs);
};

