#pragma once

#include "Screen.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Draw
{
private:
	vector<int> xVals;
	vector<int> yVals;
public:
	void circle(int x, int y, int radius);
	void rect(int x, int y);

	void output(Screen screen);
	void output(Screen screen, int red, int blue, int green);



	~Draw();
};

