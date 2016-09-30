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
    bool addStudent(const string& name) { return classroomVector.insert(name); }; //Adds unique student to the end of the roster
    bool removeStudent(const string& name) { return classroomVector.remove(name); }; //Removes specified student from the roster
    bool containsStudent(const string& name) { return classroomVector.contains(name); };   //Checks if specified student is in the roster
    string listAllStudents();   //Returns a list of the roster, separated by commas
    string removeAlphabeticallyFirst(); //Removes the alphabetically first student
    string removeAlphabeticallyLast();  //Removes the alphabetically last student
    void combineClasses(Classroom& otherClass); //Merges a second roster with the current roster
    
private:
    UniqueVector<string> classroomVector;
};

#endif
