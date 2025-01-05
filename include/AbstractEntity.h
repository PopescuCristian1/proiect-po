#ifndef ABSTRACT_ENTITY_H
#define ABSTRACT_ENTITY_H

class AbstractEntity {
public:
    virtual void display() const = 0;
    virtual ~AbstractEntity() {}
};

#endif // ABSTRACT_ENTITY_H
