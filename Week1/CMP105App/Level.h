#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	void beginDraw();
	void endDraw();
	sf::RenderWindow* window;

	sf::RectangleShape rect;
	sf::RectangleShape rectRed;
	sf::RectangleShape rectBlue;
	sf::RectangleShape rectGreen;

	sf::CircleShape ball;
	sf::Vector2f move;
	bool top;
	


	sf::CircleShape circle;

	sf::Font font;
	sf::Text text;
};