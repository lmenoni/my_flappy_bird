#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Entity.hpp"

class Obstacle : public Entity
{
private:
    // questo sara lo sprite una volta implementato (sf::Sprite)
    sf::RectangleShape _sprite;

public:

    Obstacle( void );
    ~Obstacle( void );
    Obstacle( const Obstacle& other );
    Obstacle& operator=( const Obstacle& other );

    void    update( float delta );
    sf::Drawable* getSprite( void ) const;

};

#endif