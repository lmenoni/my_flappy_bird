#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define W_HEIGHT 720
#define W_WIDTH 900
#define MOVE_SPEED 5.f
#define JUMP_FORCE -400.f
#define GRAVITY 800.f

class Game
{
private:

    sf::RenderWindow    _window;
    sf::CircleShape     _player;
    bool                _running;

    void    processEvents( sf::Vector2f& velocity );
    void    render( const sf::Drawable **sprites, int nOfSprites );
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