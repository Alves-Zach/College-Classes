// Include guards
// #ifndef RATIO_H_INCLUDED
// #define RATIO_H_INCLUDED

#include <iostream>
#include <algorithm>
#include "Ratio.h"

using namespace std;

// Useful helper methods
bool Ratio::bothNegative(long numerIn, long denomIn) {
    if (numerIn < 0 && denomIn < 0) {
        return true;
    }
    return false;
}

bool Ratio::justDenomNegative(long numerIn, long denomIn) {
    if (denomIn < 0 && numerIn > 0) {
        return true;
    }
    return false;
}

// Constructors:
// Long ctor
Ratio::Ratio(long numeratorIn, long denominatorIn) {
    numer = numeratorIn;
    denom = denominatorIn;

    if (denominatorIn == 0) {
        throw runtime_error("Must enter a non-zero denominator");
    }

    if (justDenomNegative(numer, denom)) {
        denom *= -1;
        numer *= -1;
    }
    if (bothNegative(numer, denom)) {
        denom *= -1;
        numer *= -1;
    }
}

// Int ctor
Ratio::Ratio(int numeratorIn, int denominatorIn) {
    numer = numeratorIn;
    denom = denominatorIn;

    if (denominatorIn == 0) {
        throw runtime_error("Must enter a non-zero denominator");
    }

    if (justDenomNegative(numer, denom)) {
        denom *= -1;
        numer *= -1;
    }
    if (bothNegative(numer, denom)) {
        denom *= -1;
        numer *= -1;
    }
}

// Copy ctor
Ratio::Ratio(const Ratio &rhs) {
    numer = rhs.numer;
    denom = rhs.denom;
}

// Destructors
Ratio::~Ratio() { }

// Numerator methods:
// Getter
long Ratio::numerator() const {
    return numer;
}

// Setter
void Ratio::numerator(long numeratorIn) {
    numer = numeratorIn;
}

// Denominator methods:
// Getter
long Ratio::denominator() const {
    return denom;
}

// Setter
void Ratio::denominator(long denominatorIn) {
    denom = denominatorIn;
    if (bothNegative(numer, denom)) {
        numer *= -1;
        numer *= -1;
    }
    if (justDenomNegative(numer, denom)) {
        denom *= -1;
        numer *= -1;
    }
}

long double Ratio::ratio() const {
    long double ldNumer = numer;
    long double ldDenom = denom;

    return ldNumer/ldDenom;
}

// // Simplify methods
long Ratio::simplifyNum(long numIn, long denIn) {
    long greatCD = __gcd(numIn, denIn);

    return numIn/greatCD;
}

long Ratio::simplifyDen(long numIn, long denIn) {
    long greatCD = __gcd(numIn, denIn);

    return denIn/greatCD;
}

// Operators:
// Assignment Operator
Ratio &Ratio::operator=(const Ratio &rhs) {
    numer = rhs.numerator();
    denom = rhs.denominator();
    return *this;
}

// Addition methods
Ratio Ratio::add(const Ratio &r1) {
    long numerArg = (numer * r1.denominator()) + (r1.numerator() * denom);
    long newNum = simplifyNum(numerArg, denom * r1.denominator());
    long newDen = simplifyDen(numerArg, denom * r1.denominator());

    Ratio returnR(newNum, newDen);

    return returnR;
}

Ratio Ratio::add(const Ratio &r1, const Ratio &r2) const {
    Ratio returnR(numer, denom);
    returnR = returnR.add(r1);
    returnR = returnR.add(r2);

    return returnR;
}

Ratio Ratio::add(const Ratio &r1, const Ratio &r2, const Ratio &r3) const {
    Ratio returnR(numer, denom);
    returnR = returnR.add(r1);
    returnR = returnR.add(r2);
    returnR = returnR.add(r3);

    return returnR;
}

Ratio Ratio::add(const Ratio &r1, const Ratio &r2, const Ratio &r3,
     const Ratio &r4) const {
    Ratio returnR(numer, denom);
    returnR = returnR.add(r1);
    returnR = returnR.add(r2);
    returnR = returnR.add(r3);
    returnR = returnR.add(r4);

    return returnR;
}

