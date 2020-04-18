#include "Snake.h"

Snake::Snake(int l_blockSize)
{
	m_blockSize = l_blockSize;
	m_bodyRectangle.setSize(sf::Vector2f(m_blockSize - 1, m_blockSize - 1));
	Reset();
}

Snake::~Snake()
{

}

bool Snake::IsAlive()
{
	return m_isAlive;
}

void Snake::SetDirection(Direction l_direction)
{
	m_direction = l_direction;
}

Direction Snake::GetDirection()
{
	return m_direction;
}

int Snake::GetSpeed()
{
	return m_speed;
}

void Snake::Move()
{
	for (int i = m_snakeBody.size() - 1; i > 0; i--) {
		//this if is for growing
		if (i == m_snakeBody.size() - 1 && m_snakeBody[i].position == m_snakeBody[i - 1].position) {
			continue;
		}
		m_snakeBody[i].position = m_snakeBody[i - 1].position;
	}
	switch (m_direction)
	{
	case Direction::Left:
		--m_snakeBody[0].position.x;
		break;
	case Direction::Right:
		++m_snakeBody[0].position.x;
		break;
	case Direction::Up:
		--m_snakeBody[0].position.y;
		break;
	case Direction::Down:
		++m_snakeBody[0].position.y;
		break;
	default:
		break;
	}
}

void Snake::Update()
{
	if (m_snakeBody.empty()){
		return;
	}
	if (m_direction == Direction::None){
		return;
	}
	Move();
	CheckCollision();
}

void Snake::Lose()
{
	m_isAlive = false;
}

void Snake::CheckCollision()
{
	if (m_snakeBody.size() < 5){
		return;
	}
	for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); itr++)
	{
		if (m_snakeBody.begin()->position == itr->position)
		{
			Lose();
			break;
		 }
	}
}

void Snake::Extend()
{
	if (m_snakeBody.empty()) {
		return;
	}
	m_snakeBody.insert(m_snakeBody.begin() + 1, SnakeSegment(m_snakeBody[0].position.x, m_snakeBody[0].position.y));
}

void Snake::Render(Window &l_window)
{
	if (m_snakeBody.empty()) {
		return;
	}

	m_bodyRectangle.setFillColor(sf::Color::Magenta);
	for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); itr++)
	{
		m_bodyRectangle.setPosition(itr->position.x * m_blockSize, itr->position.y * m_blockSize);
		l_window.Draw(m_bodyRectangle);
	}

	m_bodyRectangle.setFillColor(sf::Color::Red);
	m_bodyRectangle.setPosition(m_snakeBody.begin()->position.x * m_blockSize, m_snakeBody.begin()->position.y * m_blockSize);
	l_window.Draw(m_bodyRectangle);
}

void Snake::Reset()
{
	m_snakeBody.clear();
	m_snakeBody.push_back(SnakeSegment(10, 10));
	m_snakeBody.push_back(SnakeSegment(9, 10));
	m_snakeBody.push_back(SnakeSegment(8, 10));
	m_snakeBody.push_back(SnakeSegment(7, 10));
	m_snakeBody.push_back(SnakeSegment(6, 10));
	m_snakeBody.push_back(SnakeSegment(5, 10));
	SetDirection(Direction::None);
	m_score = 0;
	m_speed = 3;
	m_isAlive = true;
}