#include "Team.h"

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
    std::sort(utilities.begin(), utilities.end());
}
