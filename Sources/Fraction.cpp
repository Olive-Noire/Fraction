#include "../Headers/Fraction.hpp"

#include <iostream>
#include <cassert>

Fraction::Fraction() : _numerator{0}, _denominator{1} {}

Fraction::Fraction(int n) : _numerator{n}, _denominator{1} {}

Fraction::Fraction(int n, unsigned int d) : _numerator{n}, _denominator{d} {

    assert(d != 0 && "Can't create fraction with a denominator null");
    _Simplify();

}

Fraction::Fraction(double n) : _denominator{1} {

    while (n != static_cast<int>(n)) {

        n *= 10;
        _denominator *= 10;

    }

    _numerator = static_cast<int>(n);
    _Simplify();

}

Fraction::Fraction(double n, double d) {

    assert(d != 0 && "Can't create fraction with a denominator null");

    while (n != static_cast<int>(n) || d != static_cast<int>(d)) {

        n *= 10;
        d *= 10;

    }

    _numerator = static_cast<int>(n);
    _denominator = static_cast<int>(d);

    _Simplify();

}

bool Fraction::Integer() const { return _denominator == 1; }

double Fraction::Value() const { return _numerator/_denominator; }

int Fraction::GetNumerator() const { return _numerator; }

void Fraction::SetNumerator(int n) {

    _numerator = n;
    _Simplify();

}

unsigned int Fraction::GetDenominator() const { return _denominator; }

void Fraction::SetDenominator(unsigned int d) {

    assert(d != 0 && "Can't set denominator null");
    _denominator = d;
    _Simplify();

}

Fraction Inverse(const Fraction &f) {
    
    if (f._numerator < 0) {

        return Fraction{-static_cast<int>(f._denominator), static_cast<unsigned int>(-f._numerator)};

    } else {

        return Fraction{static_cast<int>(f._denominator), static_cast<unsigned int>(f._numerator)};

    }

}

Fraction Floor(const Fraction &f) { return Fraction{f._numerator-f._numerator%static_cast<int>(f._denominator), f._denominator}; }
Fraction Ceil(const Fraction &f) { return Floor(f)++; }

Fraction Fraction::operator+() const { return *this; }
Fraction Fraction::operator-() { return Fraction{-_numerator, _denominator}; }

Fraction& Fraction::operator++() {

    _numerator += _denominator;
    return *this;

}

Fraction& Fraction::operator++(int) { return ++(*this); }

Fraction& Fraction::operator--() {

    _numerator -= _denominator;
    return *this;

}

Fraction& Fraction::operator--(int) { return --(*this); }

Fraction operator+(const Fraction &l, const Fraction &r) { return Fraction{l._numerator*static_cast<int>(r._denominator)+r._numerator*static_cast<int>(l._denominator), l._denominator*r._denominator}; }
Fraction operator-(const Fraction &l, const Fraction &r) { return Fraction{l._numerator*static_cast<int>(r._denominator)-r._numerator*static_cast<int>(l._denominator), l._denominator*r._denominator}; }
Fraction operator*(const Fraction &l, const Fraction &r) { return Fraction{l._numerator*static_cast<int>(r._numerator), l._denominator*r._denominator}; }
Fraction operator/(const Fraction &l, const Fraction &r) { return l*Inverse(r); }
Fraction operator%(const Fraction &l, const Fraction &r) { return l-Floor(l/r)*r; }

Fraction& Fraction::operator+=(const Fraction &f) { return *this = *this+f; }
Fraction& Fraction::operator-=(const Fraction &f) { return *this = *this-f; }
Fraction& Fraction::operator*=(const Fraction &f) { return *this = *this*f; }
Fraction& Fraction::operator/=(const Fraction &f) { return *this = *this/f; }
Fraction& Fraction::operator%=(const Fraction &f) { return *this = *this%f; }

bool operator==(const Fraction &l, const Fraction &r) { return l._numerator == r._numerator && l._denominator == r._denominator; }
bool operator!=(const Fraction &l, const Fraction &r) { return !(l == r); }

bool operator<(const Fraction &l, const Fraction &r) { return l._numerator*r._denominator < r._numerator*l._denominator; }
bool operator<=(const Fraction &l, const Fraction &r) { return (l == r || l < r); }

bool operator>(const Fraction &l, const Fraction &r) { return !(l <= r); }
bool operator>=(const Fraction &l, const Fraction &r) { return !(l < r); }

std::ostream& operator<<(std::ostream &flux, const Fraction &f) {

    if (f.Integer()) {

        flux << f._numerator;

    } else {

        flux << static_cast<std::string>(f);

    }

    return flux;

}

Fraction::operator std::string() const { return std::to_string(_numerator)+"/"+std::to_string(_denominator); }

void Fraction::_Simplify() {

    unsigned int d{_denominator}, pgcd{static_cast<unsigned int>(_numerator)};

    while (d != 0) {

        unsigned int buffer{d};
        d = pgcd%d;
        pgcd = buffer;

    }

    _numerator /= pgcd;
    _denominator /= pgcd;

}