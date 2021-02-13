#include "Entity.h"

void Entity::initVariables()
{
    this->texture = NULL;
    this->sprite = NULL;
    this->movementSpeed = 100.0f;
}

Entity::Entity()
{
    this->initVariables();
}

Entity::~Entity()
{
    delete this->sprite;
}

//Component functions
void Entity::createSprite(sf::Texture* texture)
{
    this->texture = texture;
    this->sprite = new sf::Sprite(*this->texture);
    this->sprite->setScale(2.f, 2.f);
}

//Functions
void Entity::setPosition(const float x, const float y)
{
    if (this->sprite)
    {
        this->sprite->setPosition(x, y);
    }
}

void Entity::move(const float& dt, const float dirX, const float dirY)
{
    if (this->sprite)
        this->sprite->move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
    if (this->sprite)
    {
        target->draw(*this->sprite);
    }
}
