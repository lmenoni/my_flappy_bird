#include "Obstacle.hpp"

void    Obstacle::update( float delta ) {
    _velocity.x = -(MOVE_SPEED * 15);
    _sprite.move(_velocity * delta);
}

sf::Drawable* Obstacle::getSprite( void ) const {
    return ((sf::Drawable *)&_sprite);
}

// ORTHODOX

Obstacle::Obstacle( void ) : Entity(), _sprite(sf::Vector2f(100.f, 200.f)) {
    sf::Vector2f    size = _sprite.getSize();
    _sprite.setFillColor(sf::Color::Red);
    _sprite.setOrigin(size.x / 2.f, size.y / 2.f);
    _sprite.setPosition(W_WIDTH, W_HEIGHT - size.y / 2.f);
}

Obstacle::Obstacle( const Obstacle& other ) : Entity(), _sprite(other._sprite) {}

Obstacle& Obstacle::operator=( const Obstacle& other ) {
    if (this != &other) {
        _position = other._position;
        _position = other._position;
        _velocity = other._velocity;
        _velocity = other._velocity;
        _sprite = other._sprite;
    }
    return (*this);
}

Obstacle::~Obstacle( void ) {}