Ratio Ratio::add(const Ratio &r1, const Ratio &r2, const Ratio &r3, const Ratio &r4,
    const Ratio &r5) const {
    Ratio returnR(numer, denom);
    returnR = returnR.add(r1);
    returnR = returnR.add(r2);
    returnR = returnR.add(r3);
    returnR = returnR.add(r4);
    returnR = returnR.add(r5);

    return returnR;
}

Ratio Ratio::add(const Ratio &r1, const Ratio &r2, const Ratio &r3, const Ratio &r4,
    const Ratio &r5, const Ratio &r6) const {
    Ratio returnR(numer, denom);
    returnR = returnR.add(r1);
    returnR = returnR.add(r2);
    returnR = returnR.add(r3);
    returnR = returnR.add(r4);
    returnR = returnR.add(r5);
    returnR = returnR.add(r6);

    return returnR;
}

Ratio Ratio::add(const Ratio &r1, const Ratio &r2, const Ratio &r3, const Ratio &r4,
    const Ratio &r5, const Ratio &r6, const Ratio &r7) const {
    Ratio returnR(numer, denom);
    returnR = returnR.add(r1);
    returnR = returnR.add(r2);
    returnR = returnR.add(r3);
    returnR = returnR.add(r4);
    returnR = returnR.add(r5);
    returnR = returnR.add(r6);
    returnR = returnR.add(r7);

    return returnR;
}

Ratio Ratio::add(const Ratio &r1, const Ratio &r2, const Ratio &r3, const Ratio &r4,
    const Ratio &r5, const Ratio &r6, const Ratio &r7, const Ratio &r8) const {
    Ratio returnR(numer, denom);
    returnR = returnR.add(r1);
    returnR = returnR.add(r2);
    returnR = returnR.add(r3);
    returnR = returnR.add(r4);
    returnR = returnR.add(r5);
    returnR = returnR.add(r6);
    returnR = returnR.add(r7);
    returnR = returnR.add(r8);

    return returnR;
}

// Multiplication:
Ratio Ratio::multiply(const Ratio &r1) {
    long newNum = simplifyNum(numer * r1.numerator(), denom * r1.denominator());
    long newDen = simplifyDen(numer * r1.numerator(), denom * r1.denominator());

    Ratio returnR(newNum, newDen);

    return returnR;
}

// Division:
Ratio Ratio::divide(const Ratio &r1) {
    long newNum = simplifyNum(numer * r1.denominator(), denom * r1.numerator());
    long newDen = simplifyDen(numer * r1.denominator(), denom * r1.numerator());

    Ratio returnR(newNum, newDen);

    return returnR;
}

// Subtraction:
Ratio Ratio::subtract(const Ratio &r1) {
    // Make r1 negative and then call add
    Ratio negR1(r1.numerator() * -1, r1.denominator());

    Ratio returnR(numer, denom);
    returnR = returnR.add(negR1);

    return returnR;
}

// Comparison methods:
int Ratio::compare(const Ratio &r1) {
    if (numer == r1.numerator() && denom == r1.denominator()) {
        return 0;
    }
    if (ratio() < r1.ratio()) {
        return -1;
    }
    if (ratio() > r1.ratio()) {
        return 1;
    }
    return -1;
}

int Ratio::compare(long double decimalIn) {
    if (ratio() == decimalIn) {
        return 0;
    }
    else if(ratio() < decimalIn) {
        return -1;
    }
    else {
        return 1;
    }
}

// ostream things
ostream &operator<<(ostream &stream, const Ratio &r1) {
    return stream << r1.numerator() << '/' << r1.denominator();
}

istream &operator>>(istream &stream, const Ratio &r1) {
    if (r1.denominator() == 0) {
        throw runtime_error("Must enter a non-zero denominator");
    }
    stream >> r1.numerator() >> '/' >> r1.denominator();
    return stream;
}
