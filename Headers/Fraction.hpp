#ifndef DEF_FRACTION_HPP
#define DEF_FRACTION_HPP

#include <iosfwd>
#include <string>

class Fraction {

    public:

    Fraction();

    Fraction(int);
    Fraction(int, unsigned int);

    Fraction(double);
    Fraction(double, double);

    ~Fraction() = default;

    Fraction(const Fraction&) = default;
    Fraction(Fraction&&) = default;

    bool Integer() const;
    double Value() const;

    int GetNumerator() const;
    void SetNumerator(int);

    unsigned int GetDenominator() const;
    void SetDenominator(unsigned int);

    friend Fraction Inverse(const Fraction&);
    friend Fraction Floor(const Fraction&);
    friend Fraction Ceil(const Fraction&);

    Fraction operator+() const;
    Fraction operator-();

    Fraction& operator++();
    Fraction& operator++(int);

    Fraction& operator--();
    Fraction& operator--(int);

    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);
    friend Fraction operator%(const Fraction&, const Fraction&);

    Fraction& operator+=(const Fraction&);
    Fraction& operator-=(const Fraction&);
    Fraction& operator*=(const Fraction&);
    Fraction& operator/=(const Fraction&);
    Fraction& operator%=(const Fraction&);

    friend bool operator==(const Fraction&, const Fraction&);
    friend bool operator!=(const Fraction&, const Fraction&);

    friend bool operator<(const Fraction&, const Fraction&);
    friend bool operator<=(const Fraction&, const Fraction&);

    friend bool operator>(const Fraction&, const Fraction&);
    friend bool operator>=(const Fraction&, const Fraction&);

    Fraction& operator=(const Fraction&) = default;
    Fraction& operator=(Fraction&&) = default;

    friend std::ostream& operator<<(std::ostream&, const Fraction&);

    operator std::string() const;

    private:

    void _Simplify();

    int _numerator;
    unsigned int _denominator;

};

#endif // DEF_FRACTION_HPP