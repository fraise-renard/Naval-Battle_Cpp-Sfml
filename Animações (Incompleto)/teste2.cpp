#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

int main1(int argc, char **argv) {

	// create the window
	sf::RenderWindow window(sf::VideoMode(900, 700), "Testes com animacoes");

	sf::Texture explosao[7];

	explosao[0].loadFromFile("assets/explosion.png", sf:: IntRect(0, 0, 32, 62));
	explosao[1].loadFromFile("assets/explosion.png", sf:: IntRect(32, 0, 32, 62));
	explosao[2].loadFromFile("assets/explosion.png", sf:: IntRect(69, 0, 32, 62));
	explosao[3].loadFromFile("assets/explosion.png", sf:: IntRect(100, 0, 32, 62));
	explosao[4].loadFromFile("assets/explosion.png", sf:: IntRect(138, 0, 32, 62));
	explosao[5].loadFromFile("assets/explosion.png", sf:: IntRect(170, 0, 34, 66));
	explosao[6].loadFromFile("assets/bombaImg_final.png");



	int textura_atual = 0;
	int f = 0;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (f == 134) {
			f = 0;
			if(textura_atual != 6)
			{
				textura_atual++;
			}

		}
		sf::Sprite bomm;
		bomm.setTexture(explosao[textura_atual]);
		bomm.setScale(4,4);
		bomm.setPosition(45,45);

		window.clear();

		window.draw(bomm);

		window.display();

		f++;

	}

}

/*
 * teste2.cpp
 *
 *  Created on: 12 de abr. de 2023
 *      Author: lucieny*
 * teste2ofc.cpp
 *
 *  Created on: 12 de abr. de 2023
 *      Author: lucieny
 */










