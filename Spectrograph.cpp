#include "Spectrograph.h"

#include <iostream>

Spectrograph::Spectrograph(Screen scr, int nBins) {

	numBins = nBins;
	padding = 4;
	screenHeight = scr.ScreenHeight;
	screenWidth = scr.ScreenWidth;
	calculateBinWidth();
	binStartPosition = 0;


}
Spectrograph::Spectrograph(Screen scr) {

	numBins = 32;
	padding = 10;
	screenHeight = scr.ScreenHeight;
	screenWidth = scr.ScreenWidth;
	binStartPosition = 0;

	calculateBinWidth();

}

int Spectrograph::calculateBinWidth() {
	int width = screenWidth / (numBins);
	binWidth = width;

	return width;


}

void Spectrograph::setPadding(int paddingAmount) {
	padding = paddingAmount;
}

void Spectrograph::initialiseBins() {
	
	
	for (int i = 0; i < numBins; i++) {

		int left = (i * binWidth) + padding;
		int width = binWidth;
		int binheight = 0;
		int top = screenHeight-binheight;

		binList.push_back(new Rect{left,top, binheight, width, 255,255,0});
		
	

	}
}

void Spectrograph::updateBin(vector<double> binHeights) {
	for (int i = 0; i < binHeights.size(); i++) {
		
		binList[i]->setHeight(binHeights[i]);
		binList[i]->setYpos(screenHeight - binHeights[i]);
		binList[i]->setRGB(200, (screenWidth/255)*i, (screenWidth / 255) * i);
		
		
	}

}

void Spectrograph::draw() {
	for (int i = 0; i < binList.size(); i++) {
		binList[i]->draw();

	}
}
void Spectrograph::outputSpectrograph(Screen screen) {
	for (int i = 0; i < binList.size(); i++) {
		binList[i]->output(screen);
	}
}

Spectrograph::~Spectrograph() {
	for (int i = 0; i < binList.size(); i++)
	{
		delete binList[i];
	}
}
void Spectrograph::resetHeights() {
	for (int i = 0; i < binList.size(); i++) {
		binList[i]->setHeight(0);
	}
}