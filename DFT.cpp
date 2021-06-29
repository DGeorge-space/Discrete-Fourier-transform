#include "DFT.h"
#include "math.h"
#include <algorithm>




using namespace std;


DFT::DFT() {
	dftLen = 0;
}

void DFT::HannWindow(int N) {
	/*A Hann window is a window function that is zero valued
	outside of a specified window, this is important in signal 
	processing for clearning up signal noise*/


	//Cast N, the number of values in the array, to double:

	double ND = static_cast<double>(N);
	for (int n = 0; n < N; n++) {
		double nD = static_cast<double>(n);
		double realPart = 0.5 * (1.0 - cos((2.0 * PI * nD) / ND));
		signalWindow.push_back(std::complex<double>(realPart, 0.0));
	}
	dftLen = signalWindow.size();
	

};

DFT::DFT(int n) {

	dftLen = n;
}
vector<complex<double>> DFT::dft(vector<complex<double>> inputArray) {
	int N = inputArray.size();
	int K = N;
	// K and N are the number of samples in Fourier and real space respectively
	
	std::complex<double> intSum;

	//define and allocate memory for output
	std::vector<std::complex<double>> output;
	output.reserve(K);

	for (int k = 0; k < K; k++) {

		//solve for the real and imaginary parts of each complex n
		intSum = std::complex<double>(0, 0);
		for (int n = 0; n < N; n++) {
			double realPart = cos(((2 * PI) / N) * k * n);
			double imagPart = sin(((2 * PI) / N) * k * n);


			std::complex<double> w(realPart, -imagPart);
			intSum += inputArray[n] * w;
		}
		output.push_back(intSum);
	}
	return output;

};
vector<double> DFT::setData( vector<complex<double>> data) {

	//make a temporary copy of data so that the original cannot be modified. 
	std::vector<std::complex<double>> tempData;
	for (int i = 0; i < data.size(); i++) {
		tempData.push_back(data[i]);
	}
	
	//using the resize function we can truncate the vector if it is too long and pad with zero values if too short
	if (tempData.size() != dftLen) {
		tempData.resize(dftLen, std::complex<double>(0.0, 0.0));
	}

	//apply window function to temp data: 
	HannWindow(tempData.size());

	for (int i = 0; i < tempData.size(); i++){
		tempData[i] *= signalWindow[i];
	}

	//compute the DFT:

	std::vector<complex<double>> dftResults = dft(tempData);

	// compute power spectrum:

	std::vector<double> absDFT;

	for (int i = 0; i < dftResults.size();i++) {
		absDFT.push_back(abs(static_cast<std::complex<double>>(dftResults[i])));
	}

	double maxValue = *max_element(absDFT.begin(), absDFT.end());

	//maxValue is used to calculate the normalised power spectrum
	for (int i = 0; i< absDFT.size(); i++) {
		absDFT[i] /= maxValue;
	}

	/*convert to decibels(dB) only allow the first half of the power spectrum as it is repeated for negatives.
	
	Minimise the values below -30dB*/

	std::vector<double> powerSpectrum;
	for (int i = 0; i < (absDFT.size()/2); i++) {
		double tempValue = 10 * log10(absDFT[i]);
		if (tempValue < -30.0) {
			powerSpectrum.push_back(0.01);
		}
		else {
			powerSpectrum.push_back((tempValue + 30.0) / 30.0);
		}
	}
	return powerSpectrum;
	
};