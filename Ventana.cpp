#include "Ventana.h"
using namespace sf;

Ventana* Ventana::pin = 0;

Ventana* Ventana::Instancia() {
	if (pin == 0) {
		pin = new Ventana;
	}
	return pin;
}

Ventana::Ventana() {
	vAlto = 450;
	vAncho = 533;
	this->ventana.create(VideoMode(vAlto, vAncho, 32), "Bewitched");
	this->ventana.setFramerateLimit(60);
}

