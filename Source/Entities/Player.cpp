#include "Player.h"

//Initialization functions
void Player::initVariables()
{

}

void Player::initComponents()
{
    this->createMovementComponent(300.f, 250.f, 100.f);
}

//Constructor / Destructor
Player::Player(float x, float y, sf::Texture& texture)
{
    this->initVariables();
    this->initComponents();

    this->setTexture(texture);
    this->setPosition(x, y);
}

Player::~Player()
{

}
