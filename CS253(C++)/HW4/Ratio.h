// Include guards
#ifndef RATIO_H_INCLUDED
#define RATIO_H_INCLUDED

#include <iostream>

class Ratio {
    public:
    // Useful helper methods
    bool bothNegative(long numerIn, long denomIn);
    bool justDenomNegative(long numerIn, long denomIn);

    // Constructors:
        // No default ctor
        Ratio() = delete;

        // Long ctor
        Ratio(long, long = 1);

        // Int ctor
        Ratio(int, int = 1);

        // Copy ctor
        Ratio(const Ratio &);

    // Destructors:
        ~Ratio();

    // Numerator methods:
        // Getter
        long numerator() const;

        // Setter
        void numerator(long);

    // Denominator methods:
        // Getter
        long denominator() const;

        // Setter
        void denominator(long);

        long double ratio() const;\

    // Simplify methods:
        long simplifyNum(long, long);
        long simplifyDen(long, long);

    // Operators:
        // Assignment Operator:
        Ratio &operator=(const Ratio &);

        // Addition methods:
        Ratio add(const Ratio &);

        Ratio add(const Ratio &, const Ratio &) const;

        Ratio add(const Ratio &, const Ratio &, const Ratio &) const;

        Ratio add(const Ratio &, const Ratio &, const Ratio &, const Ratio &) const;

        Ratio add(const Ratio &, const Ratio &, const Ratio &, const Ratio &,
                    const Ratio &) const;

        Ratio add(const Ratio &, const Ratio &, const Ratio &, const Ratio &, const Ratio &,
                    const Ratio &) const;

        Ratio add(const Ratio &, const Ratio &, const Ratio &, const Ratio &, const Ratio &,
                    const Ratio &, const Ratio &) const;

        Ratio add(const Ratio &, const Ratio &, const Ratio &, const Ratio &, const Ratio &,
                    const Ratio &, const Ratio &, const Ratio &) const;

        // Multiplication
        Ratio multiply(const Ratio &);

        // Division:
        Ratio divide(const Ratio &);

        // Subtraction:
        Ratio subtract(const Ratio &);

        // Comparison methods:
        int compare(const Ratio &);
        int compare(long double);


    private:
        // The normal numerator and denominator
        long numer;
        long denom;

        // Numerator and denominator as ints to save space
        int numeratorInt;
        int denominatorInt;

};

// ostream things
std::ostream &operator<<(std::ostream &, const Ratio &);
std::istream &operator>>(std::istream &, const Ratio &);

#endif /* COMPLEX_H_INCLUDED */
