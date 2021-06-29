#pragma once

#include <math.h>
#include "Screen.h"
#include <vector>


using namespace std;

//============= SHAPES CLASS ===========================
//=======================================================



class Shapes{
//abstract class for creating Shapes of different types
private:
	vector<int> xValsForShape;
	vector<int> yValsForShape;

	// set colours
	Uint8 R=0;
	Uint8 G=0;
	Uint8 B=0;

protected: 

	int Xpos; 
	int Ypos; 
	int size=100;
public: 
	Shapes();
	void setRGB(Uint8 Red, Uint8 Green, Uint8 Blue);
	void setR(int Red);
	void setG(int Green);
	void setB(int Blue);
	Uint8 getR();
	Uint8 getG();
	Uint8 getB();

	int getXpos();
	int getYpos();

	void pushBackX(int x);
	void pushBackY(int y);
	void setXpos(int x);
	void setYpos(int y);
	void setXandY(int x, int y);


	void setSize(int size);
	int getSize();

	virtual void draw()=0;

	void output(Screen screen);
	~Shapes();
};





