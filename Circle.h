#pragma once
#include "Shapes.h"
class Circle :
    public Shapes
{

	public:
		Circle();
		Circle(int Radius);
		void setRadius(int radius);
		void draw();


	private:
		int radius;

	};


