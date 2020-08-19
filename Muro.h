#include "Muñequito.h"
#include "SFML/Graphics.hpp"
using namespace sf;


class Muro : public Muñequito {
public:
	Muro();
	Muro(const Muro& orig);
	virtual ~Muro();

	int rel;
	float distancia;
	bool activa;

	void activar();
	void setSpawn(float x, float y);
	int x, y;

private:
	Vector2f spawn;
};
