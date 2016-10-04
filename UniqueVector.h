#ifndef UNIQUEVECTOR_H
#define UNIQUEVECTOR_H
#include <iostream>
using namespace std;

template <typename T>
class UniqueVector {
public:
    //Constructor, default initialization size is 3
    UniqueVector(unsigned int initialCapacity = 3);
    //Destructor
    virtual ~UniqueVector() { delete[] mainArray; };
    //Returns current capacity of the vector
    unsigned int capacity() const { return currentCapacity; };
    //Returns current container size of the vector
    unsigned int size() const { return numElements; };
    //Checks if the vector contains any elements
    bool empty() { return numElements == 0; };
    //Checks if the vector contains a specific element
    bool contains(const T& data);
    //As above, if element is found, sets its position to pos
    bool contains(const T& data, unsigned int& pos);
    //Finds element at position pos, sets its content to data
    bool at(unsigned int pos, T& data);
    //Inserts unique data to the end of the vector
    bool insert(const T& data);
    //Inserts unique data to position pos
    bool insert(const T& data, unsigned int pos);
    //Inserts unique data to the front of the vector
    bool push_front(const T& data) { return insert(data, 0); };
    //If data exists in the vector, remove it
    bool remove(const T& data);
    //Remove the content at position pos, set the content to data
    bool remove(unsigned int pos, T& data);
    //Remove the content at the end of the vector
    bool pop_back(T& data);
    //Clear the vector and reset it to its default capacity
    void clear();
    //Compares two UniqueVectors
    //Both vectors must contain the same number of elements, as well as the same elements in the same order.
    bool operator==(const UniqueVector<T>& otherUniqueVector);
    
private:
    T* mainArray;
    unsigned int numElements;
    unsigned int currentCapacity;
    void extendArray();
};

#include "UniqueVector.cpp"
#endif
