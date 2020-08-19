#include "Admin.h"
//State
class Estado {
public:
	virtual void Iniciar() = 0;
	virtual void Limpiar() = 0;

	virtual void Pausa() = 0;
	virtual void Reanudar() = 0;

	virtual void ProcesarEventos(Admin* gameadm) = 0;
	virtual void Actualizar(Admin* gameadm) = 0;
	virtual void Dibujar(Admin* gameadm) = 0;

	void CambiarEstado(Admin* gameadm, Estado* estado) {
		gameadm->CambiarEstado(estado);
	}

protected:
	Estado(){}
};