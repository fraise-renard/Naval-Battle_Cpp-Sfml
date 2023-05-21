/*
 * barco.h
 *
 *  Created on: 3 de abr. de 2023
 *      Author: hayde
 */

#ifndef BARCOS_BARCOS_H_
#define BARCOS_BARCOS_H_
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <enum/enum.h>
#include <cstdlib>

int perifericos(int g[][10], int i, int x, int y, Celulas barco, direcao dir, int id);
bool gen_boat(int g[][10], int len, int id);
bool repeat(int grid[][10], sf::RectangleShape boxes[10][10], int dim, int * all_boats);
int gen_game_matrix(int g[][10], sf::RectangleShape boxes[10][10], int dim);


#endif /* BARCOS_BARCOS_H_ */
