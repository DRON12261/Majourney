#ifndef PLAYER_H
#define PLAYER_H

#include <Entities/Entity.h>

class Player : public Entity
{
private:
    //Variables

    //Initialization functions
    void initVariables();
    void initComponents();
public:
    Player(float x, float y, sf::Texture& texture);
    virtual ~Player();

    //Functions

};

#endif
