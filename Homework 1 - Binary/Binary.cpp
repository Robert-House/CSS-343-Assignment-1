//---------------------------------------------------------------------------
// BINARY.CPP
// Member function definitions for Binary class
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
#include "Binary.h"

#pragma region Constructor/Destructor
//------------------------------[Constructor]------------------------------
// Create an empty Binary object with a value of 0.
//
// Precondition:	None
// Postcondition:	Binary object is constructed with a value of 0.
Binary::Binary()
{
	// Use helper member to convert int to bin
	ConvertToBinary(0);
}

//------------------------------[Constructor]------------------------------
// Create an empty Binary object with a value of num.
//
// Precondition:	None
// Postcondition:	Binary object is constructed with a value of 0.
Binary::Binary(int num)
{
	// Use helper member to convert int to bin
	ConvertToBinary(num);
}

//------------------------------[Copy]-------------------------------------
// Copy Constructor for Binary class
//
// Precondition:	source is a valid reference
// Postcondition:	Binary object is constructed with the value of source.
Binary::Binary(const Binary &source)
{
	*this = source;
}

//------------------------------[Destructor]-------------------------------
// Destructor for Binary class
//
// Precondition:	ptr points to valid location.
// Postcondition:	memory at ptr is deallocated and ptr is set to NULL.
Binary::~Binary()
{
	delete _binaryData;
	_binaryData = NULL;
}
#pragma endregion

#pragma region Operator Overloads

//------------------------------[Operator+]-------------------------------- 
// Overloads the + operator.
//
// Precondition:  Reference to rightSide is valid.
// Postcondition: Returns a Binary object equal to the sum of A and B.
Binary Binary::operator+(const Binary& rightSide) const
{
	int tempInt = ConvertToInteger() + rightSide.ConvertToInteger();

	return Binary(tempInt);
}

//------------------------------[Operator-]--------------------------------
// Overload the - operator.
//
// Precondition:  Reference to rightSide is valid.
// Postcondition: Returns a Binary object equal to the difference of A and B.
Binary Binary::operator-(const Binary& rightSide) const
{
	int tempInt = ConvertToInteger() - rightSide.ConvertToInteger();

	return Binary(tempInt);
}

//------------------------------[Operator+=]-------------------------------
// Overload the += operator.
//
// Precondition:  Reference to rightSide is valid.
// Postcondition: Adds the value of rightSide to the value of this object
//				  and returns a reference to itself.
Binary& Binary::operator+=(Binary& rightSide)
{
	*this = *this + rightSide;

	return *this;
}

//------------------------------[Operator-=]-------------------------------
// Overload the -= operator.
//
// Precondition:  Reference to rightSide is valid.
// Postcondition: Subtracts the value of rightSide from the value of this 
//				  object and returns a reference to itself.
Binary& Binary::operator-=(Binary& rightSide)
{
	*this = *this - rightSide;

	return *this;
}

//------------------------------[Operator=]--------------------------------
// Overload the = operator.
//
// Precondition:  Reference to source is valid.
// Postcondition: Returns a deep copy of the source object.
Binary& Binary::operator=(const Binary &source)
{
	// Delete data in this array pointer
	delete _binaryData;
	_binaryData = NULL;

	// Deep copy the data
	_size = source._size;
	_isNegative = source._isNegative;

	// Allocate memory for new array
	_binaryData = new bool[_size];

	for (int i = 0; i < _size; i++)
	{
		// Copy every element
		_binaryData[i] = source._binaryData[i];
	}

	return *this;
}

//------------------------------[Operator==]-------------------------------
// Overload the == operator.
//
// Precondition:  Reference to rightSide is valid.
// Postcondition: Compares two binary numbers and returns true if they
//				  are equal.
bool Binary::operator==(const Binary &rightSide) const
{
	// Check sign bit for equivilence
	if (_isNegative != rightSide._isNegative)
	{
		return false;
	}

	// Check to see if the sizes are the same
	if (_size != rightSide._size)
	{
		// Not equivilent
		return false;
	}

	// Check to see if every bit in the array is equal
	// Already checked the size of the binary array so we
	// can assume that they are equal in length
	for (int i = 0; i < _size; i++)
	{
		// Compare each entry
		if (_binaryData[i] != rightSide._binaryData[i])
		{
			return false;
		}
	}

	// The two binary numbers are equivilent
	return true;
}

//------------------------------[Operator!=]-------------------------------
// Overload the != operator.
//
// Precondition:  Reference to rightSide is valid.
// Postcondition: Compares two binary numbers and returns true if they
//				  are not equal.
bool Binary::operator!=(const Binary &rightSide) const
{
	// Use == operator to check for equivilence
	if (*this == rightSide)
	{
		return false;
	}

	return true;
}

//------------------------------[Operator<<]-------------------------------
// Overload the << operator.
//
// Precondition:  Reference to source is valid.
// Postcondition: Prints binary number to the outstream.
ostream& operator<<(ostream &out, const Binary &source)
{
	// Check to see if the number is negative and print "-" to
	// out stream
	if (source._isNegative == true)
	{
		out << "-";
	}
	
	// Because our bits are stored from least->most significant, loop 
	// through backwards to print out to console
	for (int i = source._size - 1; i >= 0; i--)
	{
		if (source._binaryData[i] == true)
		{
			out << "1";
		}
		else
		{
			out << "0";
		}
	}

	return out;
}

