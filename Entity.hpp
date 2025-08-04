#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define W_HEIGHT 720
#define W_WIDTH 900
#define MOVE_SPEED 5.f
#define JUMP_FORCE -400.f
#define GRAVITY 800.f

class Entity
{
protected:

    sf::Vector2f    _position;
    sf::Vector2f    _velocity;

public:

    Entity( void ) : _position(), _velocity() {};
    ~Entity( void ) {};

    virtual void    update( const float delta ) = 0;

private:

    Entity( const Entity& ) {};
    Entity& operator=( const Entity& ) {return (*this);};

};

// player ha lo sprite e animazioni del caso 
// obstacle ha 2 sprite  con coordinate x uguali cambiano le posizioni (? vediamo perche potrebbe essere un casino anche se più pratico in quanto bastano 2 sprite invece di uno sprite per obstacle in array + si puo cambiare lo spazio tra tubi mentre vai avanti)

#endif