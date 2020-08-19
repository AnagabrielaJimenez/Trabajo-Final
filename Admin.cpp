#include "Admin.h"
#include "Estado.h"
#include "Ventana.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdio.h>

void Admin::Iniciar() {
	Ventana &ventana = *Ventana::Instancia();
	m_funcionando = true;
}

void Admin::Limpiar() {
	Ventana &ventana = *Ventana::Instancia();

	while (estados.empty()) {
		estados.back()->Limpiar();
		estados.pop_back();
	}
	ventana.ventana.close();
}

void Admin::CambiarEstado(Estado* estado) {
	if (!estados.empty()) {
		estados.back()->Limpiar();
		estados.pop_back();
	}

	estados.push_back(estado);
	estados.back()->Iniciar();
}

void Admin::PushEstado(Estado* estado) {
	if (!estados.empty()) {
		estados.back()->Pausa();
	}

	estados.push_back(estado);
	estados.back()->Iniciar();
}

void Admin::PopEstado() {
	if (!estados.empty()) {
		estados.back()->Limpiar();
		estados.pop_back();
	}

	if (!estados.empty()) {
		estados.back()->Reanudar();
	}
}

void Admin::ProcesarEventos() {
	estados.back()->ProcesarEventos(this);
}

void Admin::Actualizar() {
	estados.back()->Actualizar(this);
}

void Admin::Dibujar() {
	Ventana &ventana = *Ventana::Instancia();
	ventana.ventana.clear();
	ventana.reloj.restart();
	estados.back()->Dibujar(this);
	ventana.ventana.display();
}