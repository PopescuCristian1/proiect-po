#ifndef TEAM_H
#define TEAM_H

#include "Utility.h"
#include <vector>
#include <algorithm>
#include "CustomException.h"

class Team {
private:
    std::vector<Utility> utilities;

public:
    void addUtility(const Utility& utility);
    void displayUtilities() const;
    void sortUtilities();
};

#endif // TEAM_H
