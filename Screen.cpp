#include "Screen.h"

Screen::Screen() :
	m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {

}
// TODO Auto-generated constructor stub

bool Screen::init() {

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	// Create an application window with the following settings:
	m_window = SDL_CreateWindow("An SDL2 window",                // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		ScreenWidth,                               // width, in pixels
		ScreenHeight,                               // height, in pixels
		SDL_WINDOW_SHOWN                  // flags - see below
	);

	// Check that the window was successfully created
	if (m_window == NULL) {
		// In the case that the window could not be made...
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, ScreenWidth, ScreenHeight);

	if (m_renderer == NULL) {

		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {

		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	m_buffer1 = new Uint32[ScreenWidth * ScreenHeight];
	m_buffer2 = new Uint32[ScreenWidth * ScreenHeight];

	memset(m_buffer1, 0, ScreenHeight * ScreenWidth * sizeof(Uint32));
	memset(m_buffer2, 0, ScreenHeight * ScreenWidth * sizeof(Uint32));

	return true;
}


void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer1, ScreenWidth * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

	//stops unallocated memory being allocated. 
	if (x < 0 || x >= ScreenWidth || y < 0 || y >= ScreenHeight) {
		return;
	}
	Uint32 color = 0;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_buffer1[(y * ScreenWidth) + x] = color;
}

bool Screen::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;

}

void Screen::close() {
	delete[] m_buffer1;
	delete[] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);

	// Clean up
	SDL_Quit();

}
void Screen::boxBlur() {
	//swap buffers so pixel is in buffer w and we are drawing to buffer 1
	Uint32* temp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for (int y = 0; y < ScreenHeight; y++) {
		for (int x = 0; x < ScreenWidth; x++) {
			/*
			 * 0 0 0	sum over colour vals adjacent pixels and divide by near neighbours
			 * 0 1 0
			 * 0 0 0
			 */
			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;
			for (int row = -1; row <= 1; row++) {
				for (int col = -1; col <= 1; col++) {
					int currentX = x + col;
					int currentY = y + row;

					if (currentX >= 0 && currentX < ScreenHeight && currentY >= 0 && currentY < ScreenHeight) {
						Uint32 color = m_buffer2[currentY * ScreenWidth + currentX];
						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;

					}
				}
			}
			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;

			setPixel(x, y, red, green, blue);
		}
	}
}