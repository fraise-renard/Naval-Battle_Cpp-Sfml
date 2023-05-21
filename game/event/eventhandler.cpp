/*
 * eventhandler.cpp
 *
 *  Created on: 2 de abr. de 2023
 *      Author: hayde
 */
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <iostream>
#include "enum/enum.h"
#include "event/eventhandler.h"
/*	float x, y;
	for (int l = 0; l < 10; l++) {
		for (int c = 0; c < 10; c++) {
			if (matriz[l][c] == ESTRELA) {
				x = l * dim;
				y = c * dim;
				starImage.setPosition(x, y);
				window.draw(starImage);
			}
		}
	}
}*/

void trataEventos(sf::RenderWindow *window, int matriz[10][10], sf::Sound *boom, sf::Sound *splash,
		int dim, float x, float y){
	//Trata as intera��es.
	sf::Event event;
	int linha, coluna;
	float x_bomb, y_bomb;

	while ((*window).pollEvent(event)) {
		if (event.type == sf::Event::Closed){
			(*window).close();
		}
		if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::getPosition(*window).x < 900) {

			linha = sf::Mouse::getPosition(*window).x / dim;
			coluna = sf::Mouse::getPosition(*window).y / dim;

			x_bomb = linha * dim;
			y_bomb = coluna * dim;

			if(matriz[linha][coluna] == agua){ //bomba na agua, errou o tiro
				matriz[linha][coluna] = erro;
				//bomba.setTexture(water_erro);
				(*splash).play();
			}else{
				//submarinos
				for(int i = 0; i < 4; i++){
					if(matriz[linha][coluna] == submarino + i){ //bomba no quadrado do barco, acertou o tiro
						matriz[linha][coluna] = acerto;
						//bomba.setTexture(acerto);
						(*boom).play();
					}

				}
				for (int i = 0; i < 3; i++) {
					if (matriz[linha][coluna] == ctorpedo + i) { //bomba no quadrado do barco, acertou o tiro
						matriz[linha][coluna] = acerto;
						//bomba.setTexture(acerto);
						(*boom).play();
					}
				}
				for (int i = 0; i < 2; i++) {
					if (matriz[linha][coluna] == tanque + i) { //bomba no quadrado do barco, acertou o tiro
						matriz[linha][coluna] = acerto;
						//bomba.setTexture(acerto);
						(*boom).play();
					}
				}
				if (matriz[linha][coluna] == porta_avioes) {
					matriz[linha][coluna] = acerto;
					//bomba.setTexture(acerto);
					(*boom).play();
				}
			}


		}
	} //Fim do loop de eventos.
}

void desenhaElementos(sf::RenderWindow &window, int matriz[10][10], int dim,
		sf::Sprite bomba, sf::Texture hit, sf::Texture water){

	float x, y;
		for (int l = 0; l < 10; l++) {
			for (int c = 0; c < 10; c++) {
				if (matriz[l][c] == acerto) {
					x = l * dim;
					y = c * dim;
					bomba.setTexture(hit);
					bomba.setPosition(x, y);
					window.draw(bomba);
				}
				if(matriz[l][c] == erro){
					x = l * dim;
					y = c * dim;
					bomba.setTexture(water);
					bomba.setPosition(x, y);
					window.draw(bomba);
				}
			}
		}
}

bool conta_barco(int matriz[10][10], int * total_boats){
	//numero de quadrados de cada barco
	int num_sub1, num_sub2, num_sub3, num_sub4;
	int num_ctorp1, num_ctorp2, num_ctorp3;
	int num_tank1, num_tank2, num_plane;

	bool win;

	win = false;
	num_sub1 = 0;
	num_sub2 = 0;
	num_sub3 = 0;
	num_sub4 = 0;
	num_ctorp1 = 0;
	num_ctorp2 = 0;
	num_ctorp3 = 0;
	num_tank1 = 0;
	num_tank2 = 0;
	num_plane = 0;

	for(int l = 0; l < 10; l++){
		for(int c = 0; c < 10; c++){
			//submarino
			if(matriz[l][c] == 21){
				num_sub1++;
			}
			if(matriz[l][c] == 22){
				num_sub2++;
			}
			if(matriz[l][c] == 23){
				num_sub3++;
			}
			if(matriz[l][c] == 24){
				num_sub4++;
			}
			if(matriz[l][c] == 31){
				num_ctorp1++;
			}
			if(matriz[l][c] == 32){
				num_ctorp2++;
			}
			if(matriz[l][c] == 33){
				num_ctorp3++;
			}
			if(matriz[l][c] == 41){
				num_tank1++;
			}
			if(matriz[l][c] == 42){
				num_tank2++;
			}
			if(matriz[l][c] == 51){
				num_plane++;
			}
		}
	}

	if(num_sub1 == 0 || num_sub2 == 0 || num_sub3 == 0 || num_sub4 == 0 ||
	num_ctorp1 == 0 || num_ctorp2 == 0 || num_ctorp3 == 0 ||
	num_tank1 == 0 || num_tank2 == 0 || num_plane == 0){
		*total_boats = *total_boats - 1;

	}

	if(*total_boats == 0){
		win = true;
	}else{
		win = false;
	}

	return win;
}



