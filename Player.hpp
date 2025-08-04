#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity
{
private:
    // questo sara lo sprite una volta implementato (sf::Sprite)
    sf::CircleShape _sprite;

public:

    Player( void );
    ~Player( void );
    Player( const Player& other );
    Player& operator=( const Player& other );

    void    update( float delta );
    void    changeVelocityY( const float velocityY );
    void    move( const float x, const float y );
    sf::Drawable* getSprite( void ) const;

};

#endif