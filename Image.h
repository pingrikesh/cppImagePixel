 #ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct color
{
//public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
};


namespace myImage
{
	class Image
	{
	public:
		//Image();
		Image(color c);
		//Image(const Image& s);
		//void WriteAll(std::string filename);
		//void WriteAllB(std::string filename);
		//Image AbsDifference(const Image& source);
		//You need to implement
		void ReadFromFile(std::string filename);
		void test();
		std::vector <unsigned int> averageCalculator();
		void mapToHistogram(std::vector<unsigned int>& token, std::map<unsigned char, int>& histogram);
		void writeToFile(std::map<unsigned char, int >& histogram);

		//Image CircularShift();
		//Image SpatialDifference();
	private:
		//static const int NROWS = 6000;
		 //static const int NCOLS = 4000;
		//color arr[NROWS][NCOLS];
		unsigned int nrow, ncol;
		std::vector <color> colorVec;
		
	};

}

#endif