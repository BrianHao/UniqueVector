#ifndef UNIQUEVECTOR_CPP
#define UNIQUEVECTOR_CPP
#include "UniqueVector.h"
#include <iostream>
using namespace std;

//Default constructor
template <typename T>
UniqueVector<T>::UniqueVector() {
    numElements = 0;
    currentCapacity = 3;
    mainArray = new T[currentCapacity];
}

//Constructor with provided initial capacity
template <typename T>
UniqueVector<T>::UniqueVector(unsigned const int initialCapacity) {
    numElements = 0;
    currentCapacity = initialCapacity;
    mainArray = new T[currentCapacity];
}

//Destructor
template <typename T>
UniqueVector<T>::~UniqueVector() {
    if (numElements != 0) {
        delete[] mainArray;
    }
    return;
}

//Returns the size of the space currently allocated for the vector.
template <typename T>
unsigned int UniqueVector<T>::capacity() {
    return currentCapacity;
}

//Returns the current number of elements in the vector.
template <typename T>
unsigned int UniqueVector<T>::size() {
    return numElements;
}

//If the vector contains zero elements, returns true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::empty() {
    if (numElements == 0) {
        return true;
    } else {
        return false;
    }
}

//If the vector contains data, returns true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::contains(const T& data){
    bool hasData = false;
    if (!this->empty()) {
        for (unsigned int i = 0; i < numElements; i++) {
            if (mainArray[i]==data) {
                hasData = true;
                break;
            }
        }
    }
    
    return hasData;
}

//If pos is a valid position, retrieves the element in position pos in the array,
//  stores it in data, and returns true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::at(unsigned int pos, T& data) {
    if (!this->empty() && pos<numElements) {
        data = mainArray[pos];
        return true;
    } else {
        return false;
    }
}

//If the vector does not already contain data, adds a new element, data, to the
//  back of the vector, increases the container size by one, and returns true;
//  otherwise, returns false. If the underlying array is full, creates a new
//  array with double the capacity and copies all of the elements over.
template <typename T>
bool UniqueVector<T>::insert(const T& data) {
    bool insertSuccessful = false;
    
    return insertSuccessful;
}

//If the vector does not already contain data, adds a new element, data, to the
//  vector at position pos, increases the container size by one, returns true;
//  otherwise, returns false. If the underlying array is full, creates a new array
//  with double the capacity and copies all of the elements over.
template <typename T>
bool UniqueVector<T>::insert(const T& data, unsigned int pos){
    bool insertSuccessful = false;
    
    return insertSuccessful;
}

//If the vector does not already contain data, adds a new element, data, to the
//  front of the vector, increases the container size by one, and returns true;
//  otherwise, returns false. If the underlying array is full, creates a new array
//  with double the capacity and copies all of the elements over.
template <typename T>
bool UniqueVector<T>::push_front(const T& data){
    bool pushSuccessful = false;
    
    return pushSuccessful;
}

//If the vector contains data, removes data from the vector, reduces the container
//  size by one, leaves the capacity unchanged, and returns true; otherwise,
//  returns false.
template <typename T>
bool UniqueVector<T>::remove(const T& data){
    bool removeSuccessful = false;
    
    return removeSuccessful;
}

//If pos is a valid position, removes the element in position pos, stores it in data,
//  reduces the container size by one, leaves the capacity unchanged, and returns true;
//  otherwise, returns false.
template <typename T>
bool UniqueVector<T>::remove(unsigned int pos, T& data){
    bool removeSuccessful = false;
    
    return removeSuccessful;
}

//If the vector is not empty, removes the last element in the vector, stores it in data,
//  reduces the container size by one, leaves the capacity unchanged, and returns
//  true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::pop_back(T& data){
    bool popSuccessful = false;
    
    return popSuccessful;
}

//Empties the vector of its elements and resets the capacity to 3.
template <typename T>
void UniqueVector<T>::clear(){
    
}

//If the vector on the left hand side has the same elements in the same order as the
//  vector on the right hand side, returns true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::operator==(const UniqueVector& otherUniqueVector){
    bool vectorsAreEqual = false;
    
    return vectorsAreEqual;
}

//Copies the main array into a temporary array, deletes the current array,
//  then creates a new array of double the current capacity. Finally, copy the
//  contents of the temporary array into the new array.
template <typename T>
void UniqueVector<T>::extendArray() {
    T* tempArray = mainArray;               //Creates temp array & copies over main array
    
    delete[] mainArray;                     //Delete current main array
    
    currentCapacity*=2;                         //Double capacity
    mainArray = new T[currentCapacity];         //Creates new main array with double capacity
    
    for (unsigned int i = 0; i < numElements; i++) {
        mainArray[i]=tempArray[i];          //Copies temp array to the new main array
    }
    
    return;
}

#endif
