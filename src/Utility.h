#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

class Utility {
private:
    static int instances;
    int value;

public:
    Utility(int value = 0);
    Utility(const Utility& other);
    Utility& operator=(const Utility& other);
    ~Utility();

    static int getInstances();
    friend std::ostream& operator<<(std::ostream& os, const Utility& utility);
    friend std::istream& operator>>(std::istream& is, Utility& utility);
    bool operator<(const Utility& other) const;
    friend bool operator==(const Utility& a, const Utility& b);

    int getValue() const;
};

#endif // UTILITY_H
