
// Ai behaviours

#pragma once
#include "BasicGameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <random>
#include "Wall.h"

struct BasicCollision
{
	bool willCollide;
	sf::Vector2f position;
	sf::Vector2f normal;
};

class BaseAI : public BasicGameObject
{
public:
	BaseAI();
	BaseAI(int AISTATE);
	~BaseAI();

	//virtual void SetupSprite(sf::Texture* texture);
	//virtual void Draw(sf::RenderWindow & window);
	virtual void Update(sf::Vector2f targetPosition, sf::Vector2f targetVelocity, std::vector<Wall> * walls);

	virtual float GetNewOrientation();
	sf::Vector2f Normalize(sf::Vector2f &velocity);

	virtual void Wander();
	virtual void Seek();
	virtual void Flee();
	virtual void Arrive();
	virtual void Pursue();
	virtual void WallAvoidance(std::vector<Wall> * walls);
	virtual BasicCollision WillCollideWall(sf::Vector2f rayVector, std::vector<Wall> * walls);
	void GetCollisionNormal(sf::Vector2f otherPosition);

	//virtual bool Bounds(sf::Vector2f boundsPosition, sf::Vector2f boundsSize);
	void SetTargetPosition(sf::Vector2f newTargetPosition);
	void SetTargetVelocity(sf::Vector2f newTargetVelocity);

	// AI Behaviour States
	enum AIState
	{
		WANDER,
		SEEK,
		FLEE,
		ARRIVE,
		PURSUE
	};
	AIState currentState;

	//Sprite
	//sf::Sprite m_sprite;
	//sf::Texture m_texture;

protected:

	//sf::Vector2f m_position;
	//sf::Vector2f m_velocity;
	float m_speed;
	//float m_maxSpeed;
	float m_distance;
	float m_currentOrientation;

	//Conversions between Degrees and Radians
	float RadiansToDegrees = 180 / 3.14159265359;
	float DegreesToRadians = 3.14159265359 / 180;

	//Needed For Behaviours
	sf::Vector2f m_targetPosition;
	sf::Vector2f m_targetVelocity;

	//Needed for Wander Behaviour
	sf::Clock wanderTimer;
	float wanderDistance;

	//Needed for Pursue Behaviour
	sf::Vector2f direction;

};