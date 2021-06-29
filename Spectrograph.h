#pragma once

#include<vector>
#include "rect.h"
class Spectrograph
{

	
	std::vector<Rect*> binList;
	int padding;
	int screenHeight;
	int screenWidth;
	int binWidth;
	int binStartPosition;




public:
	Spectrograph(Screen scr);
	int numBins; //number of distinct rects to show 
	Spectrograph(Screen scr, int nBins);
	int calculateBinWidth();
	void setPadding(int paddingAmount);
	void initialiseBins();
	void draw();
	void outputSpectrograph(Screen screen);
	void updateBin(vector<double> binHeights);
	void resetHeights();
	~Spectrograph();
};

