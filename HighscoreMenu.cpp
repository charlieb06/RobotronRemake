#include "HighscoreMenu.h"

HighscoreMenu::HighscoreMenu(float width, float height)
{
	font.openFromFile("assets/font/robotron-2084.otf");
	//Text* text = new Text(font, sf::Color::Red, "Play", 30);
	Text* text1 = new Text(font);
	text1->setFillColor(sf::Color::Red);
	text1->setString("Press ESC to close");
	text1->setPosition(sf::Vector2(width / 20, height / (MAX_NUMBER_OF_ITEMS + 30) * 2));
	texts.push_back(text1);

	text2 = new Text(font);
	text2->setFillColor(sf::Color::White);
	text2->setString("Last score: " + std::to_string(score));
	text2->setPosition(sf::Vector2(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	texts.push_back(text2);

	text3 = new Text(font);
	text3->setFillColor(sf::Color::White);
	text3->setString("Highscore: " + std::to_string(highScore));
	text3->setPosition(sf::Vector2(width / 20, height / (MAX_NUMBER_OF_ITEMS + 2) * 1));
	texts.push_back(text3);
}

HighscoreMenu::~HighscoreMenu()
{
}
void HighscoreMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < texts.size(); i++)
	{
		window.draw(*texts[i]);
	}
}

void HighscoreMenu::PassScore(int currentScore, int highScoreP)
{
	score = currentScore; 
	highScore = highScoreP;
	text2->setString("Last score: " + std::to_string(score));
	text3->setString("Highscore: " + std::to_string(highScore));
}
