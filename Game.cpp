#include "Game.hpp"

void    Game::gameLoop( void ) {

    sf::Clock   clock;
    while (_running) {
        sf::Time dt = clock.restart();
        float   delta = dt.asSeconds();
        processEvents();
        _player.update(delta);
        _obstacle.update(delta);
        render();
    }
    _window.close();
}

void    Game::processEvents( void ) {
    sf::Event   event;
    static bool canJump = true;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _running = false;
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && canJump) {
            _player.changeVelocityY(JUMP_FORCE);
            canJump = false;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
            canJump = true;
    }
    handleKeyInput();
}

void    Game::colorChangeLogic( sf::Shape& player, sf::Clock& clock ) {
    sf::Time elapsed = clock.getElapsedTime();
    sf::Uint8 red = static_cast<sf::Uint8>((std::sin(elapsed.asSeconds()) + 1) * 127);
    sf::Uint8 green = static_cast<sf::Uint8>((std::cos(elapsed.asSeconds()) + 1) * 127);
    player.setFillColor(sf::Color(red, green, 150));
}

void    Game::handleKeyInput( void ) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _player.move(-MOVE_SPEED, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _player.move(MOVE_SPEED, 0.f);
    }
}

void    Game::render( void ) {
    _window.clear();
    _window.draw(*(_player.getSprite()));
    _window.draw(*(_obstacle.getTopSprite()));
    _window.draw(*(_obstacle.getBotSprite()));
    _window.display();
}

// ORTHODOX

Game::Game( void )
    : _window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Flappy God"), _player(), _obstacle(), _running(true) {
    _window.setFramerateLimit(60);
}

Game::~Game( void ) {}