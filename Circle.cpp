#include "Circle.h"


//CIRCLE METHODS:

Circle::Circle() {
	radius = 10;
}
Circle::Circle(int Radius) {
	radius = Radius;
}
void Circle::setRadius(int radius) {
	radius = radius;
}
void Circle::draw() {
	const float PI = 3.14159265;



	for (int i = 0; i < 361; i++) {
		int xp = getXpos() + radius * cos((i * PI) / 180);
		int yp = getYpos() + radius * sin((i * PI) / 180);

		pushBackX(xp);
		pushBackY(yp);

		


	}
}