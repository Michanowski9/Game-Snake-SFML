#include "Game.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600))
{
	//load textures

	//setup game variables
}

Game::~Game()
{

}

void Game::HandleInput()
{

}

void Game::Update()
{
	m_window.Update();
	//game update
}

void Game::Render()
{
	m_window.BeginDraw();
	//draw sprites
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
	m_elapsed = m_clock.restart();
}