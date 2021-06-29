#include "Shapes.h"


Shapes::Shapes() {
	Xpos = 0;
	Ypos = 0; 
	R = 0;
	G = 0;
	B = 0;
}

void Shapes::setRGB(Uint8 red, Uint8 green, Uint8 blue) {
	R = red;
	G = green;
	B = blue;
}
void Shapes::setR(int red) {
	R = red;
}
void Shapes::setG(int green) {
	G = green;

}
void Shapes::setB(int blue) {
	G = blue;

}
Uint8 Shapes::getR() {
	return R;
}
Uint8 Shapes::getG() {
	return G;
}
Uint8 Shapes::getB() {
	return B;
}

void Shapes::setSize(int size) {
	size = size;
}
int Shapes::getSize() {
	return size;
}

int Shapes::getXpos() {
	return Xpos;
}
int Shapes::getYpos() {
	return Ypos;
}

void Shapes::setYpos(int y) {
	Ypos = y;
}
void Shapes::setXpos(int x) {
	Xpos = x;
}
void Shapes::setXandY(int x, int y) {
	Xpos = x;
	Ypos = y;
}

void Shapes::pushBackX(int x) {
	xValsForShape.push_back(x);
}

void Shapes::pushBackY(int y) {
	yValsForShape.push_back(y);
}

void Shapes::output(Screen screen) {
	for (int i = 0; i < xValsForShape.size(); i++) {
		screen.setPixel(xValsForShape[i], yValsForShape[i], getR(), getG(), getB());
	}
}

Shapes::~Shapes() {

}




