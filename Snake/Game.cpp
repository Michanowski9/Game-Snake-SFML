#include "Game.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)), m_snake(16)
{
	//load textures

	//setup game variables
}

Game::~Game()
{

}

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && m_snake.GetDirection() != Direction::Right) {
		m_nextDirection = Direction::Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && m_snake.GetDirection() != Direction::Left) {
		m_nextDirection = Direction::Right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && m_snake.GetDirection() != Direction::Down) {
		m_nextDirection = Direction::Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && m_snake.GetDirection() != Direction::Up) {
		m_nextDirection = Direction::Down;
	}
}

void Game::Update()
{
	m_window.Update();
	float timestep = 1.0f / m_snake.GetSpeed();

	if (m_elapsed.asSeconds() >= timestep)
	{
		//game update
		m_snake.SetDirection(m_nextDirection);
		m_snake.Update();
		m_elapsed -= sf::seconds(timestep);
	}
}

void Game::Render()
{
	m_window.BeginDraw();
	m_snake.Render(m_window);
	m_window.EndDraw();
}

Window* Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	m_elapsed += m_clock.restart();
}