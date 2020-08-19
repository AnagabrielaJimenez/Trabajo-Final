#include "Reloj.h"
#include "SFML/Graphics.hpp"
using namespace sf;

class Ventana {
public:
	static Ventana* Instancia();
	RenderWindow ventana;
	int vAncho;
	int vAlto;
	game::Reloj reloj;

private:
	Ventana();
	Ventana(const Ventana& orig);
	Ventana &operator= (const Ventana &);

	static Ventana* pin;
};