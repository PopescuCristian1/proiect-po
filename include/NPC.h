#ifndef NPC_H
#define NPC_H

#include "AbstractEntity.h"
#include <string>
#include <iostream>

class NPC : public AbstractEntity {
private:
    std::string role;

public:
    NPC(const std::string& role = "");
    void display() const override;
};

#endif // NPC_H
