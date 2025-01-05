// Team.h
#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Utility.h"
#include "CustomException.h"

class Team {
private:
    std::vector<Utility> utilities;
    static Team* instance; // Singleton instance

    Team() = default; // Private constructor for Singleton

public:
    // Delete copy constructor and assignment operator
    Team(const Team&) = delete;
    Team& operator=(const Team&) = delete;

    static Team* getInstance(); // Access the Singleton instance

    void addUtility(const Utility& utility);
    void displayUtilities() const;
    void sortUtilities();

    ~Team(); // Destructor
};

#endif // TEAM_H
