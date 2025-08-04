#include "Game.hpp"

void    Game::gameLoop( void ) {

    sf::Clock   clock;

    // Carichiamo un font (usiamo uno standard di sistema, per test)
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        std::cerr << "Errore caricamento font\n";
        _window.close();
        return ;
    }

    // Creiamo un testo
    sf::Text text("Usa frecce per muovere il cerchio", font, 20);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    // Creiamo un vettore per la fisica
    sf::Vector2f    velocity(0.f, 0.f);

    while (_running) {
        // prendiamo il tempo trascorso tra un frame e l'altro (dinamicita per FPS)
        sf::Time dt = clock.restart();
        float   delta = dt.asSeconds();

        // Eventi
        processEvents( velocity );

        // changePlayerPosition( delta )
            // Fisica
        velocity.y += GRAVITY * delta;
        _player.move(velocity * delta);

            // Evita che esca dallo schermo
        if (_player.getPosition().y + _player.getRadius() > W_HEIGHT) {
            _player.setPosition(_player.getPosition().x, W_HEIGHT - _player.getRadius());
            velocity.y = 0;
        }

        // rendering
        colorChangeLogic(_player, clock);
        sf::Drawable    *sprites[2];
        sprites[0] = &_player;
        sprites[1] = &text;
        render((const sf::Drawable**)sprites, 2);
    }
    _window.close();
}

void    Game::processEvents( sf::Vector2f& velocity ) {
    // Una volta implementata una classe entity interna a game il metodo andra' a modificare quella
    sf::Event   event;
    static bool canJump = true;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _running = false;
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && canJump) {
            velocity.y = JUMP_FORCE;
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

void    Game::render( const sf::Drawable **sprites, int nOfSprites ) {
    _window.clear();
    for (int i = 0; i < nOfSprites; i++)
        _window.draw(*sprites[i]);
    _window.display();
}

// ORTHODOX

Game::Game( void )
    : _window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Flappy God"), _player(50), _running(true) {
    _window.setFramerateLimit(60);
    _player.setFillColor(sf::Color::Green);
    _player.setOrigin(_player.getRadius(), _player.getRadius());
    _player.setPosition(W_WIDTH / 2.f, W_HEIGHT / 2.f);
}

Game::~Game( void ) {}