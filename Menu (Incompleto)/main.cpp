#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {

	srand(time(NULL));
	setbuf(stdout, NULL);

	//abrir a janela sfml
	sf::RenderWindow window(sf::VideoMode(900, 429), "Batalha Naval",
			sf::Style::Close | sf::Style::Titlebar);

	//Declara variaveis para SFML
	sf::Texture textureFundo;
	sf::Sprite fundoImage;

	sf::SoundBuffer bufferDropSound;
	sf::Sound dropSound;

	sf::SoundBuffer bufferOver;
	sf::Sound overSound;

	sf::Music rainMusic;

	sf::Font font;

	//adiciona a fonte
	font.loadFromFile("assets/pixel.ttf");

	//textos
	sf::Text texto = sf::Text{};

	sf::Text start("Batalha Naval", font, 75);
	start.setColor(sf::Color{58,68,84});
	start.setPosition(0, 0);

	sf::Text autoras("Desenvolvedoras: Mel, Nubia e Sarah dos Santos", font, 23);
	autoras.setColor(sf::Color{79,79,79});
	autoras.setPosition(0, 80);

	sf::Text startButton("Jogar", font, 32);
		    startButton.setPosition(350, 200);
		    startButton.setFillColor(sf::Color::Red);
		    startButton.setOutlineColor(sf::Color::White);
		    startButton.setOutlineThickness(2);

	window.setFramerateLimit(60); // Limita os frames
	window.setVerticalSyncEnabled(true);//limita a sincroniza��o

	//Icone da janela.
	sf::Image image = sf::Image { };
	image.loadFromFile("assets/doguinho.png");
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	//imagens e sons
	textureFundo.loadFromFile("assets/fundo_batalha.png");
	fundoImage.setTexture(textureFundo);

	bufferDropSound.loadFromFile("assets/musica_batalha.wav");
	dropSound.setBuffer(bufferDropSound);

	bufferOver.loadFromFile("assets/musica_batalha.wav");
	overSound.setBuffer(bufferOver);

	rainMusic.openFromFile("assets/musica_batalha.wav");
	// start the playback of the background music immediately
	rainMusic.setLoop(true);
	rainMusic.play();

	font.loadFromFile("assets/pixel.ttf");

	/**********************Loop do jogo**********************/
	while (window.isOpen()) {
		sf::Event event;

		//Trata as intera��es.
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed){
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left
					&& startButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				//start game
			}

		} //Fim do loop de eventos.



		/**********************Pinta o mundo**********************/

		window.clear(sf::Color::White);
		window.draw(fundoImage);
		window.draw(start);
		window.draw(autoras);
		window.draw(startButton);
		window.display();// Mostra na tela.

		sf::sleep(sf::milliseconds(10.0f));

	} //Fim do loop do jogo (janela aberta).

	return 0;
}
