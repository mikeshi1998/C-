// ITP 365 Fall 2018
// LP4 – Money
// Name: Yuchen Shi
// Email: yuchensh@usc.edu
// Platform: Mac

#pragma once
#include <iostream>

class Money
{
public:
    // Function: Parameterized Constructor
    // Purpose: Initializes dollars and cents to inputted values
    // Input: A long long holding the # of dollars an int holding the # of cents
    // Returns: Nothing
    Money(long long inDollars, long long inCents);
    
    // Function: Parameterized Constructor
    // Purpose: Initializes dollars and cents to inputted value
    // Input: A double holding both the dollars and cents,
    //   with fractional pennies discarded
    // Returns: Nothing
    Money(double inNumber);
    
    // Function: Default Constructor
    // Purpose: Initializes dollars and cents to 0
    // Input: None
    // Returns: Nothing
    Money();
    
    // Function: Addition operator
    // Purpose: Adds 2 Money values together
    // Input: The left and right Money values to add
    // Returns: A new Money object with the summed values
    friend Money operator+ (const Money& left, const Money& right);
    
    // Function: Subtraction operator
    // Purpose: Subtracts second money from 1st money
    // Input: The left and right Money values to subtract
    // Returns: A new Money object with the subtracted values
    friend Money operator- (const Money& left, const Money& right);
    
    // Function: Multiplication operator
    // Purpose: Multiples inputted money by a given factor
    // Input: The left value is the money, the right value is the factor
    // Returns: A new Money object with the multiplied values
    friend Money operator* (const Money& left, const double& right);
    
    // Function: Division operator
    // Purpose: Divides inputted money by a given factor
    // Input: The left value is the money, the right value is the factor
    // Returns: A new Money object with the divided values
    friend Money operator/ (const Money& left, const double& right);
    
    // Function: Output operator
    // Purpose: Writes the formatted money's value to the given stream
    // Input: The stream and the money to print
    // Returns: The modified stream
    friend std::ostream& operator<< (std::ostream& os, const Money& obj);
    
    // Function: Input operator
    // Purpose: Reads a money's value to the given stream
    // Input: The stream and the money to store the values in
    // Returns: The modified stream
    friend std::istream& operator>> (std::istream& is, Money& obj);
    
private:
    long long mDollars;            // Stores whole number of dollars
    short mCents;                // Stores whole number of cents
    
};
