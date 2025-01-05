// Team.cpp
#include "Team.h"

// Initialize static instance
Team* Team::instance = nullptr;

Team* Team::getInstance() {
    if (!instance) {
        instance = new Team();
    }
    return instance;
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
    // Singleton instance cleanup is not explicitly required here
}
