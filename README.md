## Assignment 1 - UniqueVector and Classroom
See the assignment specification pdf. Don't forget to update this README. Happy coding!

Brian Hao

CSCI235


░░░░░░░░░▄░░░░░░░░░░░░░░▄░░░░
░░░░Much unique░░░░░░░▄▀▒▌░░░
░░░░░░░░▌▒▒█░░░░░░░░▄▀▒▒▒▐░░░
░░░░░░░▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐░░░
░░░░░▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒Wow░
░░░▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌░░░ 
░░▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒▌░░
░░▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐░░
░▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌░
░▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌░
▀▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒▐░
▐▒▒▐▀▐▀▒░▄▄▒▄▒▒▒▒▒▒░▒░▒░▒▒▒▒▌
▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▐░
░▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒░▒░▒░▒░▒▒▒▌░
░▐▒▒▒▒▒▒▒▒▒▒▒▒Very vector▒▐░░
░░▀▄▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▄▒▒▒▒▌░░
░░░So classroom▒▄▄▄▀▒▒▒▒▄▀░░░
░░░░░░▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀░░░░░
░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▀▀░░░░░░░░



## UniqueVector
A custom vector-like ADT that uses a dynamic array as its underlying data structure.

Each entry in the vector must be unique.


### Includes member functions that allows the user to check for the following:

    * Vector capacity

    * Vector Size

    * Whether it's empty

    * Whether it contains a specific element


### Also includes member functions that allows the user to interact with the vector:

    * Insert an element to the end of the vector

    * Insert an element to a position provided by the user

    * Insert an element to the front of the vector

    * Should it exist, remove an element from the vector

    * Remove an element from a user-provided position, if it is valid

    * Remove the last element from the vector

    * Clear the vector and reset it to its default capacity


Lastly, the comparison operator == is overloaded to compare between two UniqueVectors.

Both vectors must contain the same number of elements, as well as the same elements in

    the same order.

## Classroom
Utilizes a UniqueVector to maintain a unique roster of students names, stored as strings.


#### Includes member functions that allows the user to, through encapsulation, interact with the UniqueVector:

    * Add a new student (Using UniqueVector's insert() function)

    * Remove a student (Using UniqueVector's remove() function)

    * Check if a specific student is in the roster (Using UniqueVector's contains() function)

    * Remove the first alphabetical student

    * Remove the last alphabetical student

    * Generate a list of all the students in the roster


## Compilation Instructions
### To test the usage of the UniqueVector and Classroom classes:

$ make

$ ./UniqueVector

### To use a UniqueVector in your code
In your code, include the header file for the UniqueVector class where you are using it (Assuming main.cpp):
\#include <UniqueVector.h>

Compile using the following commands:

$ g++ -c -Wall -std=c++11 main.cpp -o main.o

$ g++ -c -Wall -std=c++11 UniqueVector.cpp -o UniqueVector.o

$ g++ -o YOUR_PROGRAM_NAME_HERE main.o UniqueVector.o

$ ./YOUR_PROGRAM_NAME_HERE



### To use the Classroom class in your code
In your code, include the header file for the Classroom class where you are using it (Assuming main.cpp):
\#include <Classroom.h>

Compile using the following commands:

$ g++ -c -Wall -std=c++11 main.cpp -o main.o

$ g++ -c -Wall -std=c++11 UniqueVector.cpp -o UniqueVector.o

$ g++ -c -Wall -std=c++11 Classroom.cpp -o Classroom.o

$ g++ -o YOUR_PROGRAM_NAME_HERE main.o UniqueVectorTester.o ClassroomTester.o UniqueVector.o Classroom.o

$ ./YOUR_PROGRAM_NAME_HERE
