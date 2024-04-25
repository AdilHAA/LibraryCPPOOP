#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>
#include <sstream>
class Rational {
public:
    Rational() = default;
    Rational(const int64_t& num);
    Rational(const int64_t& num, const int64_t& den);
    Rational(const Rational& rhs);
    Rational(Rational&& copy) = default;
    ~Rational() = default;
    Rational& operator=(Rational&& copy) noexcept;
    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int64_t& num);
    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const int64_t& num);
    Rational& operator*=(const Rational& rhs);
    Rational& operator*=(const int64_t& num);
    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const int64_t& num);
    bool operator==(const Rational& rhs) { return ((rhs.num_ == num_) && (rhs.den_ == den_)); };
    bool operator!=(const Rational& rhs) { return !(operator==(rhs));};
    bool operator>(const Rational& rhs) { return ((num_ * rhs.den_) - (rhs.num_ * den_) > 0) && ((den_ * rhs.den_) > 0);};
    bool operator<(const Rational& rhs) { return ((num_ * rhs.den_) - (rhs.num_ * den_) < 0) && ((den_ * rhs.den_) < 0); };
    bool operator>=(const Rational& rhs) { return ((num_ * rhs.den_) - (rhs.num_ * den_) >= 0) && ((den_ * rhs.den_) >= 0); };
    bool operator<=(const Rational& rhs) { return ((num_ * rhs.den_) - (rhs.num_ * den_) <= 0) && ((den_ * rhs.den_) <= 0); };
    std::ostream& WriteTo(std::ostream& ostrm) const;
    std::istream& ReadFrom(std::istream& istrm);
private:
    int64_t num_ = 0;
    int64_t den_ = 1;
    int64_t Nod(const int64_t& x, const int64_t& y) {
        int64_t a = std::max(std::abs(x), std::abs(y));
        int64_t b = std::min(std::abs(x), std::abs(y));
        while (a != b) {
            a -= b;
            int64_t temp = a;
            a = std::max(temp, b);
            b = std::min(temp, b);
        }
        return b;
    }
    void Standart() {
        int64_t ans = Nod(std::abs(num_), std::abs(den_));
        if (den_ < 0) {
            num_ *= (-1);
            den_ *= (-1);
        }
        num_ /= ans;
        den_ /= ans;
    }
    static const char sign{'/'};
};

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
    return rhs.WriteTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
    return rhs.ReadFrom(istrm);
}

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, int64_t rhs);
Rational operator-(const Rational& lhs, int64_t rhs);
Rational operator/(const Rational& lhs, int64_t rhs);
Rational operator*(const Rational& lhs, int64_t rhs);
Rational operator+(int64_t rhs, const Rational& lhs);
Rational operator-(int64_t rhs, const Rational& lhs);
Rational operator/(int64_t rhs, const Rational& lhs);
Rational operator*(int64_t rhs, const Rational& lhs);
#endif;