#include "Creditos.h"
#include "Admin.h"
#include "Menu.h"
#include "Jugador.h"
#include "Recursos.h"
#include "Prota.h"
#include <memory>

using namespace sf;
using namespace std;

Creditos Creditos::m_Creditos;

void Creditos::Iniciar() {
	game::Jugador &jugador = *game::Jugador::Instancia();
	jugador.iniciar();
	jugador.setPosicion(215, 180);


	avanzar = false;
	salir = false;

	fondo = new Muñequito(RUTA_CRED);
	fondo->setPosicion(0, 0);

	ifstream archivo;
	string texto;
	archivo.open("puntos.txt", ios::in);
	while (!archivo.eof()) {
		getline(archivo, texto);
	}
	archivo.close();

	std::unique_ptr<Font> fuente1(new Font);
	fuente1->loadFromFile(RUTA_FONT_W);
	std::unique_ptr<Text> palabras(new Text);
	palabras->setFont(*fuente1);
	palabras->setString("Puntaje total");
	palabras->setCharacterSize(20);
	palabras->setPosition(100, 230);

	std::unique_ptr<Text> obtenido(new Text);
	obtenido->setFont(*fuente1);
	obtenido->setString(texto);
	obtenido->setCharacterSize(20);
	
	obtenido->setPosition(300, 230);


}

void Creditos::Limpiar() {
	delete fondo;
}

void Creditos::ProcesarEventos(Admin* gameadm) {
	game::Jugador &jugador = *game::Jugador::Instancia();
	Ventana &motor = *Ventana::Instancia();
	
	Event evento;
	if (motor.ventana.pollEvent(evento)) {
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

	int grupo = 0;
	float tiempo = 500.f;
	float tiempo2 = 1000.f;

	jugador.setFrame(1, 0, 1, 1);
	if (reloj.getMiliseconds() > tiempo) {
		jugador.setFrame(1, grupo + 1, 1, 1);
	}

	if (reloj.getMiliseconds() > tiempo2) {
		jugador.setFrame(1, grupo - 1, 1, 1);
		reloj.restart();
	}
}

void Creditos::Actualizar(Admin* gameadm) {
	game::Jugador &jugador = *game::Jugador::Instancia();
	if (avanzar) {
		gameadm->CambiarEstado(Menu::Instancia());
	}

}

void Creditos::Dibujar(Admin* gameadm) {
	Ventana &motor = *Ventana::Instancia();
	game::Jugador &jugador = *game::Jugador::Instancia();
	fondo->dibujar();
	motor.ventana.draw(*palabras);
	motor.ventana.draw(*obtenido);
	jugador.dibujar();
}