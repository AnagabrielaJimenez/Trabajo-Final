#include "Estado.h"
#include "Muñequito.h"
#include "Muro.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;
using namespace sf;

class Prota : public Estado {
public:
	void Iniciar();
	void Limpiar();

	void Pausa();
	void Reanudar();

	void ProcesarEventos(Admin* gameadm);
	void Actualizar(Admin* gameadm);
	void Dibujar(Admin* gameadm);

	static Prota* Instancia() {
		return &m_Prota;
	}

	Muro muro[10];

protected:
	Prota() {}

private:
	static Prota m_Prota;
	bool avanzar;
	bool salir;

	Muñequito *fondo;
	Font *fuente1;
	Text *scoreText;
	Clock * reloj1;
	Time * tiempo1;
	float tiempo2;

	int playerX = 250;
	int playerY = 151;
	float dy = 0;
	int height = 150;
	int score = 0;


	const int PLAYER_LEFT_BOUNDING_BOX = 20;
	const int PLAYER_RIGHT_BOUNDING_BOX = 60;
	const int PLAYER_BOTTOM_BOUNDING_BOX = 70;
};