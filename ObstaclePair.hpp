#ifndef OBSTACLEPAIR_HPP
#define OBSTACLEPAIR_HPP

#include "Obstacle.hpp"

class ObstaclePair
{
private:

    Obstacle        _topPipe;
    Obstacle        _botPipe;
    float           _pairX;
    float           _distY;
    static float    _velocity;
    bool            _onScreen;

public:

    ObstaclePair( void );
    ObstaclePair( const float botY );
    ~ObstaclePair( void );
    ObstaclePair( const ObstaclePair& other );
    ObstaclePair& operator=( const ObstaclePair& other );

    void            update( float delta );
    sf::Drawable*   getTopSprite( void );
    sf::Drawable*   getBotSprite( void );
    bool            isActive( void );
    float           getX( void );
    void            activate( void );
    static void            addVelocity( const float boost );

};

#endif