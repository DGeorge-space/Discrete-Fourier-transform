#pragma once
#include "Shapes.h"
class Rect :
    public Shapes
{
private:
    int height;
    int width;
    int bottomYcoordinate;
    int bottomXcoordinate;

public:
    Rect();
    Rect(int left, int top, int height, int width);
    Rect(int left, int top, int h, int w, Uint8 R, Uint8 G, Uint8 B);
    Rect(int left, int top);
    void setHeight(int h);
    void setWidth(int w);
    void draw();
    
};

