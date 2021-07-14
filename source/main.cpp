#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

void addTriangle(int n, std::vector<sf::Vertex>& triangles, sf::Vector2f apex, double sideLenght)
{
	if(n > 0)
	{
		triangles.push_back(sf::Vertex(sf::Vector2f(apex.x - sideLenght * 0.5, apex.y - (sideLenght * sqrt(3.0)) * 0.5), 
									   sf::Color::Black));
		triangles.push_back(sf::Vertex(sf::Vector2f(apex.x + sideLenght * 0.5, apex.y - (sideLenght * sqrt(3.0)) * 0.5), 
									   sf::Color::Black));
		triangles.push_back(sf::Vertex(sf::Vector2f(apex.x, apex.y), 
									   sf::Color::Black));
										
		addTriangle(n - 1, 
					triangles, 
					sf::Vector2f(apex.x, apex.y - (sideLenght * sqrt(3.0)) * 0.5), 
					sideLenght * 0.5);
		addTriangle(n - 1, 
					triangles, 
					sf::Vector2f(apex.x - sideLenght * 0.5, apex.y), 
					sideLenght * 0.5);
		addTriangle(n - 1, 
					triangles, 
					sf::Vector2f(apex.x + sideLenght * 0.5, apex.y), 
					sideLenght * 0.5);
	}
}

int main()
{
	sf::Vector2f windowSize(800, 600);
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Sierpinski triangle generator");
	window.setFramerateLimit(60);
	
	double sideLenght{ 400.0 };

	sf::Vertex backgroundTriangle[]{
		sf::Vertex(sf::Vector2f(windowSize.x * 0.5, 100), sf::Color::White),
		sf::Vertex(sf::Vector2f(windowSize.x * 0.5 + sideLenght * 0.5, 100 + (sideLenght * sqrt(3.0)) * 0.5), 
				   sf::Color::White),
		sf::Vertex(sf::Vector2f(windowSize.x * 0.5 - sideLenght * 0.5, 100 + (sideLenght * sqrt(3.0)) * 0.5), 
				   sf::Color::White)
	};
	
	auto blackTriangles{ std::vector<sf::Vertex>() };
	addTriangle(7, 
			    blackTriangles, 
				sf::Vector2f(windowSize.x * 0.5, 100 + (sideLenght * sqrt(3.0)) * 0.5), 
				sideLenght * 0.5);

	sf::Event event;

    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
		
		window.clear();
		
		window.draw(backgroundTriangle, 3, sf::Triangles);
		window.draw(&blackTriangles.at(0), blackTriangles.size(), sf::Triangles);
		
		window.display();
    }

    return 0;
}