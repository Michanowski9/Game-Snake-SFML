#include "Window.h"

Window::Window()
{
	Setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string &l_title, const sf::Vector2u &l_size) 
{
	m_windowSize = l_size;
	m_windowTitle = l_title;
	Setup(l_title, l_size);
}

