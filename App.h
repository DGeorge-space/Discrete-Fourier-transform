
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstring>
#include <SDL.h>
#include <vector>
#include "Screen.h"
#include "Circle.h"
#include "Rect.h"
#include "Spectrograph.h"
#include "DFT.h"

#pragma once

using namespace std;


class App
{
private:
	Screen screen;

	

public:
	App();

	void Run();
	std::vector<std::complex<double>> m_signal;
	void generateSignal(int N,double K);

	~App();

};

