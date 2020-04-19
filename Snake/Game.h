#pragma once
#include "Window.h"
#include "Snake.h"
#include "World.h"

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
	World m_world;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};

