#include "App.h"

App::App() {


	// The screen object initialises the window, renderer, texture and buffers 1 & 2 as Null 
	
	Screen screen;
	
}

void App::Run() {
	//screen.init() sets the m_window object, with a name for the window, X & Y position [set to Undefined currently], and screen height and size:
// a possible optimisation here is to overload the init function with options for position, window width, height and name. 
// Further, might be better to split the init function into several for usability and improved experience. 
	
	if (screen.init() == false) {

		//if the function fails output a message to the console, may be better to do this using printf: 
			//cout << "Error initialising SDL" << endl;
		printf("Error initialising SDL, SDL Error: %s\n", SDL_GetError());
	}
	//This is the main 'game loop' where the magic happens

	int nSamples = 128;
	double kVal = 6.0;

	DFT dft(nSamples);

	generateSignal(nSamples,kVal);
	Spectrograph spectrograph(screen,nSamples/2);
	vector<double> binHeights = dft.setData(m_signal);
	
	for (int i = 0; i < binHeights.size(); i++)
	{
		binHeights[i]*= (screen.ScreenHeight*0.9);
	}

	spectrograph.initialiseBins();
	spectrograph.updateBin(binHeights);
	spectrograph.draw();

	while (true) {
		
		
	
		
		
		spectrograph.outputSpectrograph(screen);
		
		SDL_Delay(5);




		/* At the end of the loop the update function will update the texture from the data in the buffer, clear the renderer,
		* update the renderer with the updated texture and then present the renderer on to the window
		*/

		
		

		
	

		screen.update();
		/*
		A little box blur function that averages the colour RGB for a given pixel with its 9 near neighbours -
			possible optimisation:
				- only blur pixels that are not the same as the bakground colour
		*/
		//screen.boxBlur();

		
		//All Events handling goes on in screen. processEevents() 
		if (screen.processEvents() == false) {
			
			break; // exit the program 
		}
		
	}
	
}

void App::generateSignal(int N, double K) {

	int numSamples = N;
	double signalKVal = K;

	
	for (int i = 0; i < N; i++)
	{
		/*complex<double> currentSignal = 1 * (cos(2.0 * M_PI / static_cast<double>(N)) * signalKVal * static_cast<double>(i)) +
			0.5 * (sin((2.0 * M_PI * signalKVal * static_cast<double>(i)) / static_cast<double>(N))) +
			0.25* (sin((2.0 * M_PI * signalKVal * static_cast<double>(i)) / static_cast<double>(N)))+
			0.0005*(cos((2.0 * M_PI * signalKVal * static_cast<double>(i)) / static_cast<double>(N)) );*/

		complex<double> currentSignal = 2.5* (cos((2 * M_PI / static_cast<double>(N)) * signalKVal * static_cast<double>(i)))+
			0.5* (cos((2 * M_PI / static_cast<double>(N)) * signalKVal*2 * static_cast<double>(i))) +
			1* (cos((2 * M_PI / static_cast<double>(N)) * signalKVal*5 * static_cast<double>(i))) +
			10 * (cos((2 * M_PI / static_cast<double>(N)) * signalKVal * 10 * static_cast<double>(i)))+
			5 * (cos((2 * M_PI / static_cast<double>(N)) * signalKVal * 100 * static_cast<double>(i)));
			
		m_signal.push_back(currentSignal);


	}
}


App::~App() {

	screen.close();
}