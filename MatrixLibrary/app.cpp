#include <iostream>
#include <vector>
#include "Linear.h"
#include "SFML/Graphics.hpp"

class Cell {
	sf::Vector2f cellPosition;
	sf::Vector2f position;
	sf::Vector2f size;
};

class SnakeMap {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f mapSize;
public:
	SnakeMap();
	SnakeMap(sf::Vector2f position, sf::Vector2f size, sf::Vector2f mapSize);
	void setPosition(sf::Vector2f position);
	void setSize();
	void setMapSize();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	sf::Vector2f getMapSize();
	void draw(sf::RenderWindow& window);
};

SnakeMap::SnakeMap() {
}
SnakeMap::SnakeMap(sf::Vector2f position, sf::Vector2f size, sf::Vector2f mapSize) {
	this->position = position;
	this->size = size;
	this->mapSize = size;
}
void SnakeMap::setPosition(sf::Vector2f position) {
	this->position = position;
}
void SnakeMap::setSize() {
	this->size = size;
}
void SnakeMap::setMapSize() {
	this->mapSize = mapSize;
}
sf::Vector2f SnakeMap::getPosition() {
	return position;
}
sf::Vector2f SnakeMap::getSize() {
	return size;
}
sf::Vector2f SnakeMap::getMapSize() {
	return mapSize;
}
void SnakeMap::draw(sf::RenderWindow& window) {

	for (int i = 0; i < mapSize.x; i++)
	{
		for (int j = 0; j < mapSize.y; j++)
		{
			sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
		}
	}

}

int main() {

	setlocale(LC_ALL,"Russian");

	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	SnakeMap map();

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);




		window.display();
	}

	return 0;
}

//
//Matrix mat1{
//	4, 1,
//	{
//		1,
//		2,
//		3,
//		4,
//	}
//};
//Matrix mat2{
//	2, 4,
//	{
//		1,2,3,4,
//		5,6,7,8
//	}
//};
//Matrix mat3{
//	1, 4,
//	{
//		1,2,
//		3,4,
//	}
//};
//
//
////Matrix mat4 = mat1 + 1000 + mat2;
//Matrix mat5 = mat1 * mat3;
//Matrix mat6 = mat1 & mat1;
//
//mat5.print();
//mat6.print();