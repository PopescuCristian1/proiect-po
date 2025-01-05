// Team.cpp
#include "Team.h"
#include <memory>

std::unique_ptr<Team> Team::instance = nullptr; 

Team* Team::getInstance() {
    if (!instance) {
        instance = std::make_unique<Team>(); 
    }
    return instance.get();
}

void Team::addUtility(const Utility& utility) {
    utilities.push_back(std::make_unique<Utility>(utility)); 
}

void Team::displayUtilities() const {
    for (const auto& utility : utilities) {
        std::cout << *utility << '\n'; 
    }
}

void Team::sortUtilities() {
    if (utilities.empty()) {
        throw CustomException();
    }
    std::sort(utilities.begin(), utilities.end(), [](const std::unique_ptr<Utility>& a, const std::unique_ptr<Utility>& b) {
        return *a < *b; 
    });
}

Team::~Team() {
}
