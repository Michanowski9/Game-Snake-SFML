#include "World.h"

World::World(sf::Vector2u l_windowSize, int l_blockSize)
{
	m_blockSize = l_blockSize;
	m_windowSize = l_windowSize;
	SpawnApple();
	m_appleShape.setFillColor(sf::Color::Green);
	m_appleShape.setRadius(m_blockSize / 2);

	for (int i = 0; i < 4; i++) {
		m_boundsShape[i].setFillColor(sf::Color::White);
		if (i % 2 == 0) {
			m_boundsShape[i].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
		}
		else {
			m_boundsShape[i].setSize(sf::Vector2f(m_blockSize, m_windowSize.y));
		}

		if (i < 2){
			m_boundsShape[i].setPosition(0, 0);
		}
		else {
			m_boundsShape[i].setOrigin(m_boundsShape[i].getSize());
			m_boundsShape[i].setPosition(sf::Vector2f(m_windowSize));
		}
	}
}

World::~World()
{

}

void World::SpawnApple()
{
	int maxX = (m_windowSize.x / m_blockSize) - 2;
	int maxY = (m_windowSize.y / m_blockSize) - 2;
	m_applePosition = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
	m_appleShape.setPosition(m_applePosition.x * m_blockSize, m_applePosition.y * m_blockSize);
}

void World::Update(Snake &l_player)
{
	if (l_player.GetHeadPosition() == m_applePosition)
	{
		l_player.Extend();
		//Increase score
		do {
			SpawnApple();
		} while (!l_player.CheckFreeSpace(m_applePosition));
	}
	int gridSizeX = m_windowSize.x / m_blockSize;
	int gridSizeY = m_windowSize.y / m_blockSize;

	if (l_player.GetHeadPosition().x <= 0
		|| l_player.GetHeadPosition().y <= 0
		|| l_player.GetHeadPosition().x >= gridSizeX - 1
		|| l_player.GetHeadPosition().y >= gridSizeY - 1) {
		l_player.Lose();
	}
}

void World::Render(Window &l_window)
{
	for (auto bound : m_boundsShape){
		l_window.Draw(bound);
	}
	l_window.Draw(m_appleShape);
}