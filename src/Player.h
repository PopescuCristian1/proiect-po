#ifndef PLAYER_H
#define PLAYER_H

#include "AbstractEntity.h"
#include <iostream>
#include <string>

class Player : public AbstractEntity {
private:
    std::string name;
    int level;
    double rating;

public:
    Player(const std::string& name = "", int level = 0, double rating = 0.0);
    Player(const Player& other);
    Player& operator=(const Player& other);

    void display() const override;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    friend std::istream& operator>>(std::istream& is, Player& player);
};

#endif // PLAYER_H
