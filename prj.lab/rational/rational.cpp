#include <rational/rational.hpp>
Rational::Rational(const int64_t& num) {
    num_ = num;
    den_ = 1;
}
Rational::Rational(const int64_t& num, const int64_t& den) {
    if (den > 0) {
        num_ = num / Nod(num, den);
        den_ = den / Nod(num, den);
    }
    if (den < 0) {
        num_ = -num / Nod(num, -den);
        den_ = -den / Nod(num , -den);
    }
    if (den == 0) {
        throw std::invalid_argument("Zero denumenator in ctor");
    }
}
Rational::Rational(const Rational& rhs) {
    num_ = rhs.num_ / Nod(rhs.num_, rhs.den_);
    den_ = rhs.den_ / Nod(rhs.num_, rhs.den_);
    Standart();
}

Rational& Rational::operator=(Rational&& copy) noexcept{
    std::swap(num_, copy.num_);
    std::swap(den_, copy.den_);
    return *this;
}

Rational& Rational::operator+=(const Rational& rhs) {
    num_ = num_ * rhs.den_ + den_ * rhs.num_;
    den_ = den_ * rhs.den_;
    Standart();
    return *this;
}
Rational& Rational::operator+=(const int64_t& num) {
    Rational rhs(num);
    num_ = num_ * rhs.den_ + den_ * rhs.num_;
    den_ = den_ * rhs.den_;
    Standart();
    return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
    num_ = num_ * rhs.den_ - den_ * rhs.num_;
    den_ = den_ * rhs.den_;
    Standart();
    return *this;
}
Rational& Rational::operator-=(const int64_t& num) {
    Rational rhs(num);
    num_ = num_ * rhs.den_ - den_ * rhs.num_;
    den_ = den_ * rhs.den_;
    Standart();
    return *this;
}
Rational& Rational::operator*=(const Rational& rhs){
    num_ = num_ * rhs.num_;
    den_ = den_ * rhs.den_;
    return *this;
}
Rational& Rational::operator*=(const int64_t& num) {
    Rational rhs(num);
    num_ = num_ * rhs.num_;
    den_ = den_ * rhs.den_;
    return *this;
}
Rational& Rational::operator/=(const Rational & rhs) {
    num_ = num_ * rhs.den_;
    den_ = den_ * rhs.num_;
    return *this;
}
Rational& Rational::operator/=(const int64_t& num) {
    Rational rhs(num);
    num_ = num_ * rhs.den_;
    den_ = den_ * rhs.num_;
    return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) += rhs;
};
Rational operator-(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs) -= rhs;
};
Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) *= rhs;
};
Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) /= rhs;
};
Rational operator+(const Rational& lhs, int64_t rhs) {
    return Rational(lhs) += rhs;
};
Rational operator+(int64_t rhs, const Rational& lhs) {
    return Rational(lhs) += rhs;
};
Rational operator*(const Rational& lhs, int64_t rhs) {
    return Rational(lhs) *= rhs;
};
Rational operator*(int64_t rhs, const Rational& lhs) {
    return Rational(lhs) *= rhs;
};
Rational operator/(const Rational& lhs, int64_t rhs) {
    return Rational(lhs) /= rhs;
};
Rational operator/(int64_t rhs, const Rational& lhs) {
    return Rational(lhs) /= rhs;
};
Rational operator-(const Rational& lhs, int64_t rhs)
{
    return Rational(lhs) -= rhs;
};
Rational operator-(int64_t rhs, const Rational& lhs)
{
    return Rational(lhs) -= Rational(rhs);
};
std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
    ostrm << num_ << sign << den_;
    return ostrm;
}
std::istream& Rational::ReadFrom(std::istream& istrm) {
    int64_t num;
    int64_t den;
    char sep(0);
    istrm >> num >> sep >> den;
    if (istrm.good()) {
        if (sep == sign && den != 0) {
            num_ = num;
            den_ = den;
        }
        else{
            istrm.std::ios_base::failbit;
        }
    }
    return istrm;
}