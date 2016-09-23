//#define CATCH_CONFIG_MAIN
//#include "catch.h"

//FOR MY OWN TESTING
#include "UniqueVector.h"
#include "Classroom.h"
#include <iostream>
using namespace std;

int main() {
    UniqueVector<int> vecA;
    UniqueVector<string> vecB(8);
    
    cout << "Vector A's capacity: " << vecA.capacity() << endl;
    cout << "Vector B's capacity: " << vecB.capacity() << endl;
    
    
    return 0;
}
