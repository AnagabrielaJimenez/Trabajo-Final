#include "Muñequito.h"
#include "Reloj.h"
#include "SFML/Graphics.hpp"
using namespace sf;

namespace game {
	class Jugador : public Muñequito {
	public:
		static Jugador* Instancia();
		virtual ~Jugador();

		bool enSuelo;
		bool vivo;
		Vector2f viejaPos;

		void caida(float delta_t);
		void actualizar();

		void setSpawn(float x, float y);
		void reaparecer();
		void iniciar();

		IntRect getBounds();

		game::Reloj reloj;

	private:
		//Singleton
		Jugador();
		Jugador(const Jugador& orig);
		Jugador &operator= (const Jugador &);
		static Jugador* pin;

		Vector2f velocidad;
		Vector2f aceleracion;
		Vector2f spawn;
	};
}