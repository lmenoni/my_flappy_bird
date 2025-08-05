#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "ObstaclePair.hpp"
#include <cstdlib>
#include <ctime>

class Game
{
private:

    sf::RenderWindow    _window;
    Player              _player;
    ObstaclePair        _obstacle[20];
    bool                _running;

    void    processEvents( void );
    void    render( void );
    void    handleKeyInput( void );
    void    gameLoop( void );
    void    updateEntities( const float delta );
    void    activateRandomObstacle( void );
    int     getFirstInactive( void );
    
public:
    
    bool    startGame( void );
    Game( void );
    ~Game( void );

private:

    // Vietiamo copia e assegnazione (C++98 style)
    Game( const Game& ) {};
    Game& operator=( const Game& ) {return *this;};

};

#endif