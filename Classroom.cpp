#include "Classroom.h"
#include "UniqueVector.h"
#include <iostream>
#include <string>
using namespace std;

//Default constructor
Classroom::Classroom(){
    classroomVector = new UniqueVector<string>;
}

//Constructor with provided initial capacity.
Classroom::Classroom(unsigned const int initialCapacity){
    classroomVector = new UniqueVector<string>(initialCapacity);
}

//Destructor
Classroom::~Classroom(){
    if (!classroomVector->empty()) {
        delete classroomVector;
    }
    
}

//If a student named name is not already on the classroom roster, adds a new student
//  named name to the classroom roster and returns true; otherwise, returns false.
bool Classroom::addStudent(const string& name){
    
    return 0;
    
}

//If a student named name is on the classroom roster, removes the student named name
//  from the classroom roster and returns true; otherwise, returns false.
bool Classroom::removeStudent(const string& name){
    return 0;
}

//If a student named name is on the classroom roster, returns true; otherwise, returns false.
bool Classroom::containsStudent(const string& name){
    return 0;
}

//Returns a string containing the names of the students in the classroom, separated by commas.
string Classroom::listAllStudents(){
    return 0;
}

//Removes and returns the student whose name comes lexicographically first on the classroom roster.
string Classroom::removeAlphabeticallyFirst(){
    return 0;
}

//Removes and returns the student whose name comes lexicographically last on the classroom roster.
string Classroom::removeAlphabeticallyLast(){
    return 0;
}

//Adds all of the student names on otherClass’ roster onto the roster of the Classroom calling
//  this function and leaves otherClass unchanged.
void Classroom::combineClasses(Classroom& otherClass){
    
}
