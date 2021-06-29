#pragma once
#include <vector>
#include <math.h>
#include <complex>

using namespace std;

class DFT
{
private:
	vector<complex<double>> signalWindow;
	int dftLen;


public:
	DFT();
	DFT(int n);
	const double PI = 3.14159265358979;
	void HannWindow(int N);
	vector<complex<double>> dft(vector<complex<double>> inputArray);
	vector<double> setData(const vector<complex<double>> data);
	
};

