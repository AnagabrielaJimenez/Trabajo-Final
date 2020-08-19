#include "Menu.h"
#include "Admin.h"
#include "Prota.h"
#include "Recursos.h"

using namespace sf;
using namespace std;

Menu Menu::m_enu;

void Menu::Iniciar() {
	avanzar = false;
	salir = false;
	
	std::unique_ptr<Muñequito> inicio(new Muñequito(RUTA_INTRO));
	inicio->setPosicion(0, 0);


	fuente1 = new Font();
	fuente1->loadFromFile(RUTA_FONT_W);
	palabras = new Text();
	palabras->setFont(*fuente1);
	palabras->setString("Presiona ENTER para comenzar");
	palabras->setCharacterSize(20);
	palabras->setPosition(50, 190);
}

void Menu::ProcesarEventos(Admin* gameadm) {
	Ventana &ventana = *Ventana::Instancia();

	Event evento;
	if (ventana.ventana.pollEvent(evento)) {
		switch (evento.type) {
		case Event::Closed:
			gameadm->Salir();
			break;
		case Event::KeyPressed:
			switch (evento.key.code) {
			case Keyboard::Return:
				if (!avanzar) {
					avanzar = true;
				}
			case Keyboard::Escape:
				salir = true;
				break;
			}
		}
	}
}

void Menu::Actualizar(Admin* gameadm) {
	if (avanzar) {
		gameadm->CambiarEstado(Prota::Instancia());
	}
}

void Menu::Dibujar(Admin* gameadm) {
	Ventana &ventana = *Ventana::Instancia();
	inicio->dibujar();
	ventana.ventana.draw(*palabras);
}