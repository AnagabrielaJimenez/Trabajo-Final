#include "SFML/Graphics.hpp"
#include "Ventana.h"
#include <vector>

using namespace std;

class Estado;

class Admin {
public:
	void Iniciar();
	void Limpiar();

	void ProcesarEventos();
	void Actualizar();
	void Dibujar();

	void CambiarEstado(Estado* estado);
	void PushEstado(Estado* estado);
	void PopEstado();

	bool Funcionando() { return m_funcionando;  }
	void Salir() { m_funcionando = false; }

private:
	vector<Estado*> estados;
	bool m_funcionando;
};