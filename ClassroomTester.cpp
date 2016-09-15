#include <iostream>
#include "Classroom.h"
#include "catch.h"

TEST_CASE("adding students preserves uniqueness","[addStudent]"){
	Classroom myClass;

	// Vector contains student after being added
	REQUIRE( myClass.addStudent("Simon") == true );
	REQUIRE( myClass.containsStudent("Simon") == true );

	// Vector doesn't contain student never added
	REQUIRE( myClass.containsStudent("Aarsh") == false );

	// Vector doesn't re-add existing student
	REQUIRE( myClass.addStudent("Simon") == false);

	// Stress testing (ish)
	REQUIRE( myClass.addStudent("John") == true);
	REQUIRE( myClass.addStudent("Jacob") == true);
	REQUIRE( myClass.addStudent("Jingle") == true);
	REQUIRE( myClass.addStudent("Heimer") == true);
	REQUIRE( myClass.addStudent("Schmidt") == true);

	// Vector contains all students added so far
	REQUIRE( myClass.containsStudent("Schmidt") == true);
	REQUIRE( myClass.containsStudent("Heimer") == true);
	REQUIRE( myClass.containsStudent("Jingle") == true);
	REQUIRE( myClass.containsStudent("Jacob") == true);
	REQUIRE( myClass.containsStudent("John") == true);
	REQUIRE( myClass.containsStudent("Simon") == true);

	// Removing an existing student returns true
	REQUIRE( myClass.removeStudent("Simon") == true);

	// Vector no longer contains removed student
	REQUIRE( myClass.containsStudent("Simon") == false);

	// Removing all students and performing same check
	REQUIRE( myClass.removeStudent("John") == true);
	REQUIRE( myClass.removeStudent("Jacob") == true);
	REQUIRE( myClass.removeStudent("Jingle") == true);
	REQUIRE( myClass.removeStudent("Heimer") == true);
	REQUIRE( myClass.removeStudent("Schmidt") == true);

	REQUIRE( myClass.containsStudent("Schmidt") == false);
	REQUIRE( myClass.containsStudent("Heimer") == false);
	REQUIRE( myClass.containsStudent("Jingle") == false);
	REQUIRE( myClass.containsStudent("Jacob") == false);
	REQUIRE( myClass.containsStudent("John") == false);
	REQUIRE( myClass.containsStudent("Simon") == false);
}

