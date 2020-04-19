#include "Game.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 608)), m_snake(16), m_world(sf::Vector2u(800, 608),16)
{
	//load textures

	//setup game variables
}

Game::~Game()
{

}

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && m_snake.GetPhysicalDirection() != Direction::Right) {
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && m_snake.GetPhysicalDirection() != Direction::Left) {
		m_snake.SetDirection(Direction::Right);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && m_snake.GetPhysicalDirection() != Direction::Down) {
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && m_snake.GetPhysicalDirection() != Direction::Up) {
		m_snake.SetDirection(Direction::Down);
	}
}

void Game::Update()
{
	m_window.Update();
	float timestep = 1.0f / m_snake.GetSpeed();

	if (m_elapsed.asSeconds() >= timestep)
	{
		//game update
		m_snake.Update();
		m_world.Update(m_snake);
		while (!m_snake.IsAlive())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
			{
				m_snake.Reset();
			}
		}
		m_elapsed -= sf::seconds(timestep);
	}
}

void Game::Render()
{
	m_window.BeginDraw();
	m_world.Render(m_window);
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