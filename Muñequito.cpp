#include <iostream>
#include "Muñequito.h"
#include "Ventana.h"

using namespace std;
using namespace sf;

Muñequito::Muñequito() {
	Cargado = false;
	setVelocidad(0.f, 0.f);
}

Muñequito::Muñequito(const char *texture) {
	setSprite(texture);
	reloj.restart();
	frame = 0;
	setVelocidad(0.f, 0.f);
}


void Muñequito::setSprite(const char *path) {
	if (!textura.loadFromFile(path)) {
		cout << "Error cargando imagen" << path;
		Cargado = false;
	}
	else {
		Cargado = true;
		sprite.setTexture(textura);
		setSize(textura.getSize().x, textura.getSize().y);
	}
}

void Muñequito::setCentro(float x, float y) {
	if (Cargado) {
		sprite.setOrigin(x, y);
	}
}

void Muñequito::setPosicion(float x, float y) {
	if (Cargado) {
		sprite.setPosition(x, y);
	}
}

Vector2f Muñequito::getPosicion() {
	if (Cargado) {
		return sprite.getPosition();
	}
	return Vector2f();
}

Vector2u Muñequito::getSize() {
	return size;
}

void Muñequito::setSize(unsigned int x, unsigned int y) {
	size.x = x;
	size.y = y;
}

void Muñequito::dibujar() {
	if (Cargado) {
		Ventana &ventana = *Ventana::Instancia();
		ventana.ventana.draw(sprite);
	}
}

void Muñequito::movimiento(float x, float y) {
	if (Cargado) {
		sprite.move(x, y);
	}
}

void Muñequito::setVelocidad(float x, float y) {
	velocidad.x = x;
	velocidad.y = y;
}

Vector2f Muñequito::getVelocidad() {
	return velocidad;
}

void Muñequito::setFrame(int row, int frame, float scaleX, float scaleY) {
	sprite.setTextureRect(IntRect(frame*size.x, row*size.y, size.x, size.y));
	sprite.setScale(scaleX, scaleY);
}

IntRect Muñequito::getBounds() {
	IntRect r(getPosicion().x - getSize().x / 2 + 5, getPosicion().y - getSize().y / 2 + 5, getSize().x - 10, getSize().y - 5);
	return r;
}