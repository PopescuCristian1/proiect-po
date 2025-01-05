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
    static Team* instance;

    Team() = default; 

public:
    Team(const Team&) = delete;
    Team& operator=(const Team&) = delete;

    static Team* getInstance();

    void addUtility(const Utility& utility);
    void displayUtilities() const;
    void sortUtilities();

    ~Team(); 
};

#endif