//------------------------------[Operator>>]-------------------------------
// Overload the >> operator.
//
// Precondition:  in contains an integer and reference to source is valid.
// Postcondition: Takes input from in and converts the integer to a binary
//				  number.
istream& operator>>(istream &in, Binary &source)
{
	// Assume all input is an integer
	int temp = 0;

	in >> temp;
	source.ConvertToBinary(temp);

	return in;
}
#pragma endregion

#pragma region Accessors

//------------------------------[getBit]-----------------------------------
// Return the value of the bit at bitIndex.
//
// Precondition:  None
// Postcondition: Returns true if the bit at the index is 1 or false if
//				  the bit is 0.
bool Binary::getBit(int bitIndex) const
{
	if (!CheckInput(bitIndex))
	{
		return false;
	}

	// Assuming the input is correct every time
	return _binaryData[bitIndex];
}

#pragma endregion

#pragma region Mutators

//------------------------------[setBit]-----------------------------------
// Set bit at bitIndex to 1.
//
// Precondition:  None
// Postcondition: Returns true if the operation was successful.
bool Binary::setBit(int bitIndex)
{
	// Validate input. Silently fails if input is invalid.
	if (!CheckInput(bitIndex))
	{
		return false;
	}

	_binaryData[bitIndex] = true;

	return true;
}

//------------------------------[toggleBit]--------------------------------
// Toggles the bit at bitIndex.
//
// Precondition:  None
// Postcondition: Returns true if the operation was successful.
bool Binary::toggleBit(int bitIndex)
{
	// Validate input. Silently fails if input is invalid.
	if (!CheckInput(bitIndex))
	{
		return false;
	}

	// If true, set to false. Else set to true.
	if (_binaryData[bitIndex])
	{
		_binaryData[bitIndex] = false;
	}
	else
	{
		_binaryData[bitIndex] = true;
	}

	return true;
}

//------------------------------[clearBit]---------------------------------
// Set bit at bitIndex to 0.
//
// Precondition:  None
// Postcondition: Returns true if the operation was successful.
bool Binary::clearBit(int bitIndex)
{
	// Validate input. Silently fails if input is invalid.
	if (!CheckInput(bitIndex))
	{
		return false;
	}

	_binaryData[bitIndex] = false;

	return true;
}

#pragma endregion

#pragma region Private Members

//------------------------------[ConvertToInteger]-------------------------
// Convert binary number to a integer.
//
// Precondition:  None
// Postcondition: Returns the integer value of the binary number.
int Binary::ConvertToInteger() const
{
	int convertedBin = 0;

	// Handle case zero
	if (_binaryData[0] == false && _size == 1)
	{
		return convertedBin;
	}

	// Handle end/odd case
	if (_binaryData[0] == true)
	{
		convertedBin += 1;
	}

	// Convert the rest of the bits to a integer
	for (int i = 1; i < _size; i++)
	{
		if (_binaryData[i] == true)
		{
			// Each value held in the bit can be calculated
			// by the sum of 2^n where n is the bit index in the array
			int exponent = 1;

			// Nested loop because I can't use pow() :(
			for (int j = 0; j < i; j++)
			{
				exponent *= 2;
			}
			convertedBin += exponent;
		}
	}

	// Convert to negative if _isNegative is true
	if (_isNegative)
	{
		convertedBin = -convertedBin;
	}

	return convertedBin;
}

//------------------------------[ConvertToBinary]--------------------------
// Convert a integer to binary.
//
// Precondition:  None
// Postcondition: Returns if the conversion was successful.
bool Binary::ConvertToBinary(int num)
{
	int remainder = abs(num);
	int length = 0;
	int divisor = 0;

	// Clear old memory out if _binData is not null
	// Reset _isNegative to false
	{
		if (_binaryData != NULL)
		{
			delete _binaryData;
			_isNegative = false;
			_binaryData = NULL;
		}
	}

	// Check to see if the number is zero. If so, create bin array with
	// size of 1 and mark it zero.
	if (num == 0)
	{
		_binaryData = new bool[1];
		_binaryData[0] = 0;
		_size = 1;
		return true;
	}

	// Check if the number is negative. If so, change the sign bit
	if (num < 0)
	{
		_isNegative = true;
	}

	// Get the number of indices in the array
	while (remainder >= 1)
	{
		remainder = remainder / 2;
		length++;
	}

	// Create array of booleans and store size of array
	_size = length;
	_binaryData = new bool[length];
	remainder = abs(num);

	// Fill bin data
	// 
	for (int i = 0; i < length; i++)
	{
		divisor = remainder;

		// Record bit at index
		if (divisor % 2 == 1)
		{
			_binaryData[i] = true;
		}
		else
		{
			_binaryData[i] = false;
		}
		
		remainder = remainder / 2;
	}

	return true;
}

//------------------------------[CheckInput]-------------------------------
// Checks if the index is valid for this Binary object.
//
// Precondition:  None
// Postcondition: Returns true if the index is between 0 and _size - 1.
bool Binary::CheckInput(int index) const
{
	if (index < 0)
	{
		return false;
	}

	if (index > _size - 1)
	{
		return false;
	}

	return true;
}

#pragma endregion