#include "Rect.h"

Rect::Rect() {
	Xpos = 0;
	Ypos = 0;
	height = 0;
	width = 0;
	bottomXcoordinate = Xpos + height;
	bottomYcoordinate = Ypos + width;
}

Rect::Rect(int left, int top, int h, int w) {

	// left & top refer to the coordinates of the top left part of the rect

	Xpos = left;
	Ypos = top;
	height = h;
	width = w;

	bottomXcoordinate = Xpos + height;
	bottomYcoordinate = Ypos + width;



}

Rect::Rect(int left, int top, int h, int w, Uint8 R, Uint8 G, Uint8 B) {

	// left & top refer to the coordinates of the top left part of the rect


	setRGB(R, G, B);
	
	Xpos = left;
	Ypos = top;
	height = h;
	width = w;

	bottomXcoordinate = Xpos + height;
	bottomYcoordinate = Ypos + width;



}

void Rect::draw() {

	for (int x = Xpos; x < Xpos + width; x++) {
		for (int y = Ypos; y < Ypos+height; y++) {
			pushBackX(x);
			pushBackY(y);
		}
	}

}

void Rect::setHeight(int h) {
	height = h;
	bottomYcoordinate = h;
	
}
void Rect::setWidth(int w) {
	width = w;
	bottomXcoordinate = w;
	
}




;
