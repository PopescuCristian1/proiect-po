#ifndef CONTAINER_H
#define CONTAINER_H

#include "CustomException.h"
#include <list>
#include <iostream>

template <typename T>
class Container {
private:
    std::list<T> elements;

public:
    void add(const T& element) {
        elements.push_back(element);
    }

    void display() const {
        for (const auto& element : elements) {
            std::cout << element << '\n';
        }
    }

    T getFirstElement() const {
        if (!elements.empty()) {
            return elements.front();
        }
        throw CustomException();
    }
};

#endif // CONTAINER_H
