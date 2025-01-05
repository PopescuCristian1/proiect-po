// Team.cpp
#include "Team.h"

Team* Team::instance = nullptr;

Team* Team::getInstance() {
    static std::unique_ptr<Team> instance(new Team());
    return instance.get();
}


void Team::addUtility(const Utility& utility) {
    utilities.push_back(utility);
}

void Team::displayUtilities() const {
    for (const auto& utility : utilities) {
        std::cout << utility << '\n';
    }
}

void Team::sortUtilities() {
    if (utilities.empty()) {
        throw CustomException();
    }
    std::sort(utilities.begin(), utilities.end(), [](const Utility& a, const Utility& b) {
        return a < b;
    });
}

Team::~Team() {
}
