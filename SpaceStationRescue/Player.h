

#ifndef PLAYER
#define PLAYER


#include "BasicGameObject.h"
#include "Bullet.h"
#include "Worker.h"
#include "Predator.h"
#include "Interceptor.h"
#include "AlienNest.h"
#include "Sweeper.h"
#include "Wall.h"

#include <iostream>

using namespace std;

class Player : public BasicGameObject
{
public:
	Player();
	Player(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f maxSpeed, float orientation, sf::Texture* tex, sf::Texture& bulletTex);
	~Player();

	void movementHandler();
	void bulletHandler();
	void Draw(sf::RenderWindow *window);
	void RadarDraw(sf::RenderWindow *window);

	//void Update(std::vector<Worker>* workers, std::vector<Predator>* predators, std::vector<Sweeper>* sweepers, std::vector<Wall>* walls, std::vector<AlienNest>* alienNests, std::vector<Interceptor>* interceptors);
	void Update(std::vector<Worker>*workers, std::vector<Predator>* predators, std::vector<Sweeper>* sweepers, std::vector < Wall>* walls, std::vector<AlienNest>* alienNests, std::vector<Interceptor>* interceptors);


	float speed;

	std::vector<Bullet> * bullets;
	int bulletTimer;
	int collected; 

	sf::Vector2f difference;
	sf::Vector2f result;
	sf::Vector2f playerOrigin;
	sf::Vector2f wallOrigin;

	
private:
	sf::Vector2f velocityHandler(float orientation);
	float conversion;
	sf::Texture bulletTexture;
	sf::CircleShape radarImage;
};

#endif 