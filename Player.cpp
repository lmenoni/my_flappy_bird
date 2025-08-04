#include "Player.hpp"

void    Player::update( float delta ) {
    _velocity.y += GRAVITY * delta;
    _sprite.move(_velocity * delta);
    if (_sprite.getPosition().y + _sprite.getRadius() > W_HEIGHT) {
        _sprite.setPosition(_sprite.getPosition().x, W_HEIGHT - _sprite.getRadius());
        _velocity.y = 0;
    }
}

sf::Drawable* Player::getSprite( void ) const {
    return ((sf::Drawable *)&_sprite);
}

void    Player::changeVelocityY( const float velocityY ) {
    _velocity.y = velocityY;
}

void    Player::move( const float x, const float y ) {
    _sprite.move(x, y);
}

// ORTHODOX

Player::Player( void ) : Entity(), _sprite(50) {
    _sprite.setFillColor(sf::Color::Green);
    _sprite.setOrigin(_sprite.getRadius(), _sprite.getRadius());
    _sprite.setPosition(W_WIDTH / 2.f, W_HEIGHT / 2.f);
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