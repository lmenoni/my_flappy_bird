#include "ObstaclePair.hpp"

float   ObstaclePair::_velocity = OBSTACLE_SPEED;

void   ObstaclePair::update( float delta ) {
    _pairX -= _velocity * delta;
    if (_pairX + (_topPipe.getSize().x / 2) < 0) {
        _pairX = W_WIDTH + (_topPipe.getSize().x / 2);
        _onScreen = false;
    }
    _topPipe.setPosition(_pairX);
    _botPipe.setPosition(_pairX);
}

void    ObstaclePair::addVelocity( const float boost ) {
    _velocity += boost;
}

bool    ObstaclePair::isActive( void ) {
    return (_onScreen);
}

void    ObstaclePair::activate( void ) {
    _onScreen = true;
}

float   ObstaclePair::getX( void ) {
    return (_pairX);
}

sf::Drawable* ObstaclePair::getTopSprite( void ) {
    return (_topPipe.getSprite());
}

sf::Drawable* ObstaclePair::getBotSprite( void ) {
    return (_botPipe.getSprite());
}

// ORTHODOX

ObstaclePair::ObstaclePair( const float botY )
    : _topPipe(), _botPipe(), _pairX(0.f), _distY(OBSTACLE_GAP), _onScreen(false) {
    sf::Vector2f    size = _botPipe.getSize();
    _pairX = W_WIDTH + (size.x / 2);
    _botPipe.setPosition(_pairX, (botY + size.y / 2.f));
    _topPipe.setPosition(_pairX, (botY + size.y / 2.f) - (_distY + size.y));
}


ObstaclePair::ObstaclePair( void )
    : _topPipe(), _botPipe(), _pairX(0.f), _distY(OBSTACLE_GAP),
      _onScreen(false) {
    sf::Vector2f    size = _botPipe.getSize();
    _pairX = W_WIDTH + (size.x / 2);
    _botPipe.setPosition(_pairX, (W_HEIGHT - size.y / 2.f));
    _topPipe.setPosition(_pairX, (W_HEIGHT - size.y / 2.f) - (_distY + size.y));
}

ObstaclePair::~ObstaclePair( void ) {};

ObstaclePair::ObstaclePair( const ObstaclePair& other ) 
    : _topPipe(other._topPipe), _botPipe(other._botPipe), _pairX(other._pairX), _distY(other._distY) {}

ObstaclePair& ObstaclePair::operator=( const ObstaclePair& other ) {
    if (this != &other) {
        _topPipe = other._topPipe;
        _botPipe = other._botPipe;
        _pairX = other._pairX;
        _distY = other._distY;
        _velocity = other._velocity;
    }
    return (*this);
}