
class WhiteboardApp
{
public:
	WhiteboardApp();
	WhiteboardApp(sf::RenderWindow &window);

	void run();

private:
	sf::RenderWindow *appWindow = NULL;

	bool started = false;

};