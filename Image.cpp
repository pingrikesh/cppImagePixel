#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include "Image.h"


namespace myImage
{
	Image::Image(color c)
	{
		

		colorVec.push_back(c);
	}

	//
	void Image::test()
	{
		std::for_each(colorVec.begin(),
			colorVec.end(),
			[](const auto &e) {
			std::cout << static_cast<int>(e.r) << " ";
		});

	}


	void Image::ReadFromFile(std::string filename)
	{
		std::ifstream fin(filename.c_str(), std::ios::in | std::ios::binary);
		std::string magicNumber, garbage;
		unsigned int height, width;
		int maximum = 0;

		if (fin.is_open())
		{
			fin >> magicNumber;
			fin.ignore();
			std::getline(fin, garbage);
			fin >> height >> width;
			//std::cout << height << " " << width << std::endl;
			Image::nrow = height;
			Image::ncol = width;
			fin.ignore();
			fin >> maximum;
			color attr;
			unsigned char R, G, B;
			for (unsigned int itr = 0; itr < nrow; itr++)
			{
				for (unsigned int itc = 0; itc < ncol; itc++)
				{
					fin >> R >> G >> B;
					//std::cout << static_cast<int>(R) << static_cast<int>(G) << static_cast<int>(B) << std::endl;
					//std::cout << R << " " << G << " " << B << std::endl;
					attr.r = R;
					attr.g = G;
					attr.b = B;
					colorVec.push_back(attr);
				}
			}	
		}
		fin.close();
	}

	std::vector <unsigned int> Image:: averageCalculator()
	{
		std::vector <unsigned int> avgCol;
		unsigned int average = 0;
		std::for_each(colorVec.begin(),
			colorVec.end(),
			[&](const auto &e) {
			average = (e.r + e.b + e.g) / 3;
			//std::cout << average;
			avgCol.push_back(average);
		});

		return avgCol;
	}

	void Image::mapToHistogram(std::vector<unsigned int>& token, std::map<unsigned char, int>& histogram)
	{

		std::set<unsigned char> unique = std::set<unsigned char>(token.cbegin(), token.cend());


		for_each(unique.cbegin(), unique.cend(), [&](auto s) {histogram[s] = 0; });

		for_each(token.cbegin(), token.cend(), [&](auto s) {histogram[s]++; });
	}

	void Image:: writeToFile(std::map<unsigned char, int >& histogram)
	{

		std::ofstream fout("hw2_output.txt");
		if (fout.is_open())
		{
			std::cout << "Program runned successfully. Output file created." << std::endl;
			fout << std::setw(5) << "Average Color: " << std::setw(5) << "Frequency: " << std::endl;
			for (auto itr : histogram)
			{
				fout << std::setw(10) << static_cast<int>(itr.first) << std::setw(10) << itr.second << std::endl;
			}
		}

		fout.close();
	}



}

