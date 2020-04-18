#pragma once
#include "Window.h"
#include "Snake.h"
class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();

	Window* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();
private:
	Window m_window;
	Snake m_snake;
	Direction m_nextDirection;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};

