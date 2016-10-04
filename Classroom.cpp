#include "Classroom.h"
#include "UniqueVector.h"
#include <iostream>
#include <string>
using namespace std;

//Returns a string containing the names of the students in the classroom, separated by commas.
string Classroom::listAllStudents() {
    string listOfStudents = "";
    string currentName = "";
    
    //Iterates through the classroomVector and adds each new name to the end of the string.
    for (unsigned int i = 0; i < classroomVector.size(); i++) {
        classroomVector.at(i, currentName);
        listOfStudents += currentName;
        if (i < classroomVector.size()-1) {
            listOfStudents += ",";
        }
    }
    return listOfStudents;
}

//Removes and returns the student whose name comes lexicographically first on the classroom roster.
string Classroom::removeAlphabeticallyFirst() {
    string alphaFirst = "";
    string comparisonName = "";
    
    //Sets alphaFirst to the 0th element in the vector.
    classroomVector.at(0, alphaFirst);
    
    //Iterates through the vector and compares alphaFirst with current name.
    for (unsigned int i = 1; i < classroomVector.size(); i++) {
        classroomVector.at(i, comparisonName);
        if (alphaFirst.compare(comparisonName) > 0) {
            alphaFirst = comparisonName;
        }
    }
    removeStudent(alphaFirst);
    
    return alphaFirst;
}

//Removes and returns the student whose name comes lexicographically last on the classroom roster.
string Classroom::removeAlphabeticallyLast() {
    string alphaLast = "";
    string comparisonName = "";
    
    //Sets alphaLast to the 0th element in the vector.
    classroomVector.at(0, alphaLast);

    //Iterates through the vector and compares alphaLast with current name.
    for (unsigned int i = 1; i < classroomVector.size(); i++) {
        classroomVector.at(i, comparisonName);
        if (alphaLast.compare(comparisonName) < 0) {
            alphaLast = comparisonName;
        }
    }
    removeStudent(alphaLast);
    
    return alphaLast;
}

//Adds all of the student names on otherClass’ roster onto the roster of the Classroom calling
//  this function and leaves otherClass unchanged.
void Classroom::combineClasses(Classroom& otherClassroom) {
    string otherStudent = "";
    
    //Iterates through the otherClass' roster, and adds it to the current Class, if possible.
    for (unsigned int i = 0; i < otherClassroom.classroomVector.size(); i++) {
        otherClassroom.classroomVector.at(i, otherStudent);
        addStudent(otherStudent);
    }
}
