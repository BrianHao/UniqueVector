#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "UniqueVector.h"
#include <iostream>
using namespace std;

class Classroom {
    
public:
    Classroom();
    Classroom(unsigned const int initialCapacity);
    virtual ~Classroom();
    bool addStudent(const string& name);
    bool removeStudent(const string& name);
    bool containsStudent(const string& name);
    string listAllStudents();
    string removeAlphabeticallyFirst();
    string removeAlphabeticallyLast();
    void combineClasses(Classroom& otherClass);
    
private:
    UniqueVector<string>* classroomVector;
};

#endif
