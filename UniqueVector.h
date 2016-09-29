#ifndef UNIQUEVECTOR_H
#define UNIQUEVECTOR_H
#include <iostream>
using namespace std;

template <typename T>
class UniqueVector {
public:
    UniqueVector();
    UniqueVector(unsigned const int initialCapacity);
    virtual ~UniqueVector();
    unsigned int capacity() const;
    unsigned int size() const;
    bool empty();
    bool contains(const T& data);
    bool contains(const T& data, unsigned int& pos);
    bool at(unsigned int pos, T& data);
    bool insert(const T& data);
    bool insert(const T& data, unsigned int pos);
    bool push_front(const T& data);
    bool remove(const T& data);
    bool remove(unsigned int pos, T& data);
    bool pop_back(T& data);
    void clear();
    bool operator==(const UniqueVector<T>& otherUniqueVector);
    
private:
    T* mainArray;
    unsigned int numElements;
    unsigned int currentCapacity;
    void extendArray();
    T atPos(unsigned int pos) const;
};

#include "UniqueVector.cpp"
#endif
