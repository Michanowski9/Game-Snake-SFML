#include "Window.h"

Window::Window()
{
	Setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string &l_title, const sf::Vector2u &l_size)
{
	Setup(l_title, l_size);
}

Window::~Window()
{
	Destroy();
}

void Window::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}

void Window::EndDraw()
{
	m_window.display();
}

void Window::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			m_isOpen = false;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			ToggleFullScreen();
		}
	}
}

bool Window::IsOpen()
{
	return m_isOpen;
}

void Window::Draw(sf::Drawable &l_drawable)
{
	m_window.draw(l_drawable);
}

void Window::ToggleFullScreen()
{
	m_isFullScreen = !m_isFullScreen;
	Destroy();
	Create();
}


void Window::Setup(const std::string &l_title, const sf::Vector2u &l_size)
{
	m_windowSize = l_size;
	m_windowTitle = l_title;
	m_isFullScreen = false;
	m_isOpen = true;
	Create();
}

void Window::Create()
{
	auto style = (m_isFullScreen ? sf::Style::Fullscreen : sf::Style::None);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}

void Window::Destroy()
{
	m_window.close();
}