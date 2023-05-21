/*
 * tile.h
 *
 *  Created on: 2 de abr. de 2023
 *      Author: hayde
 */

#ifndef TILE_H_
#define TILE_H_
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "enum/enum.h"

sf::RectangleShape criaRetangulo(int x, int y, int width, int height);
void desenhaRetangulos(sf::RenderWindow &window,
		sf::RectangleShape boxes[10][10], float x, float y, int matriz[10][10]);




#endif /* TILE_H_ */
