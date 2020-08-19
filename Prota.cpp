#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Color.hpp"
#include "Prota.h"
#include "Admin.h"
#include "Muñequito.h"
#include "Jugador.h"
#include "Muro.h"
#include "Recursos.h"
#include "Creditos.h"
#include <time.h>
#include <iostream>
#include <random>
#include <ctime>
#include <SFML\Audio.hpp>


using namespace sf;
using namespace std;

Prota Prota::m_Prota;

void Prota::Iniciar() {
	avanzar = false;
	salir = false;
	
	Ventana &ventana = *Ventana::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();
	fondo = new Muñequito(RUTA_FONDO);
	jugador.iniciar();
	
	fuente1 = new Font();
	fuente1->loadFromFile(RUTA_FONT_W);
	scoreText = new Text();
	scoreText->setFont(*fuente1);
	scoreText->setPosition(360, 0);
	scoreText->setString(std::to_string(score));

	reloj1 = new Clock();
	tiempo1 = new Time();
	tiempo2 = 0.f;

	uniform_int_distribution<unsigned> x(30, 450 - muro->getSize().x);
	uniform_int_distribution<unsigned> y(100, 533);
	default_random_engine a(time(0));
	for (size_t i = 0; i < 6; ++i){
		muro[i].x = x(a);
		muro[i].y = y(a);
	}

}

void Prota::Limpiar() {
	fondo->~Muñequito();
	delete fuente1;
	delete scoreText;
	delete reloj1;
	delete tiempo1;
}


void Prota::ProcesarEventos(Admin* gameadm) {
	Ventana &ventana = *Ventana::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();

	*tiempo1 = reloj1->getElapsedTime();
	tiempo2 = tiempo1->asSeconds()/6;

	Event evento;
	if (ventana.ventana.pollEvent(evento)) {
		switch (evento.type) {
		case Event::Closed:
			gameadm->Salir();
			break;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		playerX += 4;
		jugador.setFrame(0, 1, 1, 1);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		playerX -= 4;
		jugador.setFrame(0, 0, 1, 1);
	}
	
	if (playerX > 450)
		playerX = 0;
	if (playerX < -30)
		playerX = ventana.ventana.getSize().x - jugador.getSize().x;


	// la puntuacion no aumenta en esta situacion
	if (playerY == height && dy < (-1.62)){
		score += 1;
		scoreText->setString(std::to_string(score));
	}

	dy += 0.2;
	playerY += dy;

	uniform_int_distribution<unsigned> x(30, 450 - muro->getSize().x);
	uniform_int_distribution<unsigned> y(100, 533);
	default_random_engine e(time(0));

	if (playerY < height)
		for (int i = 0; i < 8; ++i){
			playerY = height;
			muro[i].y -= dy; 
			if (muro[i].y > 533){ // establecer nuevo muro en la parte superior
				muro[i].y = 0;
				muro[i].x = x(e);
			}
		}

	for (int i = 0; i < 8; ++i){
		if ((playerX + PLAYER_RIGHT_BOUNDING_BOX > muro[i].x) && (playerX + PLAYER_LEFT_BOUNDING_BOX < muro[i].x + muro[i].getSize().x)   
			&& (playerY + PLAYER_BOTTOM_BOUNDING_BOX > muro[i].y) && (playerY + PLAYER_BOTTOM_BOUNDING_BOX < muro[i].y + muro[i].getSize().y)  
			&& (dy > 0)){
			dy = -10;
		}
	}
	jugador.setPosicion(playerX, playerY);


	if (jugador.getPosicion().y > 560) {
		jugador.setPosicion(210, 0);
		jugador.setFrame(1, 2, 1, 1);
		jugador.caida(tiempo2);
	}
}

void Prota::Actualizar(Admin* gameadm) {
	Ventana &ventana = *Ventana::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();

	if (jugador.getPosicion().y > 560) {
		jugador.setPosicion(210, 0);
		jugador.setFrame(1, 2, 1, 1);
		jugador.caida(tiempo2);
		if (jugador.getPosicion().y > 570) {
			avanzar = true;
		}

		ofstream archivo;
		archivo.open("puntos.txt", ios::out);
		archivo << std::to_string(score);
		archivo.close();
	}
	

	if (avanzar) {
		gameadm->CambiarEstado(Creditos::Instancia());
	}
}

void Prota::Dibujar(Admin* gameadm) {
	Ventana &ventana = *Ventana::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();

	fondo->dibujar();	
	for (int i = 0; i < 8; i++) {
		muro->setPosicion(muro[i].x, muro[i].y);
		muro->dibujar();
	}
	jugador.dibujar();
	ventana.ventana.draw(*scoreText);
}