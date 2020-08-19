#include "Estado.h"
#include "Muñequito.h"
#include <fstream>

class Creditos : public Estado {
public:
	void Iniciar();
	void Limpiar();

	void Pausa();
	void Reanudar();

	void ProcesarEventos(Admin* gameadm);
	void Actualizar(Admin* gameadm);
	void Dibujar(Admin* gameadm);

	static Creditos* Instancia() {
		return &m_Creditos;
	}
	game::Reloj reloj;

protected:
	Creditos() {}

private:
	static Creditos m_Creditos;
	Muñequito *fondo;
	bool avanzar;
	bool salir;

	Font *fuente1;
	Text *palabras;
	Text *obtenido;

};