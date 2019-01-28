#pragma once
#include "Grid.hpp"
#include <memory>
#include "..\SGPE\Graphics.hpp"
#include <SFML/Graphics.hpp>


// TODO check all includes for duplicates and iostreams
// SFML window requires the renderwindow functions
class GraphicsSFML : public Graphics
{
private:
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<Canvas> canvas;
	// TODO: std::shared_ptr<Settings> settings;
public:
	GraphicsSFML(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Canvas> canvas) :Graphics(canvas), window(window), canvas(canvas) {};

	void Render() {
		window->clear();
		canvas->Render(window);
		window->display();
	};
};