TEST_CASE("Alphabetical add/removal testing", "[alphabetical]"){
	Classroom myClass;
	SECTION("Alphabetically first simple"){
		REQUIRE( myClass.addStudent("A") == true );
		REQUIRE( myClass.addStudent("B") == true );
		REQUIRE( myClass.addStudent("C") == true );
		REQUIRE( myClass.addStudent("D") == true );
		REQUIRE( myClass.addStudent("E") == true );
		REQUIRE( myClass.addStudent("F") == true );
		REQUIRE( myClass.addStudent("G") == true );
		REQUIRE( myClass.addStudent("H") == true );
		REQUIRE( myClass.addStudent("I") == true );
		REQUIRE( myClass.addStudent("J") == true );
		REQUIRE( myClass.addStudent("K") == true );
		REQUIRE( myClass.addStudent("L") == true );
		REQUIRE( myClass.addStudent("M") == true );
		REQUIRE( myClass.addStudent("N") == true );
		REQUIRE( myClass.addStudent("O") == true );
		REQUIRE( myClass.addStudent("P") == true );

		REQUIRE( myClass.removeAlphabeticallyFirst() == "A" );
		REQUIRE( myClass.removeAlphabeticallyFirst() == "B" );
		REQUIRE( myClass.removeStudent("C") == true );
		REQUIRE( myClass.removeAlphabeticallyFirst() == "D" );

	}

	SECTION("Aplhabetically first complex"){

		REQUIRE( myClass.addStudent("aargau") == true );
		REQUIRE( myClass.addStudent("aargh") == true );
		REQUIRE( myClass.addStudent("aarhus") == true );
		REQUIRE( myClass.addStudent("aari") == true );

		// Alphabetically second:
		REQUIRE( myClass.addStudent("aaren") == true );

		REQUIRE( myClass.addStudent("aarika") == true );
		REQUIRE( myClass.addStudent("aariya") == true );
		REQUIRE( myClass.addStudent("aarnet") == true );
		REQUIRE( myClass.addStudent("aaron") == true );
		REQUIRE( myClass.addStudent("aaronic") == true );
		REQUIRE( myClass.addStudent("aaronical") == true );

		// Alphabetically first:
		REQUIRE( myClass.addStudent("aardvark") == true );

		// Removing from end of vector:
		REQUIRE( myClass.removeAlphabeticallyFirst() == "aardvark" );

		// Removing from middle of vector:
		REQUIRE( myClass.removeAlphabeticallyFirst() == "aaren" );

		// Removing from beginning of vector:
		REQUIRE( myClass.removeAlphabeticallyFirst() == "aargau" );


	}

	SECTION("Alphabetically last simple"){
		REQUIRE( myClass.addStudent("Q") == true );
		REQUIRE( myClass.addStudent("R") == true );
		REQUIRE( myClass.addStudent("S") == true );
		REQUIRE( myClass.addStudent("T") == true );
		REQUIRE( myClass.addStudent("U") == true );
		REQUIRE( myClass.addStudent("V") == true );
		REQUIRE( myClass.addStudent("W") == true );
		REQUIRE( myClass.addStudent("X") == true );
		REQUIRE( myClass.addStudent("Y") == true );
		REQUIRE( myClass.addStudent("Z") == true );

		REQUIRE( myClass.removeAlphabeticallyLast() == "Z" );
		REQUIRE( myClass.removeAlphabeticallyLast() == "Y" );
		REQUIRE( myClass.removeStudent("X") == true);
		REQUIRE( myClass.removeAlphabeticallyLast() == "W" );
	}
	SECTION("Alphabetically last complex"){
		REQUIRE( myClass.addStudent("zyzop") == true );
		REQUIRE( myClass.addStudent("zywiel") == true );

		// Alphabetically secondToLast:
		REQUIRE( myClass.addStudent("zyzzogeton") == true );

		REQUIRE( myClass.addStudent("zyxel") == true );
		REQUIRE( myClass.addStudent("zyzomys") == true );

		// Alphabetically last:
		REQUIRE( myClass.addStudent("zzzz") == true );

		// Removing from end of vector:
		REQUIRE( myClass.removeAlphabeticallyLast() == "zzzz" );

		// Removing from middle of vector:
		REQUIRE( myClass.removeAlphabeticallyLast() == "zyzzogeton" );

		// Removing from beginning of vector:
		REQUIRE( myClass.removeAlphabeticallyLast() == "zyzop" );
		
	}
}

TEST_CASE("Combining classes","[combine]"){
	Classroom class1,class2;
	
	SECTION("simple combine"){
		REQUIRE( class1.addStudent("A") == true );
		REQUIRE( class1.addStudent("B") == true );
		REQUIRE( class1.addStudent("C") == true );
		REQUIRE( class1.addStudent("D") == true );
		REQUIRE( class1.addStudent("E") == true );
		REQUIRE( class1.addStudent("F") == true );
		REQUIRE( class1.addStudent("G") == true );
		REQUIRE( class1.addStudent("H") == true );

		REQUIRE( class2.addStudent("I") == true );
		REQUIRE( class2.addStudent("J") == true );
		REQUIRE( class2.addStudent("K") == true );
		REQUIRE( class2.addStudent("L") == true );
		REQUIRE( class2.addStudent("M") == true );
		REQUIRE( class2.addStudent("N") == true );
		REQUIRE( class2.addStudent("O") == true );
		REQUIRE( class2.addStudent("P") == true );

		class1.combineClasses(class2);

		REQUIRE( class1.listAllStudents() == "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P");
	}

	SECTION("Combining non-unique classes"){
		REQUIRE( class1.addStudent("A") == true );
		REQUIRE( class1.addStudent("B") == true );
		REQUIRE( class1.addStudent("C") == true );
		REQUIRE( class1.addStudent("D") == true );
		REQUIRE( class1.addStudent("E") == true );
		REQUIRE( class1.addStudent("F") == true );
		REQUIRE( class1.addStudent("G") == true );
		REQUIRE( class1.addStudent("H") == true );
		REQUIRE( class1.addStudent("I") == true );
		REQUIRE( class1.addStudent("J") == true );
		REQUIRE( class1.addStudent("K") == true );

		REQUIRE( class2.addStudent("I") == true );
		REQUIRE( class2.addStudent("J") == true );
		REQUIRE( class2.addStudent("K") == true );
		REQUIRE( class2.addStudent("L") == true );
		REQUIRE( class2.addStudent("M") == true );
		REQUIRE( class2.addStudent("N") == true );
		REQUIRE( class2.addStudent("O") == true );
		REQUIRE( class2.addStudent("P") == true );

		class1.combineClasses(class2);

		REQUIRE( class1.listAllStudents() == "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P" );

	}



}