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
unsigned int UniqueVector<T>::capacity() const {
    return currentCapacity;
}

//Returns the current number of elements in the vector.
template <typename T>
unsigned int UniqueVector<T>::size() const{
    return numElements;
}

//If the vector contains zero elements, returns true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::empty() const {
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
            if (mainArray[i]==data) {       //Iterates through array to find a match
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
bool UniqueVector<T>::at(unsigned int pos, T& data) const {
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
    
    if (!this->contains(data)) {
        if (numElements == currentCapacity) {
            this->extendArray();    //If array is full, extend it
        }
        
        mainArray[numElements] = data;
        numElements+=1;
        
        insertSuccessful = true;
        
    }
    
    return insertSuccessful;
}

//If the vector does not already contain data, adds a new element, data, to the
//  vector at position pos, increases the container size by one, returns true;
//  otherwise, returns false. If the underlying array is full, creates a new array
//  with double the capacity and copies all of the elements over.
template <typename T>
bool UniqueVector<T>::insert(const T& data, unsigned int pos){
    bool insertSuccessful = false;
    
    if (!this->contains(data) && pos==0 && numElements==0){
        mainArray[pos] = data;              //If array is empty, inserts data into position 0
        numElements+=1;
        
        insertSuccessful = true;
        
    } else if (!this->contains(data) && pos<numElements) { //If array is not empty, move elements back
        if (numElements == currentCapacity) {
            this->extendArray();    //If array is full, extend it
        }
        
        for (unsigned int i = numElements; i > pos; i--) {
            mainArray[i]=mainArray[i-1];    //Move all elements after (and including) position pos
        }                                   //  back by 1 position
        
        mainArray[pos] = data;              //Stores data in position pos
        numElements+=1;
        
        insertSuccessful = true;
    }
    return insertSuccessful;
}

//If the vector does not already contain data, adds a new element, data, to the
//  front of the vector, increases the container size by one, and returns true;
//  otherwise, returns false. If the underlying array is full, creates a new array
//  with double the capacity and copies all of the elements over.
template <typename T>
bool UniqueVector<T>::push_front(const T& data){
    return this->insert(data,0); //Calls above function ;)
}

//If the vector contains data, removes data from the vector, reduces the container
//  size by one, leaves the capacity unchanged, and returns true; otherwise,
//  returns false.
template <typename T>
bool UniqueVector<T>::remove(const T& data){
    bool removeSuccessful = false;
    unsigned int pos = 0;
    T temp; //Placeholder variable to use when calling below function
    
    if (this->contains(data)) {     //If array contains data, find its position
        for (unsigned int i = 0; i < numElements; i++) {
            if (mainArray[i]==data) {
                pos=i;
                break;
            }
        }
        removeSuccessful = this->remove(pos,temp); //Calls below function to remove the data at position pos
    }
    
    return removeSuccessful;
}

//If pos is a valid position, removes the element in position pos, stores it in data,
//  reduces the container size by one, leaves the capacity unchanged, and returns true;
//  otherwise, returns false.
template <typename T>
bool UniqueVector<T>::remove(unsigned int pos, T& data){
    bool removeSuccessful = false;
    
    if (!this->empty() && pos<numElements) {
        
        data = mainArray[pos];    //Stores element at position pos to data before removing it
        
        if (pos==numElements-1) {
            numElements-=1;
            removeSuccessful = true;
        } else {
            for (unsigned int i = pos; i < numElements-1; i++) {
                mainArray[i]=mainArray[i+1];    //Moves all elements past position pos down by 1
            }
            
            numElements-=1;
            removeSuccessful = true;
        }
    }
    
    return removeSuccessful;
}

//If the vector is not empty, removes the last element in the vector, stores it in data,
//  reduces the container size by one, leaves the capacity unchanged, and returns
//  true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::pop_back(T& data){
    bool popSuccessful = false;
    
    if (!this->empty()) {
        data = mainArray[numElements-1];
        numElements-=1;
        popSuccessful = true;
    }
    
    
    return popSuccessful;
}

//Empties the vector of its elements and resets the capacity to 3.
template <typename T>
void UniqueVector<T>::clear(){
    delete[] mainArray;
    numElements = 0;
    currentCapacity = 3;
    mainArray = new T[currentCapacity];
}

//If the vector on the left hand side has the same elements in the same order as the
//  vector on the right hand side, returns true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::operator==(const UniqueVector& otherUniqueVector){
    bool vectorsAreEqual = true;
    
    //Checks if both vectors have the same size and capacity, then compares their contents
    if (otherUniqueVector.size()==numElements && otherUniqueVector.capacity()==currentCapacity) {
        if (numElements == 1) {
            T otherVectorVal;
            otherUniqueVector.at(0,otherVectorVal);
            if (mainArray[0]!=otherVectorVal) {
                vectorsAreEqual = false;
            }
        } else {
            for (unsigned int i = 0; i < numElements; i++) {
                T otherVectorVal;
                otherUniqueVector.at(i,otherVectorVal);
                if (mainArray[i]!=otherVectorVal) {
                    vectorsAreEqual = false;
                    break;
                }
            }
        }
    } else {
        vectorsAreEqual = false;
    }
    
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
