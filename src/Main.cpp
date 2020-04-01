#include "Platform/Platform.hpp"

#include "Whiteboard/WhiteboardApp.h"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;

	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());

	unsigned int width = constants::windowWidth * screenScalingFactor;
	unsigned int height = constants::windowHeight * screenScalingFactor;

	window.create(sf::VideoMode(width, height), "Whiteboard");
	platform.setIcon(window.getSystemHandle());

	WhiteboardApp board(window);
	board.run();

	return 0;
}
