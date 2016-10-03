#ifndef UNIQUEVECTOR_H
#define UNIQUEVECTOR_H
#include <iostream>
using namespace std;

template <typename T>
class UniqueVector {
public:
    UniqueVector(unsigned int initialCapacity = 3); //Constructor, default initialization size is 3
    virtual ~UniqueVector() { delete[] mainArray; }; //Destructor
    unsigned int capacity() const { return currentCapacity; };  //Returns current capacity of the vector
    unsigned int size() const { return numElements; };  //Returns current container size of the vector
    bool empty() { return numElements == 0; };   //Checks if the vector contains any elements
    bool contains(const T& data);   //Checks if the vector contains a specific element
    bool contains(const T& data, unsigned int& pos);    //As above, if element is found, sets its position to pos
    bool at(unsigned int pos, T& data); //Finds element at position pos, sets its content to data
    bool insert(const T& data); //Inserts unique data to the end of the vector
    bool insert(const T& data, unsigned int pos); //Inserts unique data to position pos
    bool push_front(const T& data) { return insert(data,0); }; //Inserts unique data to the front of the vector
    bool remove(const T& data); //If data exists in the vector, remove it
    bool remove(unsigned int pos, T& data); //Remove the content at position pos, set the content to data
    bool pop_back(T& data); //Remove the content at the end of the vector
    void clear();   //Clear the vector and reset it to its default capacity
    bool operator==(const UniqueVector<T>& otherUniqueVector);  //Compares two UniqueVectors
    //Both vectors must contain the same number of elements, as well as the same elements in the same order.
    
private:
    T* mainArray;
    unsigned int numElements;
    unsigned int currentCapacity;
    void extendArray();
};

#include "UniqueVector.cpp"
#endif
