#include "SFML/Graphics.hpp"
#include "Ventana.h"
#include "Admin.h"
#include "Prota.h"
#include "Menu.h"
#include "Recursos.h"
#include <iostream>
#include <time.h>
using namespace sf;
using namespace std;


int main() {

	Admin* gameadm = new Admin();

	Ventana &ventana = *Ventana::Instancia();

	gameadm->Iniciar();
	gameadm->CambiarEstado(Menu::Instancia());

	while (gameadm->Funcionando()) {
		gameadm->ProcesarEventos();
		gameadm->Actualizar();
		gameadm->Dibujar();
	}

	gameadm->Limpiar();

	return 0;
}
