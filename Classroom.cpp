#include "Classroom.h"
#include "UniqueVector.h"
#include <iostream>
using namespace std;

//Default constructor
Classroom::Classroom() {
    classroomVector = new UniqueVector<string>;
}

//Constructor with provided initial capacity.
Classroom::Classroom(unsigned const int initialCapacity) {
    classroomVector = new UniqueVector<string>(initialCapacity);
}

//Destructor
Classroom::~Classroom() {
    delete classroomVector;
}

//If a student named name is not already on the classroom roster, adds a new student
//  named name to the classroom roster and returns true; otherwise, returns false.
bool Classroom::addStudent(const string& name) {
    return classroomVector->insert(name);
}

//If a student named name is on the classroom roster, removes the student named name
//  from the classroom roster and returns true; otherwise, returns false.
bool Classroom::removeStudent(const string& name) {
    return classroomVector->remove(name);}

//If a student named name is on the classroom roster, returns true; otherwise, returns false.
bool Classroom::containsStudent(const string& name) {
    return classroomVector->contains(name);
}

//Returns a string containing the names of the students in the classroom, separated by commas.
string Classroom::listAllStudents() {
    string listOfStudents;
    string currentName;
    
    //Iterates through the classroomVector and adds each new name to the end of the string.
    for (unsigned int i = 0; i<(classroomVector->size()); i++) {
        listOfStudents+=studentAt(i);
        if (i<(classroomSize()-1)) {
            listOfStudents+=",";
        }
    }
    return listOfStudents;
}

//Removes and returns the student whose name comes lexicographically first on the classroom roster.
string Classroom::removeAlphabeticallyFirst() {
    string alphaFirst;
    string comparisonName;
    
    //Sets alphaFirst to the 0th element in the vector.
    alphaFirst=studentAt(0);
    
    //Iterates through the vector and compares alphaFirst with current name.
        for (unsigned int i = 1; i < classroomVector->size(); i++) {
            comparisonName=studentAt(i);
            if (alphaFirst.compare(comparisonName) > 0) {
                alphaFirst=comparisonName;
            }
        }
    removeStudent(alphaFirst);
    
    return alphaFirst;
}

//Removes and returns the student whose name comes lexicographically last on the classroom roster.
string Classroom::removeAlphabeticallyLast() {
    string alphaLast;
    string comparisonName;
    
    alphaLast=studentAt(0);

        for (unsigned int i = 1; i < classroomVector->size(); i++) {
            comparisonName=studentAt(i);
            if (alphaLast.compare(comparisonName) < 0) {
                alphaLast=comparisonName;
            }
        }
    removeStudent(alphaLast);
    
    return alphaLast;
}

//Adds all of the student names on otherClass’ roster onto the roster of the Classroom calling
//  this function and leaves otherClass unchanged.
void Classroom::combineClasses(Classroom& otherClass) {
    
    //Iterates through the otherClass' roster, and adds it to the current Class, if possible.
    for (unsigned int i = 0; i < otherClass.classroomSize(); i++) {
        addStudent(otherClass.studentAt(i));
    }
}

//Returns container size of Classroom.
unsigned int Classroom::classroomSize() const {
    return classroomVector->size();
}

//Returns name of student at position pos.
string Classroom::studentAt(unsigned int pos) const {
    string studentName;
    classroomVector->at(pos, studentName);
    return studentName;
}
