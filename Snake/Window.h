#pragma once

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();
	Window(const std::string &l_title, const sf::Vector2u &l_size);
	~Window();

	void BeginDraw();
	void EndDraw();

	void Update();

	void Draw(sf::Drawable &l_drawable);

	void ToggleFullScreen();
private:
	void Setup(const std::string &l_title, const sf::Vector2u &l_size);
	void Create();
	void Destroy();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isFullScreen;
};

