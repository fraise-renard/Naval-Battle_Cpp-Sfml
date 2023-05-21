#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <time.h>
#include <SFML/Graphics/Text.hpp>
#include <cstdlib>
#include "tile/tile.h"
#include "barcos/barcos.h"
#include "event/eventhandler.h"
#include "enum/enum.h"

//A fun��o main � usada como fun��o pricipal do jogo chamando fun��es auxiliares.
int main() {
	/**********************Inicializa Objetos do Jogo**********************/

	const int LARGURA = 1400;
	const int ALTURA = 900;
	int dim = 90;
	bool wingame;
	std::string str_boats_left;


	//Painel
	sf::Texture texturePainel;
	texturePainel.loadFromFile("assets/painel.png");

	sf::Sprite painel;
	painel.setTexture(texturePainel);
	painel.setPosition(900,0);

	//Texto
	sf::Font lomo5;
	lomo5.loadFromFile("assets/LomoWebPixelLTStd-5.ttf");

	sf::Text msg;
	msg.setFont(lomo5);
	msg.setColor(sf::Color{58,68,84});
	msg.setCharacterSize(25);
	msg.setPosition(980,550);
	msg.setString("Total de barcos: ");


	sf::RenderWindow window(sf::VideoMode(LARGURA, ALTURA), "Batalha Naval - MSN",
					sf::Style::Close | sf::Style::Titlebar);
			window.setFramerateLimit(60); // Limita os frames
			window.setVerticalSyncEnabled(true); //limita a sincroniza��o

	//Icone da janela.
	sf::Image image = sf::Image { };
	image.loadFromFile("assets/barquinho.png");
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	//Matriz logica e grafica
	sf::RectangleShape boxes[10][10]; //Matriz para desnhar os ret�ngulos.
	int matriz[10][10]; //Matriz para determinar se h� algo na posi��o.

	/********** Declaracao das texturas para a animacao da agua no jogo **********/
	sf::Texture fundo[21];
		std::string textname;
		for(int i = 0; i < 21; i++){
			if(i < 9){
				textname = "assets/ocean/ocean0" + std::to_string(1+i) + ".png";
			}else if(i >= 9){
				textname = "assets/ocean/ocean" + std::to_string(1+i) + ".png";
			}
			fundo[i].loadFromFile(textname);
		};

		int textura_atual = 0; //para percorrer o vetor de texturas
		int frame = 0; //para contar os frames da animacao


	//posiciona barcos sem grudar, individuais e de todos os tipos, exatos 10 barcos

	int total_boats;

	total_boats = gen_game_matrix(matriz, boxes, dim);

	//A bomba
	sf::Sprite bomba;
	sf::Texture water_splash;
	sf::Texture explosion;
	water_splash.loadFromFile("assets/erro.png");
	water_splash.setSmooth(true);
	explosion.loadFromFile("assets/acerto.png");
	explosion.setSmooth(true);

	float scala= (float) dim / water_splash.getSize().x;
	bomba.setScale(scala,scala);

	//Som de explosao e agua
	sf::SoundBuffer boomBuffer;
	boomBuffer.loadFromFile("assets/boom.wav");
	sf::Sound boom;
	boom.setBuffer(boomBuffer);

	sf::SoundBuffer splashBuffer;
	splashBuffer.loadFromFile("assets/splash.wav");
	sf::Sound splash;
	splash.setBuffer(splashBuffer);

	/**********************Loop do jogo**********************/
	while (window.isOpen()) {

		/********** Sprites para a animacao da agua no jogo **********/

						//linha1
						sf::Sprite agua(fundo[textura_atual]);
						agua.setScale(1.052, 1);

						sf::Sprite agua2(fundo[textura_atual]);
						agua2.setScale(1.052, 1);
						agua2.setPosition(360, 0);

						sf::Sprite agua3(fundo[textura_atual]);
						agua3.setScale(1.052, 1);
						agua3.setPosition(720, 0);


						//linha2
						sf::Sprite agua4(fundo[textura_atual]);
						agua4.setScale(1.052, 1);
						agua4.setPosition(0, 180);

						sf::Sprite agua5(fundo[textura_atual]);
						agua5.setScale(1.052, 1);
						agua5.setPosition(360, 180);

						sf::Sprite agua6(fundo[textura_atual]);
						agua6.setScale(1.052, 1);
						agua6.setPosition(720, 180);


						//linha3
						sf::Sprite agua7(fundo[textura_atual]);
						agua7.setScale(1.052, 1);
						agua7.setPosition(0, 360);

						sf::Sprite agua8(fundo[textura_atual]);
						agua8.setScale(1.052, 1);
						agua8.setPosition(360, 360);

						sf::Sprite agua9(fundo[textura_atual]);
						agua9.setScale(1.052, 1);
						agua9.setPosition(720, 360);


						//linha4
						sf::Sprite agua10(fundo[textura_atual]);
						agua10.setScale(1.052, 1);
						agua10.setPosition(0, 540);

						sf::Sprite agua11(fundo[textura_atual]);
						agua11.setScale(1.052, 1);
						agua11.setPosition(360, 540);

						sf::Sprite agua12(fundo[textura_atual]);
						agua12.setScale(1.052, 1);
						agua12.setPosition(720, 540);


						//linha5
						sf::Sprite agua13(fundo[textura_atual]);
						agua13.setScale(1.052, 1);
						agua13.setPosition(0, 720);

						sf::Sprite agua14(fundo[textura_atual]);
						agua14.setScale(1.052, 1);
						agua14.setPosition(360, 720);

						sf::Sprite agua15(fundo[textura_atual]);
						agua15.setScale(1.052, 1);
						agua15.setPosition(720, 720);


						if (frame == 2)
						{
							frame = 0;

							if (textura_atual == 20)
							{
								textura_atual = 0;
							} else {
								textura_atual++;
							}
						}

		float x = sf::Mouse::getPosition(window).x;
		float y = sf::Mouse::getPosition(window).y;


		/**********************Pinta o mundo**********************/

		trataEventos(&window, matriz, &boom, &splash, dim, x, y);
		//Limpa a tela.
		window.clear(sf::Color::White);
		window.draw(agua);
		window.draw(agua2);
		window.draw(agua3);
		window.draw(agua4);
		window.draw(agua5);
		window.draw(agua6);
		window.draw(agua7);
		window.draw(agua8);
		window.draw(agua9);
		window.draw(agua10);
		window.draw(agua11);
		window.draw(agua12);
		window.draw(agua13);
		window.draw(agua14);
		window.draw(agua15);
		window.draw(painel);

		desenhaRetangulos(window, boxes, x, y, matriz);
		desenhaElementos(window, matriz, dim, bomba, explosion, water_splash);
		wingame = conta_barco(matriz, & total_boats);
		if(wingame){
			std::cout << "\nVoce venceu parabens!";
		}
		window.draw(msg);
		window.display(); // Mostra na tela.
		frame++;

		sf::sleep(sf::milliseconds(50.0f)); //Aguarda.


	} //Fim do loop do jogo (janela aberta).

	return 0;
}
