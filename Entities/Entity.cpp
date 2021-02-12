#include "Entity.h"

Entity::Entity()
{
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setFillColor(sf::Color::White);
    this->movementSpeed = 100.0f;
}

Entity::~Entity()
{

}

//Functions
void Entity::move(const float& dt, const float dirX, const float dirY)
{
    this->shape.move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
}

void Entity::update(const float& dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->move(dt, -1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(dt, 1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->move(dt, 0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(dt, 0.f, 1.f);
    }
}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}
