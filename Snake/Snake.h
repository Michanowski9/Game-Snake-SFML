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
	Snake(int l_blockSize);
	~Snake();
	
	void SetDirection(Direction l_direction);
	Direction GetDirection();
	int GetSpeed();
	sf::Vector2i GetHeadPosition();

	void Update();
	void Reset();

	void Lose();
	bool IsAlive();
	void Extend();

	void Render(Window &l_window);
	Direction GetPhysicalDirection();
	bool CheckFreeSpace(sf::Vector2i l_toCheckPosition);
private:
	void Move();
	void CheckCollision();

	int m_speed;
	int m_score;
	int m_blockSize;
	bool m_isAlive;
	sf::RectangleShape m_bodyRectangle;
	std::vector<SnakeSegment> m_snakeBody;
	Direction m_direction;
};

