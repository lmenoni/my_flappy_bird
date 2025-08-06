#include "Player.hpp"

void    Player::update( float delta ) {
    _velocity.y += GRAVITY * delta;
    // _sprite.move(_velocity * delta);
    // if (_sprite.getPosition().y + _sprite.getRadius() > W_HEIGHT) {
    //     _sprite.setPosition(_sprite.getPosition().x, W_HEIGHT - _sprite.getRadius());
    //     _velocity.y = 0;
    // }
    _leo.move(_velocity * delta);
    if (_leo.getPosition().y + _leo.getGlobalBounds().height / 2 > W_HEIGHT) {
        _leo.setPosition(_leo.getPosition().x, W_HEIGHT - _leo.getGlobalBounds().height / 2);
        _velocity.y = 0;
    }
}

sf::Drawable* Player::getSprite( void ) const {
    // return ((sf::Drawable *)&_sprite);
    return ((sf::Drawable *)&_leo);
}

void    Player::changeVelocityY( const float velocityY ) {
    _velocity.y = velocityY;
}

void    Player::move( const float x, const float y ) {
    // _sprite.move(x, y);
    _leo.move(x, y);
}

void    Player::setTexture( const sf::Texture& texture ) {
    _leo.setTexture(texture);
    sf::FloatRect bounds = _leo.getLocalBounds();
    float targetHeight = 200.f;
    float scaleFactor = targetHeight / bounds.height;
    _leo.setOrigin(bounds.width / 2,bounds.height / 2 );
    _leo.setPosition(W_WIDTH / 6.f, W_HEIGHT / 2.f);
    _leo.setScale(scaleFactor, scaleFactor);
    _leo.rotate(90.f);

}

// ORTHODOX

Player::Player( sf::Texture& texture ) : Entity(), _sprite(30), _leo(texture) {
    _sprite.setFillColor(sf::Color::Green);
    _sprite.setOrigin(_sprite.getRadius(), _sprite.getRadius());
    _sprite.setPosition(W_WIDTH / 6.f, W_HEIGHT / 2.f);
}

Player::Player( void ) : Entity(), _sprite(30), _leo() {
    _sprite.setFillColor(sf::Color::Green);
    _sprite.setOrigin(_sprite.getRadius(), _sprite.getRadius());
    _sprite.setPosition(W_WIDTH / 6.f, W_HEIGHT / 2.f);
}

Player::Player( const Player& other ) : Entity(), _sprite(other._sprite) {}

Player& Player::operator=( const Player& other ) {
    if (this != &other) {
        _position = other._position;
        _position = other._position;
        _velocity = other._velocity;
        _velocity = other._velocity;
        _sprite = other._sprite;
    }
    return (*this);
}

Player::~Player( void ) {}