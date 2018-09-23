// ITP 365 Fall 2018
// LP4 – Money
// Name: Yuchen Shi
// Email: yuchensh@usc.edu
// Platform: Mac

#include "money.h"

// Implementation of the Money Class

Money::Money(long long inDollars, long long inCents)
{
    long long total = inDollars * 100 + inCents; // Calculate the total amount in cents
    long long dollars = total/100; // Calculate the dollars
    short cents = total - dollars*100; // Calculate the cents
    mDollars = dollars;
    mCents = cents;
}

Money::Money(double inNumber)
{
    long long cents = inNumber * 100; // Convet it to cents first
    mDollars = cents/100; // Calculate the dollars
    mCents = cents - mDollars*100; // Calculate the cents
}

Money::Money() // Default constructor
{
    mDollars = 0;
    mCents = 0;
}

Money operator+(const Money& left, const Money& right)
{
    long long leftCents = left.mDollars*100 + left.mCents;
    long long rightCents = right.mDollars*100 + right.mCents;
    long long result = leftCents + rightCents; // Convert to cents and then do the calculation
    double dollar = result/100.0; // Convert back to the "Money" format
    Money retVal = Money(dollar);
    return retVal;
}

Money operator- (const Money& left, const Money& right)
{
    long long leftCents = left.mDollars*100 + left.mCents;
    long long rightCents = right.mDollars*100 + right.mCents;
    long long result = leftCents - rightCents; // Convert to cents and then do the calculation
    double dollar = result/100.0; // Convert back to the "Money" format
    Money retVal = Money(dollar);
    return retVal;
}

Money operator* (const Money& left, const double& right)
{
    double cent = left.mCents / 100.0; // Convert the cents part to a double
    double money = left.mDollars + cent;
    double result = money * right; // Double times double is a double
    Money retVal = Money(result);
    return retVal;
}

Money operator/ (const Money& left, const double& right)
{
    double cent = left.mCents / 100.0; // Convert the cents part to a double
    double money = left.mDollars + cent;
    double result = money/right; // Double divides by double is a double
    Money retVal = Money(result);
    return retVal;
}

std::ostream& operator<< (std::ostream& os, const Money& obj)
{
    // If mDollars is less than 0, mCents must also be less than 0, but we only want the negative sign in front of the dollar, but not the cent, so add a negative sign before obj.mCents.
    if (obj.mDollars < 0)
    {
        // If the mCents is just one digit, add a "0" before -obj.mCents, so that "1" could become "01".
        if (obj.mCents >= -9)
        {
            os << "$" << obj.mDollars << ".0" << -obj.mCents;
        }
        else
        {
            os << "$" << obj.mDollars << "." << -obj.mCents;
        }
    }
    // If mDollar equals to 0, but mCents is less than 0, we would need to add a negative sign in front of the 0, but no negative sign in front of the cents.
    else if (obj.mDollars == 0 && obj.mCents < 0)
    {
        // If the mCents is just one digit, add a "0" before -obj.mCents, so that "1" could become "01".
        if (obj.mCents >= -9)
        {
            os << "$-" << obj.mDollars << ".0" << -obj.mCents;
        }
        else
        {
            os << "$-" << obj.mDollars << "." << -obj.mCents;
        }
    }
    // As long as the amount is not negative, display it in the normal way.
    else
    {
        // If the mCents is just one digit, add a "0" before -obj.mCents, so that "1" could become "01".
        if (obj.mCents < 9)
        {
            os << "$" << obj.mDollars << ".0" << obj.mCents;
        }
        else
        {
            os << "$" << obj.mDollars << "." << obj.mCents;
        }
    }
    return os;
}

std::istream& operator>> (std::istream& is, Money& obj)
{
    double input;
    is >> input; // Store the input
    long long cents = input*100; // Convert the amount entered to cents
    obj.mDollars = cents/100; // Calculate the mDollars
    obj.mCents = cents- obj.mDollars*100; // Calculate the mCents
    return is;
}




