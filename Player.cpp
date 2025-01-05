#include "Player.h"

Player::Player(const std::string& name, int level, double rating)
    : name(name), level(level), rating(rating) {}

Player::Player(const Player& other)
    : name(other.name), level(other.level), rating(other.rating) {}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        name = other.name;
        level = other.level;
        rating = other.rating;
    }
    return *this;
}

void Player::display() const {
    std::cout << "Name: " << name << ", Level: " << level << ", Rating: " << rating << '\n';
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Name: " << player.name << ", Level: " << player.level << ", Rating: " << player.rating;
    return os;
}

std::istream& operator>>(std::istream& is, Player& player) {
    is >> player.name >> player.level >> player.rating;
    return is;
}
