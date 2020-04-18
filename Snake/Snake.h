#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Window.h"

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};

enum class Direction {None, Left, Right, Up, Down};

class Snake
{
public:
	Snake(int l_blockSize, sf::Vector2u l_startPoint);
	~Snake();
	
	void SetDirection(Direction l_direction);

	void Move();
	void Eat();

	void Update();
	void Reset();

	void Render(Window &l_window);
private:
	int m_speed;
	int m_score;
	int m_blockSize;
	sf::RectangleShape m_bodyRectangle;
	std::vector<SnakeSegment> m_snakeBody;
	Direction m_direction;
};

