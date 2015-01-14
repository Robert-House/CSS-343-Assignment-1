//---------------------------------------------------------------------------
// BINARY.H
// Interface for Binary class
// Author:  Robert House
//---------------------------------------------------------------------------
// Binary class: Contains a binary representation of a number. Stored from
// least->most significant
//	 -- Allows for basic math operations on the number
//	 -- Ability to toggle individual bits
//	 -- Print to console
//
// Assumptions:
//   -- >> overload will always be an integer
//---------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class Binary
{
public:
#pragma region Constructor/Destructor
	//------------------------------[Constructor]------------------------------
	// Create an empty Binary object with a value of 0.
	//
	// Precondition:	None
	// Postcondition:	Binary object is constructed with a value of 0.
	Binary();

	//------------------------------[Constructor]------------------------------
	// Create an empty Binary object with a value of num.
	//
	// Precondition:	None
	// Postcondition:	Binary object is constructed with a value of 0.
	Binary(int num);

	//------------------------------[Copy]-------------------------------------
	// Copy Constructor for Binary class
	//
	// Precondition:	source is a valid reference
	// Postcondition:	Binary object is constructed with the value of source.
	Binary(const Binary &source);

	//------------------------------[Destructor]-------------------------------
	// Destructor for Binary class
	//
	// Precondition:	ptr points to valid location.
	// Postcondition:	memory at ptr is deallocated and ptr is set to NULL.
	~Binary();
#pragma endregion

#pragma region Operator Overloads

	//------------------------------[Operator+]-------------------------------- 
	// Overloads the + operator.
	//
	// Precondition:  Reference to rightSide is valid.
	// Postcondition: Returns a Binary object equal to the sum of A and B.
	Binary Binary::operator+(const Binary& rightSide) const;

	//------------------------------[Operator-]--------------------------------
	// Overload the - operator.
	//
	// Precondition:  Reference to rightSide is valid.
	// Postcondition: Returns a Binary object equal to the difference of A and B.
	Binary Binary::operator-(const Binary& rightSide) const;

	//------------------------------[Operator+=]-------------------------------
	// Overload the += operator.
	//
	// Precondition:  Reference to rightSide is valid.
	// Postcondition: Adds the value of rightSide to the value of this object
	//				  and returns a reference to itself.
	Binary& Binary::operator+=(Binary &rightSide);

	//------------------------------[Operator-=]-------------------------------
	// Overload the -= operator.
	//
	// Precondition:  Reference to rightSide is valid.
	// Postcondition: Subtracts the value of rightSide from the value of this 
	//				  object and returns a reference to itself.
	Binary& Binary::operator-=(Binary &rightSide);

	//------------------------------[Operator=]--------------------------------
	// Overload the = operator.
	//
	// Precondition:  Reference to source is valid.
	// Postcondition: Returns a deep copy of the source object.
	Binary& Binary::operator=(const Binary &source);

	//------------------------------[Operator==]-------------------------------
	// Overload the == operator.
	//
	// Precondition:  Reference to rightSide is valid.
	// Postcondition: Compares two binary numbers and returns true if they
	//				  are equal.
	bool Binary::operator==(const Binary &rightSide) const;

	//------------------------------[Operator!=]-------------------------------
	// Overload the != operator.
	//
	// Precondition:  Reference to rightSide is valid.
	// Postcondition: Compares two binary numbers and returns true if they
	//				  are not equal.
	bool Binary::operator!=(const Binary &rightSide) const;

	//------------------------------[Operator<<]-------------------------------
	// Overload the << operator.
	//
	// Precondition:  Reference to source is valid.
	// Postcondition: Prints binary number to the outstream.
	friend ostream& operator<<(ostream &out, const Binary &source);

	//------------------------------[Operator>>]-------------------------------
	// Overload the >> operator.
	//
	// Precondition:  in contains an integer and reference to source is valid.
	// Postcondition: Takes input from in and converts the integer to a binary
	//				  number.
	friend istream& operator>>(istream &in, Binary &source);
	
#pragma endregion

#pragma region Accessors

	//------------------------------[getBit]-----------------------------------
	// Return the value of the bit at bitIndex.
	//
	// Precondition:  None
	// Postcondition: Returns true if the bit at the index is 1 or false if
	//				  the bit is 0.
	bool getBit(int bitIndex) const;

#pragma endregion

#pragma region Mutators

	//------------------------------[setBit]-----------------------------------
	// Set bit at bitIndex to 1.
	//
	// Precondition:  None
	// Postcondition: Returns true if the operation was successful.
	bool setBit(int bitIndex);

	//------------------------------[toggleBit]--------------------------------
	// Toggles the bit at bitIndex.
	//
	// Precondition:  None
	// Postcondition: Returns true if the operation was successful.
	bool toggleBit(int bitIndex);

	//------------------------------[clearBit]---------------------------------
	// Set bit at bitIndex to 0.
	//
	// Precondition:  None
	// Postcondition: Returns true if the operation was successful.
	bool clearBit(int bitIndex);

#pragma endregion

private:
	bool _isNegative = false;
	bool *_binaryData = NULL;
	int _size = 0;

#pragma region Private Members

	//------------------------------[ConvertToInteger]-------------------------
	// Convert binary number to a integer.
	//
	// Precondition:  None
	// Postcondition: Returns the integer value of the binary number.
	int ConvertToInteger() const;

	//------------------------------[ConvertToBinary]--------------------------
	// Convert a integer to binary.
	//
	// Precondition:  None
	// Postcondition: Returns if the conversion was successful.
	bool ConvertToBinary(int num);

	//------------------------------[CheckInput]-------------------------------
	// Checks if the index is valid for this Binary object.
	//
	// Precondition:  None
	// Postcondition: Returns true if the index is between 0 and _size - 1.
	bool CheckInput(int index) const;

#pragma endregion
};