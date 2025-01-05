#include "Utility.h"

int Utility::instances = 0;

Utility::Utility(int value) : value(value) {
    instances++;
}

Utility::Utility(const Utility& other) : value(other.value) {
    instances++;
}

Utility& Utility::operator=(const Utility& other) {
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

Utility::~Utility() {
    instances--;
}

std::ostream& operator<<(std::ostream& os, const Utility& utility) {
    os << utility.value;
    return os;
}

std::istream& operator>>(std::istream& is, Utility& utility) {
    is >> utility.value;
    return is;
}

bool Utility::operator<(const Utility& other) const {
    return value < other.value;
}

bool operator==(const Utility& a, const Utility& b) {
    return a.value == b.value;
}
