#ifndef OBSTACLEPAIR_HPP
#define OBSTACLEPAIR_HPP

#include "Obstacle.hpp"

class ObstaclePair
{
private:

    Obstacle    _topPipe;
    Obstacle    _botPipe;
    float       _pairX;
    float       _distY;
    float       _velocity;

public:

    ObstaclePair( void );
    ~ObstaclePair( void );
    ObstaclePair( const ObstaclePair& other );
    ObstaclePair& operator=( const ObstaclePair& other );

    void    update( float delta );
    sf::Drawable* getTopSprite( void );
    sf::Drawable* getBotSprite( void );

};

#endif