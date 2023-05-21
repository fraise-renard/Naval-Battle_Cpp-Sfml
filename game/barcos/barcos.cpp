/*
 * barcos.cpp
 *
 *  Created on: 3 de abr. de 2023
 *      Author: hayde
 */
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include "barcos.h"
#include "tile/tile.h"

/*for (int l = 0; l < 10; l++) {
		for (int c = 0; c < 10; c++) {H
			boxes[l][c] = criaRetangulo(l * dim, c * dim, dim, dim);
			matriz[l][c] = agua; //Tudo marcado como agua.
		}
}*/
int perifericos(int g[][10], int i, int x, int y, Celulas barco, direcao dir, int id){
	int error = 0, i2 = i, cont = 0;
	switch (dir){
		case VER:{
			cont = 0;
			for(i; i >= 0; i--){ //percorre todos os quadrados do barco, comecando do ultimo e indo ate o quadrado original
				if(i == i2){ //quadrado final
					//testes para quadrado final
					//esquerda e direita
					if(g[(x - i)][y-1] == submarino
					|| g[(x - i)][y-1] == submarino + 1
					|| g[(x - i)][y-1] == submarino + 2
					|| g[(x - i)][y-1] == submarino + 3
					|| g[(x - i)][y-1] == ctorpedo
					|| g[(x - i)][y-1] == ctorpedo + 1
					|| g[(x - i)][y-1] == ctorpedo + 2
					|| g[(x - i)][y-1] == tanque
					|| g[(x - i)][y-1] == tanque + 1
					|| g[(x - i)][y-1] == porta_avioes
					){ //se for barco -> GRUDADO
						break; //n pode
					}
					if(g[(x - i)][y+1] == submarino
					|| g[(x - i)][y+1] == submarino + 1
					|| g[(x - i)][y+1] == submarino + 2
					|| g[(x - i)][y+1] == submarino + 3
					|| g[(x - i)][y+1] == ctorpedo
					|| g[(x - i)][y+1] == ctorpedo + 1
					|| g[(x - i)][y+1] == ctorpedo + 2
					|| g[(x - i)][y+1] == tanque
					|| g[(x - i)][y+1] == tanque + 1
					|| g[(x - i)][y+1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					//para cima
					if(g[(x - i)-1][y] == submarino
					|| g[(x - i)-1][y] == submarino + 1
					|| g[(x - i)-1][y] == submarino + 2
					|| g[(x - i)-1][y] == submarino + 3
					|| g[(x - i)-1][y] == ctorpedo
					|| g[(x - i)-1][y] == ctorpedo + 1
					|| g[(x - i)-1][y] == ctorpedo + 2
					|| g[(x - i)-1][y] == tanque
					|| g[(x - i)-1][y] == tanque + 1
					|| g[(x - i)-1][y] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					//diagonais superiores esquerda e direita
					if(g[(x - i)-1][y-1] == submarino
					|| g[(x - i)-1][y-1] == submarino + 1
					|| g[(x - i)-1][y-1] == submarino + 2
					|| g[(x - i)-1][y-1] == submarino + 3
					|| g[(x - i)-1][y-1] == ctorpedo
					|| g[(x - i)-1][y-1] == ctorpedo + 1
					|| g[(x - i)-1][y-1] == ctorpedo + 2
					|| g[(x - i)-1][y-1] == tanque
					|| g[(x - i)-1][y-1] == tanque + 1
					|| g[(x - i)-1][y-1] == porta_avioes
					){ //se for barco -> GRUDADO
						break; //n pode

					}
					if(g[(x - i)-1][y+1] == submarino
					|| g[(x - i)-1][y+1] == submarino + 1
					|| g[(x - i)-1][y+1] == submarino + 2
					|| g[(x - i)-1][y+1] == submarino + 3
					|| g[(x - i)-1][y+1] == ctorpedo
					|| g[(x - i)-1][y+1] == ctorpedo + 1
					|| g[(x - i)-1][y+1] == ctorpedo + 2
					|| g[(x - i)-1][y+1] == tanque
					|| g[(x - i)-1][y+1] == tanque + 1
					|| g[(x - i)-1][y+1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					cont++;



				}else if(i == 0){ //quadrado inicial

					//testes para quadrado inicial
					//esquerda e direita
					if(g[(x - i)][y-1] == submarino
					|| g[(x - i)][y-1] == submarino + 1
					|| g[(x - i)][y-1] == submarino + 2
					|| g[(x - i)][y-1] == submarino + 3
					|| g[(x - i)][y-1] == ctorpedo
					|| g[(x - i)][y-1] == ctorpedo + 1
					|| g[(x - i)][y-1] == ctorpedo + 2
					|| g[(x - i)][y-1] == tanque
					|| g[(x - i)][y-1] == tanque + 1
					|| g[(x - i)][y-1] == porta_avioes
					){ //se for barco -> GRUDADO
						break; //n pode
					}
					if(g[(x - i)][y+1] == submarino
					|| g[(x - i)][y+1] == submarino + 1
					|| g[(x - i)][y+1] == submarino + 2
					|| g[(x - i)][y+1] == submarino + 3
					|| g[(x - i)][y+1] == ctorpedo
					|| g[(x - i)][y+1] == ctorpedo + 1
					|| g[(x - i)][y+1] == ctorpedo + 2
					|| g[(x - i)][y+1] == tanque
					|| g[(x - i)][y+1] == tanque + 1
					|| g[(x - i)][y+1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					//para baixo
					if(g[(x - i)+1][y] == submarino
					|| g[(x - i)+1][y] == submarino + 1
					|| g[(x - i)+1][y] == submarino + 2
					|| g[(x - i)+1][y] == submarino + 3
					|| g[(x - i)+1][y] == ctorpedo
					|| g[(x - i)+1][y] == ctorpedo + 1
					|| g[(x - i)+1][y] == ctorpedo + 2
					|| g[(x - i)+1][y] == tanque
					|| g[(x - i)+1][y] == tanque + 1
					|| g[(x - i)+1][y] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					//diagonais inferiores esquerda e direita
					if(g[(x - i)+1][y-1] == submarino
					|| g[(x - i)+1][y-1] == submarino + 1
					|| g[(x - i)+1][y-1] == submarino + 2
					|| g[(x - i)+1][y-1] == submarino + 3
					|| g[(x - i)+1][y-1] == ctorpedo
					|| g[(x - i)+1][y-1] == ctorpedo + 1
					|| g[(x - i)+1][y-1] == ctorpedo + 2
					|| g[(x - i)+1][y-1] == tanque
					|| g[(x - i)+1][y-1] == tanque + 1
					|| g[(x - i)+1][y-1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					if(g[(x - i)+1][y+1] == submarino
					|| g[(x - i)+1][y+1] == submarino + 1
					|| g[(x - i)+1][y+1] == submarino + 2
					|| g[(x - i)+1][y+1] == submarino + 3
					|| g[(x - i)+1][y+1] == ctorpedo
					|| g[(x - i)+1][y+1] == ctorpedo + 1
					|| g[(x - i)+1][y+1] == ctorpedo + 2
					|| g[(x - i)+1][y+1] == tanque
					|| g[(x - i)+1][y+1] == tanque + 1
					|| g[(x - i)+1][y+1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					cont++;


				}else{ //quadrados do meio

					//testes para quadrados do meio
					//esquerda e direita
					if(g[(x - i)][y-1] == submarino
					|| g[(x - i)][y-1] == submarino + 1
					|| g[(x - i)][y-1] == submarino + 2
					|| g[(x - i)][y-1] == submarino + 3
					|| g[(x - i)][y-1] == ctorpedo
					|| g[(x - i)][y-1] == ctorpedo + 1
					|| g[(x - i)][y-1] == ctorpedo + 2
					|| g[(x - i)][y-1] == tanque
					|| g[(x - i)][y-1] == tanque + 1
					|| g[(x - i)][y-1] == porta_avioes
					){ //se for barco -> GRUDADO
						break; //n pode
					}
					if(g[(x - i)][y+1] == submarino
					|| g[(x - i)][y+1] == submarino + 1
					|| g[(x - i)][y+1] == submarino + 2
					|| g[(x - i)][y+1] == submarino + 3
					|| g[(x - i)][y+1] == ctorpedo
					|| g[(x - i)][y+1] == ctorpedo + 1
					|| g[(x - i)][y+1] == ctorpedo + 2
					|| g[(x - i)][y+1] == tanque
					|| g[(x - i)][y+1] == tanque + 1
					|| g[(x - i)][y+1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					cont++;


				}
			}


			if(cont == i2 + 1){ //quantidade de quadrados = len, teste de perifericos ok
				//por barcos e perifericos... SEM ULTRAPASSAR LIMITES!
				for(int k = i2; k >= 0; k--){
					if(k == i2) { //quadrado final
						g[(x - k)][y] = barco + id;
						if((x - k)-1 >= 0){ //cima apenas se x >= 0
							g[(x - k)-1][y] = periferico;
							if(y-1 >= 0){
								g[(x - k)-1][y-1] = periferico;
							}
							if(y+1 <= 9){
								g[(x - k)-1][y+1] = periferico;
							}
						}
						if(y-1 >= 0){
							g[(x - k)][y-1] = periferico;
						}
						if(y+1 <= 9){
							g[(x - k)][y+1] = periferico;
						}

					}else if(k == 0) { //quadrado inicial
						g[(x - k)][y] = barco + id;
						if((x - k)+1 <= 9){
							g[(x - k)+1][y] = periferico;
							if(y-1 >= 0){
								g[(x - k)+1][y-1] = periferico;
							}
							if(y+1 <= 9){
								g[(x - k)+1][y+1] = periferico;
							}
						}
						if(y-1 >= 0){
							g[(x - k)][y-1] = periferico;
						}
						if(y+1 <= 9){
							g[(x - k)][y+1] = periferico;
						}



					}else{ //quadrados do meio
						g[(x - k)][y] = barco + id;
						if(y-1 >= 0){
							g[(x - k)][y-1] = periferico;
						}
						if(y+1 <= 9){
							g[(x - k)][y+1] = periferico;
						}

					}

				}
				error = 1;
				return error;
			}else{ //deu ruim no teste
				error = -1;
				return error;
			}

			break;
		}
		case HOR:{
			cont = 0;
			for(i; i >= 0; i--){ //percorre todos os quadrados do barco, comecando do ultimo e indo ate o quadrado original
				if(i == i2){ //quadrado final

					//testes para quadrado final
					//cima e baixo
					if(g[(x - 1)][y + i] == submarino
					|| g[(x - 1)][y + i] == submarino + 1
					|| g[(x - 1)][y + i] == submarino + 2
					|| g[(x - 1)][y + i] == submarino + 3
					|| g[(x - 1)][y + i] == ctorpedo
					|| g[(x - 1)][y + i] == ctorpedo + 1
					|| g[(x - 1)][y + i] == ctorpedo + 2
					|| g[(x - 1)][y + i] == tanque
					|| g[(x - 1)][y + i] == tanque + 1
					|| g[(x - 1)][y + i] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					if(g[(x + 1)][y + i] == submarino
					|| g[(x + 1)][y + i] == submarino + 1
					|| g[(x + 1)][y + i] == submarino + 2
					|| g[(x + 1)][y + i] == submarino + 3
					|| g[(x + 1)][y + i] == ctorpedo
					|| g[(x + 1)][y + i] == ctorpedo + 1
					|| g[(x + 1)][y + i] == ctorpedo + 2
					|| g[(x + 1)][y + i] == tanque
					|| g[(x + 1)][y + i] == tanque + 1
					|| g[(x + 1)][y + i] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					//para frente
					if(g[x][(y + i)+1] == submarino
					|| g[x][(y + i)+1] == submarino + 1
					|| g[x][(y + i)+1] == submarino + 2
					|| g[x][(y + i)+1] == submarino + 3
					|| g[x][(y + i)+1] == ctorpedo
					|| g[x][(y + i)+1] == ctorpedo + 1
					|| g[x][(y + i)+1] == ctorpedo + 2
					|| g[x][(y + i)+1] == tanque
					|| g[x][(y + i)+1] == tanque + 1
					|| g[x][(y + i)+1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					//diagonais dianteiras superiores e inferiores
					if(g[x - 1][(y + i)+1] == submarino
					|| g[x - 1][(y + i)+1] == submarino + 1
					|| g[x - 1][(y + i)+1] == submarino + 2
					|| g[x - 1][(y + i)+1] == submarino + 3
					|| g[x - 1][(y + i)+1] == ctorpedo
					|| g[x - 1][(y + i)+1] == ctorpedo + 1
					|| g[x - 1][(y + i)+1] == ctorpedo + 2
					|| g[x - 1][(y + i)+1] == tanque
					|| g[x - 1][(y + i)+1] == tanque + 1
					|| g[x - 1][(y + i)+1] == porta_avioes
					){ //se for barco -> GRUDADO
						break; //n pode

					}
					if(g[x + 1][(y + i)+1] == submarino
					|| g[x + 1][(y + i)+1] == submarino + 1
					|| g[x + 1][(y + i)+1] == submarino + 2
					|| g[x + 1][(y + i)+1] == submarino + 3
					|| g[x + 1][(y + i)+1] == ctorpedo
					|| g[x + 1][(y + i)+1] == ctorpedo + 1
					|| g[x + 1][(y + i)+1] == ctorpedo + 2
					|| g[x + 1][(y + i)+1] == tanque
					|| g[x + 1][(y + i)+1] == tanque + 1
					|| g[x + 1][(y + i)+1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					cont++;



				}else if(i == 0){ //quadrado inicial


					//testes para quadrado inicial
					//cima e baixo
					if(g[(x - 1)][y + i] == submarino
					|| g[(x - 1)][y + i] == submarino + 1
					|| g[(x - 1)][y + i] == submarino + 2
					|| g[(x - 1)][y + i] == submarino + 3
					|| g[(x - 1)][y + i] == ctorpedo
					|| g[(x - 1)][y + i] == ctorpedo + 1
					|| g[(x - 1)][y + i] == ctorpedo + 2
					|| g[(x - 1)][y + i] == tanque
					|| g[(x - 1)][y + i] == tanque + 1
					|| g[(x - 1)][y + i] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					if(g[(x + 1)][y + i] == submarino
					|| g[(x + 1)][y + i] == submarino + 1
					|| g[(x + 1)][y + i] == submarino + 2
					|| g[(x + 1)][y + i] == submarino + 3
					|| g[(x + 1)][y + i] == ctorpedo
					|| g[(x + 1)][y + i] == ctorpedo + 1
					|| g[(x + 1)][y + i] == ctorpedo + 2
					|| g[(x + 1)][y + i] == tanque
					|| g[(x + 1)][y + i] == tanque + 1
					|| g[(x + 1)][y + i] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					//para tras
					if(g[x][(y + i)-1] == submarino
					|| g[x][(y + i)-1] == submarino + 1
					|| g[x][(y + i)-1] == submarino + 2
					|| g[x][(y + i)-1] == submarino + 3
					|| g[x][(y + i)-1] == ctorpedo
					|| g[x][(y + i)-1] == ctorpedo + 1
					|| g[x][(y + i)-1] == ctorpedo + 2
					|| g[x][(y + i)-1] == tanque
					|| g[x][(y + i)-1] == tanque + 1
					|| g[x][(y + i)-1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					//diagonais anteriores superior e inferior
					if(g[x - 1][(y + i)-1] == submarino
					|| g[x - 1][(y + i)-1] == submarino + 1
					|| g[x - 1][(y + i)-1] == submarino + 2
					|| g[x - 1][(y + i)-1] == submarino + 3
					|| g[x - 1][(y + i)-1] == ctorpedo
					|| g[x - 1][(y + i)-1] == ctorpedo + 1
					|| g[x - 1][(y + i)-1] == ctorpedo + 2
					|| g[x - 1][(y + i)-1] == tanque
					|| g[x - 1][(y + i)-1] == tanque + 1
					|| g[x - 1][(y + i)-1] == porta_avioes
					){ //se for barco -> GRUDADO
						break; //n pode

					}
					if(g[x + 1][(y + i)-1] == submarino
					|| g[x + 1][(y + i)-1] == submarino + 1
					|| g[x + 1][(y + i)-1] == submarino + 2
					|| g[x + 1][(y + i)-1] == submarino + 3
					|| g[x + 1][(y + i)-1] == ctorpedo
					|| g[x + 1][(y + i)-1] == ctorpedo + 1
					|| g[x + 1][(y + i)-1] == ctorpedo + 2
					|| g[x + 1][(y + i)-1] == tanque
					|| g[x + 1][(y + i)-1] == tanque + 1
					|| g[x + 1][(y + i)-1] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					cont++;


				}else{ //quadrados do meio


					//testes para quadrados do meio
					//cima e baixo
					if(g[(x - 1)][y + i] == submarino
					|| g[(x - 1)][y + i] == submarino + 1
					|| g[(x - 1)][y + i] == submarino + 2
					|| g[(x - 1)][y + i] == submarino + 3
					|| g[(x - 1)][y + i] == ctorpedo
					|| g[(x - 1)][y + i] == ctorpedo + 1
					|| g[(x - 1)][y + i] == ctorpedo + 2
					|| g[(x - 1)][y + i] == tanque
					|| g[(x - 1)][y + i] == tanque + 1
					|| g[(x - 1)][y + i] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					if(g[(x + 1)][y + i] == submarino
					|| g[(x + 1)][y + i] == submarino + 1
					|| g[(x + 1)][y + i] == submarino + 2
					|| g[(x + 1)][y + i] == submarino + 3
					|| g[(x + 1)][y + i] == ctorpedo
					|| g[(x + 1)][y + i] == ctorpedo + 1
					|| g[(x + 1)][y + i] == ctorpedo + 2
					|| g[(x + 1)][y + i] == tanque
					|| g[(x + 1)][y + i] == tanque + 1
					|| g[(x + 1)][y + i] == porta_avioes
					){ //se for barco -> GRUDADO

						break; //n pode
					}
					cont++;

				}
			}
;

			if(cont == i2 + 1){ //quantidade de quadrados = len, teste de perifericos ok
				//por barcos e perifericos... SEM ULTRAPASSAR LIMITES!
				for(int k = i2; k >= 0; k--){
					if(k == i2) { //quadrado final
						g[x][y + k] = barco + id;
						if((y + k)+1 <= 9){ //frente apenas se (y + k)+1 <= 9
							g[x][(y + k)+1] = periferico;
							if(x-1 >= 0){
								g[x - 1][(y + k)+1] = periferico; //diagonal superior
							}
							if(x+1 <= 9){
								g[x + 1][(y + k)+1] = periferico; //diagonal inferior
							}
						}
						if(x-1 >= 0){
							g[x - 1][y + k] = periferico;
						}
						if(x+1 <= 9){
							g[x + 1][y + k] = periferico;
						}

					}else if(k == 0) { //quadrado inicial
						g[x][y + k] = barco + id;
						if((y + k)-1 >= 0){ //tras apenas se (y + k)-1 >= 0
							g[x][(y + k)-1] = periferico;
							if(x-1 >= 0){
								g[x - 1][(y + k)-1] = periferico; //diagonal superior
							}
							if(x+1 <= 9){
								g[x + 1][(y + k)-1] = periferico; //diagonal inferior
							}
						}
						if(x-1 >= 0){
							g[x - 1][y + k] = periferico;
						}
						if(x+1 <= 9){
							g[x + 1][y + k] = periferico;
						}


					}else{ //quadrados do meio
						g[x][y + k] = barco + id;
						if(x-1 >= 0){
							g[x - 1][y + k] = periferico;
						}
						if(x+1 <= 9){
							g[x + 1][y + k] = periferico;
						}

					}

				}
				error = 1;
				return error;
			}else{ //deu ruim no teste
				error = -1;
				return error;
			}
			break;
		}
	}
}
bool gen_boat(int g[][10], int len, int id){
	int x = 0, y = 0;
	direcao dir;
	Celulas barco = agua;
	int i = 0;
	int error = 0, it_count = 0;
	bool placing_fail = true;

	switch(len){

		case 2:
			barco = submarino;
			break;
		case 3:
			barco = ctorpedo;
			break;
		case 4:
			barco = tanque;
			break;
		case 5:
			barco = porta_avioes;
			break;
	};
	do{
		if(error != 1){
			it_count++;
		}
		if(it_count == 100){
			placing_fail = true;
			return placing_fail;
			break;

		}
		//randomiza dir e coordenadas do quadrado inicial
		dir = direcao(rand () % 2); //sao 2 direcoes disponiveis
		x = rand() % 10;
		y = rand() % 10;
		error = 0;


		//selecao de direcoes
		switch(dir) {
			case VER:{ //x--

				if(x == 0){ //NAO PODE IR PARA CIMA
					error = -1;

					continue;
				}

				i = len-1;
				//checa se todos os quadrados estao livres
				for(i; i >= 0; i--){
					if((x - i) < 0 || g[(x - i)][y] != agua){ //(x - tmp_len) < 0 } final do barco ultrapassa os limites

						error = -1;
						break;
					}
				}
				if (error == -1) {

					continue;
				}

				i = len-1;

				//coloca os quadrados
				error = perifericos(g, i, x, y, barco, dir, id);
				if(error == -1){

					continue;
				}

				break;
			}
			case HOR:{
				if(y == 9){ //NAO PODE IR PARA DIREITA
					continue; //continua o LOOP

				}
				i = len-1;
				//checa se todos os quadrados estao livres
				for(i; i >= 0; i--){
					if((y + i) > 9 || g[x][y + i] != agua){ //(x - tmp_len) < 0 } final do barco ultrapassa os limites

						error = -1;
						break;
					}
				}
				if (error == -1) {

					continue;
				}

				i = len-1;

				//coloca os quadrados
				error = perifericos(g, i, x, y, barco, dir, id);
				if(error == -1){

					continue;
				}

				break;
			}
		}
		error = 1;
	}while (error != 1); //enquanto der erro, rode

	placing_fail = false;
	return placing_fail;
}
bool repeat(int grid[][10], sf::RectangleShape boxes[10][10], int dim, int * all_boats){
	bool placing_fail = true;
	int sub_count = 0, ctorp_count = 0, tank_count = 0, plane_count = 0, totalboats;
	//Inicializa matriz como agua
	for(int l = 0; l < 10; l++){
		for(int c = 0; c < 10; c++){
			grid[l][c] = agua;
			boxes[l][c] = criaRetangulo(l * dim, c * dim, dim, dim);
		}
	}


	for(sub_count; sub_count < 4 ; sub_count++){
		placing_fail = gen_boat(grid,2,sub_count);
		if(placing_fail == true){
			break;
		}
	}

	for(ctorp_count; ctorp_count < 3 ; ctorp_count++){
		placing_fail = gen_boat(grid,3, ctorp_count);
		if(placing_fail == true){
			break;
		}

	}
	for(tank_count = 0; tank_count < 2 ; tank_count++){
		placing_fail = gen_boat(grid,4, tank_count);
		if(placing_fail == true){
			break;
		}
	}

	placing_fail = gen_boat(grid,5, plane_count);
	if(placing_fail != true){
		plane_count++;
	}

	totalboats = sub_count + ctorp_count + tank_count + plane_count;
	if(totalboats != 10){
		placing_fail = true;
		return placing_fail;
	}else{
		placing_fail = false;
		*all_boats = totalboats;
		return placing_fail;
	}
}
int gen_game_matrix(int g[][10], sf::RectangleShape boxes[10][10], int dim){

	int all_boats;
	srand(time(NULL));
	bool placing_fail = true;

	do{
		placing_fail = repeat(g, boxes, dim, &all_boats);
	}while(placing_fail);

	//DEBUG: Imprime a matriz no console
	for(int l = 0; l < 10; l++){
		for(int c = 0; c < 10; c++){
			if(c != 9){

				if (g[l][c] == periferico){ //periferico vira agua
					g[l][c] = agua;
					std::cout << g[l][c] << "\t";
				}else{
					std::cout << g[l][c] << "\t";
				}

			}else{

				if (g[l][c] == periferico){
					g[l][c] = agua;
					std::cout << g[l][c];
				}else{
					std::cout << g[l][c] << "\t";
				}

			}
		}
		std::cout << "\n";
	}
	return all_boats;

}

