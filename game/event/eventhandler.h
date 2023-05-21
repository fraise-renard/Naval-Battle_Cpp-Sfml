/*
 * eventhandler.h
 *
 *  Created on: 2 de abr. de 2023
 *      Author: hayde
 */

#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "enum/enum.h"

void desenhaElementos(sf::RenderWindow &window, int matriz[][10], int dim,
		sf::Sprite bomba, sf::Texture hit, sf::Texture water);

void trataEventos(sf::RenderWindow *window, int matriz[10][10], sf::Sound *boom, sf::Sound *splash,
		int dim, float x, float y);

bool conta_barco(int matriz[10][10], int * total_boats);

#endif /* EVENTHANDLER_H_ */
