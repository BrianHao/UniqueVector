#ifndef UNIQUEVECTOR_CPP
#define UNIQUEVECTOR_CPP
#include "UniqueVector.h"
#include <iostream>
using namespace std;

//Default constructor
template <typename T>
UniqueVector<T>::UniqueVector(unsigned int initialCapacity)  : currentCapacity(initialCapacity) {
    mainArray = new T[currentCapacity];
}

//If the vector contains data, returns true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::contains(const T& data) {
    if (numElements>0) {
        for (unsigned int i = 0; i < numElements; i++) {
            if (mainArray[i]==data) {       //Iterates through array to find a match
                return true;
            }
        }
    }
    return false;
}

//If the vector contains data, returns true; otherwise, returns false.
//  If true, sets pos to the position data was at.
template <typename T>
bool UniqueVector<T>::contains(const T& data, unsigned int& pos) {
    if (numElements>0) {
        for (unsigned int i = 0; i < numElements; i++) {
            if (mainArray[i]==data) {       //Iterates through array to find a match
                pos = i;
                return true;
            }
        }
    }
    return false;
}

//If pos is a valid position, retrieves the element in position pos in the array,
//  stores it in data, and returns true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::at(unsigned int pos, T& data) {
    if (numElements<=0 || pos>=numElements) {
        return false;
    }
    data = mainArray[pos];
    return true;

}

//If the vector does not already contain data, adds a new element, data, to the
//  back of the vector, increases the container size by one, and returns true;
//  otherwise, returns false. If the underlying array is full, creates a new
//  array with double the capacity and copies all of the elements over.
template <typename T>
bool UniqueVector<T>::insert(const T& data) {
    if (contains(data)) {
        return false;
    } else {
        if (numElements == currentCapacity) {
            extendArray();    //If array is full, extend it
        }
        mainArray[numElements] = data;
        numElements++;
        return true;
    }
}

//If the vector does not already contain data, adds a new element, data, to the
//  vector at position pos, increases the container size by one, returns true;
//  otherwise, returns false. If the underlying array is full, creates a new array
//  with double the capacity and copies all of the elements over.
template <typename T>
bool UniqueVector<T>::insert(const T& data, unsigned int pos) {
    if (contains(data) || pos > numElements) {
        return false;
    } else {
        if (numElements == currentCapacity) {
            extendArray();    //If array is full, extend it
        }
        if (pos != numElements){
            for (unsigned int i = numElements; i > pos; i--) {
                mainArray[i]=mainArray[i-1];    //Move all elements after (and including) position pos
            }                                   //  back by 1 position
        }
        mainArray[pos] = data;              //Stores data in position pos
        numElements++;
        return true;
    }
}

//If the vector contains data, removes data from the vector, reduces the container
//  size by one, leaves the capacity unchanged, and returns true; otherwise,
//  returns false.
template <typename T>
bool UniqueVector<T>::remove(const T& data) {
    unsigned int pos;
    T temp; //Placeholder variable to use when calling below function
    
    if (contains(data, pos)) {     //If array contains data, find its position
        return remove(pos, temp); //Calls below function to remove the data at position pos
    } else {
        return false;
    }
}

//If pos is a valid position, removes the element in position pos, stores it in data,
//  reduces the container size by one, leaves the capacity unchanged, and returns true;
//  otherwise, returns false.
template <typename T>
bool UniqueVector<T>::remove(unsigned int pos, T& data) {
    if (numElements<=0 || pos>=numElements) {
        return false;
    } else {
        data = mainArray[pos];    //Stores element at position pos to data before removing it
        
        for (unsigned int i = pos; i < numElements-1; i++) {
            mainArray[i]=mainArray[i+1];    //Moves all elements past position pos down by 1
        }
        numElements--;
        return true;
    }
}

//If the vector is not empty, removes the last element in the vector, stores it in data,
//  reduces the container size by one, leaves the capacity unchanged, and returns
//  true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::pop_back(T& data) {
    if (numElements<=0) {
        return false;
    } else {
        data = mainArray[numElements-1];
        numElements--;
        return true;
    }
}

//Empties the vector of its elements and resets the capacity to 3.
template <typename T>
void UniqueVector<T>::clear() {
    delete[] mainArray;
    numElements = 0;
    currentCapacity = 3;
    mainArray = new T[currentCapacity];
}

//If the vector on the left hand side has the same elements in the same order as the
//  vector on the right hand side, returns true; otherwise, returns false.
template <typename T>
bool UniqueVector<T>::operator==(const UniqueVector<T>& otherUniqueVector) {
    //Checks if both vectors have the same size.
    if (otherUniqueVector.numElements == numElements) {
        if (numElements == 0) { //Both vectors are empty.
            return true;
        } else { //Vectors are not empty, compares their contents.
            for (unsigned int i = 0; i < numElements; i++) {
                if (mainArray[i] != otherUniqueVector.mainArray[i]) {
                    return false;
                }
            }
        }
    } else { //Vectors have different sizes
        return false;
    }
    return true;
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
