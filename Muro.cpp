#include "SFML/Graphics.hpp"
#include "Muro.h"
#include "Recursos.h"
#include "Ventana.h"
#include <iostream>

using namespace sf;

Muro::Muro() {

	setSprite(RUTA_MURO);
	setSize(68, 14);
	setCentro(this->getSize().x / 2, this->getSize().y / 2);
	setFrame(0, 0, 1, 1);

	distancia = 0.f;
	spawn.x = 0.f;
	spawn.y = 0.f;
	setPosicion(spawn.x, spawn.y);
}


void Muro::activar() {
	activa = true;
}

void Muro::setSpawn(float x, float y) {
	this->spawn.x = x;
	this->spawn.y = y;
}

