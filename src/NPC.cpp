#include "NPC.h"

NPC::NPC(const std::string& role) : role(role) {}

void NPC::display() const {
    std::cout << "Role: " << role << '\n';
}
//x
