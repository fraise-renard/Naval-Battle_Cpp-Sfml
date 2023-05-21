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

	sf::Texture splash[9];
	splash[0].loadFromFile("assets/splash.png", sf:: IntRect(0, 0, 61, 32));
	splash[1].loadFromFile("assets/splash.png", sf:: IntRect(62, 0, 61, 32));
	splash[2].loadFromFile("assets/splash.png", sf:: IntRect(124, 0, 61, 32));
	splash[3].loadFromFile("assets/splash.png", sf:: IntRect(186, 0, 61, 32));
	splash[4].loadFromFile("assets/splash.png", sf:: IntRect(0, 33, 61, 32));
	splash[5].loadFromFile("assets/splash.png", sf:: IntRect(62, 33, 61, 32));
	splash[6].loadFromFile("assets/splash.png", sf:: IntRect(124, 33, 61, 32));
	splash[7].loadFromFile("assets/splash.png", sf:: IntRect(186, 33, 61, 32));
	splash[8].loadFromFile("assets/agua_final.png");


	int textura_atual = 0;
	int f = 0;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (f == 85) {
			f = 0;
			if(textura_atual != 8)
			{
				textura_atual++;
			}
			//else{
			//	textura_atual = 0;
			//}
		}
		sf::Sprite respingos(splash[textura_atual]);
		respingos.setScale(4,4);

		window.clear();

		window.draw(respingos);

		window.display();

		f++;

	}

}

