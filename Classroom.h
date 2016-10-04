#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "UniqueVector.h"
#include <iostream>
#include <string>
using namespace std;

class Classroom {
    
public:
    Classroom() {};
    virtual ~Classroom() {};
    //Adds unique student to the end of the roster
    bool addStudent(const string& name) { return classroomVector.insert(name); };
    //Removes specified student from the roster
    bool removeStudent(const string& name) { return classroomVector.remove(name); };
    //Checks if specified student is in the roster
    bool containsStudent(const string& name) { return classroomVector.contains(name); };
    //Returns a list of the roster, separated by commas
    string listAllStudents();
    //Removes the alphabetically first student
    string removeAlphabeticallyFirst();
    //Removes the alphabetically last student
    string removeAlphabeticallyLast();
    //Merges a second roster with the current roster
    void combineClasses(Classroom& otherClass);
    
private:
    UniqueVector<string> classroomVector;
};

#endif
