#include "Draw.h"
#include "Screen.h"

void Draw::circle(int x, int y, int radius) {
	const float PI = 3.14159265;

	for(int i=0;i<361;i++){
		int xp= x + radius * cos((i * PI) / 180);
		int yp= y + radius * sin((i * PI) / 180);
		
		xVals.push_back(xp);
		yVals.push_back(yp);
		
	}
}

void Draw::rect(int x, int y) {
	const unsigned int size = 500;
	const int halfSize = size / 2;

	for (int j = 0; j < size; j++) {


		for (int i = -halfSize; i < halfSize; i++) {
			int xp = x + i;
			int yp = y + j;


			xVals.push_back(xp);
			yVals.push_back(yp);
		}
	}

}
void Draw::output(Screen screen) {
	int elapsed = SDL_GetTicks();
	unsigned char green = (1 + sin(elapsed * 0.0005)) * 128;
	unsigned char red = (1 + cos(elapsed * 0.005)) * 128;
	unsigned char blue = (1 + sin(elapsed * 0.0007)) * 128;
	
	for (int i = 0; i < xVals.size(); i++) {
		screen.setPixel(xVals[i], yVals[i], red, green, blue);
	}
}

void Draw::output(Screen screen, int red, int blue, int green) {
	int elapsed = SDL_GetTicks();


	for (int i = 0; i < xVals.size(); i++) {
		screen.setPixel(xVals[i], yVals[i], green, blue, red);
	}
}

Draw::~Draw() {
	{
		xVals.clear();
		yVals.clear();

	}

}