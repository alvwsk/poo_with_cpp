#include "Player.h"

Player::Player(int label) : label(label), position(0), free(true) {}

bool Player::isFree() const { return this->free; }
void Player::setFree(bool value) { this->free = value; }
int Player::getPosition() const { return this->position; }
void Player::setPosition(int value) { this->position = value; }
int Player::getLabel() const { return this->label; }

std::string Player::str() const 
{
    std::stringstream ss;
    ss << "player" << label;
    return ss.str();
}
