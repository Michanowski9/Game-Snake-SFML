#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Window.h"

class World
{
public:
	World(sf::Vector2u l_windowSize, int l_blockSize);
	~World();
	void SpawnApple();
	void Update(Snake &l_player);
	void Render(Window &l_window);
private:
	sf::Vector2i m_applePosition;
	sf::Vector2u m_windowSize;
	sf::CircleShape m_appleShape;
	sf::RectangleShape m_boundsShape[4];
	int m_blockSize;
};

