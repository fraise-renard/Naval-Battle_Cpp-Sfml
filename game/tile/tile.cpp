/*
 * tile.cpp
 *
 *  Created on: 2 de abr. de 2023
 *      Author: hayde
 */
/*
 * tile.hpp
 *
 *  Created on: 2 de abr. de 2023
 *      Author: hayde
 */

#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "tile.h"
#include "enum/enum.h"

//Define e cria um retangulo na tela.
//Entidade definida para desenhar a matriz na tela.
sf::RectangleShape criaRetangulo(int x, int y, int width, int height) {
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(1.0f);
	rectangle.setPosition(x, y);
	return rectangle;
}

void desenhaRetangulos(sf::RenderWindow &window,
		sf::RectangleShape boxes[10][10], float x, float y, int matriz[10][10]){

	sf::Color cor;
	for (int l = 0; l < 10; l++) {
		for (int c = 0; c < 10; c++) {
			if (boxes[l][c].getGlobalBounds().contains(x, y)) {
				if(matriz[l][c] == agua || matriz[l][c] == periferico || matriz[l][c] == acerto|| matriz[l][c] == erro){
					cor = sf::Color { 42, 219, 113, 80};
				}else{ //se for barco na matriz
					cor =  sf::Color {42, 219, 113, 80};
				}
			}else {
				cor = sf::Color { 255, 255, 255, 20 };
			}

			boxes[l][c].setFillColor(cor);
			window.draw(boxes[l][c]);
		}
	}
}







