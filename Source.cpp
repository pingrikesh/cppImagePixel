#include <iostream>

#include "Image.h"

using namespace std;
using namespace myImage;

int main()
{
	Image *img1 = new Image(color{ 0, 0, 0 });
	
	img1->ReadFromFile("birds.ppm");
	
	vector <unsigned int> average = img1->averageCalculator();
	map<unsigned char, int> histogram;

	img1->mapToHistogram(average, histogram);
	img1->writeToFile(histogram);

	

	//system("pause");
	return 0;
}
