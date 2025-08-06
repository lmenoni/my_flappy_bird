#include "Game.hpp"

bool    Game::startGame( void ) {
    sf::Texture player;
    player.loadFromFile("paralleila.png");
    // player.loadFromFile("blob.png");

    _player.setTexture(player);
    float   margin = 50.f;
    int     idx = 0;
    float   patternY = W_HEIGHT - margin;
    float   renderingSize = W_HEIGHT - (margin * 2) - OBSTACLE_GAP;
    float   patternGap = renderingSize / 9;

    srand(static_cast<unsigned int>(time(0)));

    while (idx < 20) {
        _obstacle[idx] = ObstaclePair(patternY);
        patternY -= patternGap;
        idx++;
        if (idx == 10)
            patternY = W_HEIGHT - margin;
    }

    gameLoop();

    return (true);
}

void    Game::gameLoop( void ) {

    sf::Clock   clock;
    float       delta = 0.f;

    while (_running) {
        delta = clock.restart().asSeconds();
        activateRandomObstacle();
        processEvents();
        updateEntities(delta);
        render();
    }
    _window.close();
}

void    Game::activateRandomObstacle( void ) {
    static ObstaclePair    *lastObstacle = NULL;

    if (!lastObstacle || (W_WIDTH - lastObstacle->getX() > 0.f && W_WIDTH - lastObstacle->getX() >= W_WIDTH / 2)) {
        int idx = rand() % 20;
        if (_obstacle[idx].isActive())
            idx = getFirstInactive();
        _obstacle[idx].activate();
        lastObstacle = &_obstacle[idx];
    }
}

int     Game::getFirstInactive( void ) {
    for (int i = 0; i < 20; i++) {
        if (!_obstacle[i].isActive())
            return (i);
    }
    return (-1);
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

void    Game::handleKeyInput( void ) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        _player.move(-MOVE_SPEED, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        _player.move(MOVE_SPEED, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        ObstaclePair::addVelocity(10.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        ObstaclePair::addVelocity(-10.f);
}

void    Game::updateEntities( const float delta ) {
    _player.update(delta);

    for (int i = 0; i < 20; i++) {
        if (_obstacle[i].isActive())
            _obstacle[i].update(delta);
    }
}

void    Game::render( void ) {
    _window.clear();
    _window.draw(*(_player.getSprite()));

    for (int i = 0; i < 20; i++) {
        if (_obstacle[i].isActive()) {
            _window.draw(*(_obstacle[i].getTopSprite()));
            _window.draw(*(_obstacle[i].getBotSprite()));
        }
    }

    _window.display();
}

// ORTHODOX

Game::Game( void )
    : _window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Flappy God"), _player(), _obstacle(), _running(true) {
    _window.setFramerateLimit(60);
}

Game::~Game( void ) {}