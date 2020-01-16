#include "Level.h"
#include <math.h>

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects

	//rectangle
	rect.setSize(sf::Vector2f(50, 50));
	rect.setOrigin(50, 50);
	rect.setFillColor(sf::Color::Red);
	

	//rectangle red
	rectRed.setSize(sf::Vector2f(100, 100));
	rectRed.setPosition(300, 300);
	rectRed.setFillColor(sf::Color::Red);
	sf::Vector2f halfsize1 = rectRed.getSize();
	halfsize1.x /= 2.0f;
	halfsize1.y /= 2.0f;
	rectRed.setOrigin(halfsize1);

	// rectangle blue
	rectBlue.setSize(sf::Vector2f(75, 75));
	rectBlue.setPosition(300, 300);
	rectBlue.setFillColor(sf::Color::Blue);
	sf::Vector2f halfsize2 = rectBlue.getSize();
	halfsize2.x /= 2.0f;
	halfsize2.y /= 2.0f;
	rectBlue.setOrigin(halfsize2);

	//rectangle green
	rectGreen.setSize(sf::Vector2f(50, 50));
	rectGreen.setPosition(300, 300);
	rectGreen.setFillColor(sf::Color::Green);
	sf::Vector2f halfsize3 = rectGreen.getSize();
	halfsize3.x /= 2.0f;
	halfsize3.y /= 2.0f;
	rectGreen.setOrigin(halfsize3);

	//circle
	circle.setRadius(100);
	circle.setOrigin(100,100);
	circle.setPosition(600, 337);
	circle.setFillColor(sf::Color::White);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(3);

	//ball
	ball.setRadius(25);
	ball.setOrigin(50, 50);
	ball.setFillColor(sf::Color::Black);
	move.x = 1000;
	move.y = 400;

	//render text

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "error loading font";
	}

	text.setFont(font);
	text.setString("HELLO WORL");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(600,5);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	sf::Vector2f posF = static_cast<sf::Vector2f>(pos); //just takes the bits(11010100) from memory and pretends they are something else
	rect.setPosition(posF);

	//ball
	
	switch (top)
	{
	case true:
		if (move.y <= 400)
		{
			move.y++;
		}
		else top = false;

		break;
	case false:
		if (move.y >= 100)
		{
			move.y--;
		}
		else top = true;
	}

	
	
	ball.setPosition(move);

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	window->draw(rectRed);
	window->draw(rectBlue);
	window->draw(rectGreen);
	window->draw(text);
	
	window->draw(rect);
	
	window->draw(ball);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}