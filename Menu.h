#include "Estado.h"
#include "Muñequito.h"

class Menu : public Estado {
public:
	void Iniciar();
	void Limpiar();

	void Pausa();
	void Reanudar();

	void ProcesarEventos(Admin* gameadm);
	void Actualizar(Admin* gameadm);
	void Dibujar(Admin* gameadm);

	static Menu* Instancia() {
		return &m_enu;
	}

protected:
	Menu(){}

private:
	static Menu m_enu;
	Muñequito *inicio;
	bool avanzar;
	bool salir;

	Font *fuente1;
	Text *palabras;
};