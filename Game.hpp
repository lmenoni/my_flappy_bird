#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Obstacle.hpp"

#define MOVE_SPEED 5.f
#define JUMP_FORCE -400.f
#define GRAVITY 800.f

class Game
{
private:

    sf::RenderWindow    _window;
    Player              _player;
    Obstacle            _obstacle;
    bool                _running;

    void    processEvents( void );
    void    render( void );
    void    handleKeyInput( void );
    void    colorChangeLogic( sf::Shape& player, sf::Clock& clock );
    
public:
    
    void    gameLoop( void );
    Game( void );
    ~Game( void );

private:

    // Vietiamo copia e assegnazione (C++98 style)
    Game( const Game& ) {};
    Game& operator=( const Game& ) {return *this;};

};

#endif