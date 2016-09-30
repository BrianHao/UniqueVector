## Assignment 1 - UniqueVector and Classroom
See the assignment specification pdf. Don't forget to update this README. Happy coding!

Brian Hao
CSCI235

# UniqueVector 
A custom vector-like ADT that uses a dynamic array as its underlying data structure.
Each entry in the vector must be unique.

Includes member functions that allows the user to check for the following:
    * Vector capacity
    * Vector Size
    * Whether it's empty
    * Whether it contains a specific element

Also includes member functions that allows the user to interact with the vector:
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

# Classroom
Utilizes a UniqueVector to maintain a unique roster of students names, stored as strings.

Includes member functions that allows the user to:
    * Add a new student
    * Remove a student
    * Check if a specific student is in the roster
    * Remove the first alphabetical student
    * Remove the last alphabetical student
    * Generate a list of all the students in the roster


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
