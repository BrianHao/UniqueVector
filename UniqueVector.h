#ifndef UNIQUEVECTOR_H
#define UNIQUEVECTOR_H
#include <iostream>
using namespace std;

template <typename T>
class UniqueVector {
public:
    UniqueVector();
    UniqueVector(unsigned const int startCapacity);
    virtual ~UniqueVector();
    unsigned int capacity();
    unsigned int size();
    bool empty();
    bool contains(const T& data);
    bool at(unsigned int pos, T& data);
    bool insert(const T& data);
    bool insert(const T& data, unsigned int pos);
    bool push_front(const T& data);
    bool remove(const T& data);
    bool remove(unsigned int pos, T& data);
    bool pop_back(T& data);
    void clear();
    bool operator==(const UniqueVector& otherUniqueVector);
    
private:
    T* mainArray;
    unsigned int numElements;
    unsigned int currentCapacity;
    void extendArray();
};

#include "UniqueVector.cpp"
#endif
