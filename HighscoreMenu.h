#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>

using namespace sf;
#define MAX_NUMBER_OF_ITEMS 3
class HighscoreMenu
{
public:
	HighscoreMenu(float width, float height);
	~HighscoreMenu();

	void draw(sf::RenderWindow& window);
	void PassScore(int currentScore, int highScoreP);
	sf::Font font;
	std::vector<sf::Text*> texts;
private:
	int score = 0;
	int highScore = 0;
	Text* text2;
	Text* text3;
};
