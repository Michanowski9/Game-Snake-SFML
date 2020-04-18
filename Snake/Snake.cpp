#include "Snake.h"

Snake::Snake(int l_blockSize, sf::Vector2u l_startPoint)
{
	m_blockSize = l_blockSize;
	m_bodyRectangle.setSize(sf::Vector2f(m_blockSize - 1, m_blockSize - 1));
	Reset();
}

Snake::~Snake()
{

}

void Snake::SetDirection(Direction l_direction)
{
	m_direction = l_direction;
}

void Snake::Render(Window &l_window)
{
	
}

void Snake::Reset()
{
	m_snakeBody.clear();
	m_snakeBody.push_back(SnakeSegment(10,10));
	m_snakeBody.push_back(SnakeSegment(10,9));
	m_snakeBody.push_back(SnakeSegment(10,8));
	SetDirection(Direction::None);
	m_score = 0;
	m_speed = 10;
}