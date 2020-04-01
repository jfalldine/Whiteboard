#include "WhiteboardApp.h"

WhiteboardApp::WhiteboardApp()
{
	std::cout << "Whiteboard initialized with no sf::RenderWindow!";
}

WhiteboardApp::WhiteboardApp(sf::RenderWindow &window)
	: appWindow(&window)
{

}

void WhiteboardApp::run()
{
	if (!started)
	{
		started = true;

		sf::Texture whiteboardTexture;
		whiteboardTexture.loadFromFile("content/whiteboard.png");
		sf::Sprite whiteboardSprite(whiteboardTexture);

		sf::Event event;

		while (appWindow->isOpen())
		{
			while (appWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					appWindow->close();

				if (event.type == sf::Event::KeyReleased)
					if (event.key.code == sf::Keyboard::Escape)
						appWindow->close();
			}

			appWindow->clear(constants::clearColor);

			appWindow->draw(whiteboardSprite);

			appWindow->display();
		}
	}
}