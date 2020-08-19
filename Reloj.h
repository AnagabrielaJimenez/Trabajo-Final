#include "SFML/System/Clock.hpp"
namespace game {

	class Reloj {
	public:
		Reloj();
		virtual ~Reloj();

		float getSeconds();
		float getMiliseconds();
		void restart();

		// Guarda los segundos obtenidos
		float elapsedSeconds;

	private:
		sf::Clock reloj;
	};

}