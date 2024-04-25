#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>
#include <sstream>
#include <iosfwd>
#include <algorithm>
struct Complex {
	[[nodiscard]] Complex() = default;
	[[nodiscard]] explicit Complex(const double real);
	~Complex() = default;
	[[nodiscard]] Complex(const double real, const double imaginary);
	[[nodiscard]] Complex(const Complex& copy);
	[[nodiscard]] Complex(Complex&& copy) noexcept;
	Complex operator-() noexcept;
	Complex& operator=(const Complex& copy);
	Complex& operator=(Complex&& copy) noexcept;
	bool operator==(const Complex& rhs) const ;
	bool operator!=(const Complex& rhs) const;
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); }
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }
	[[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
	[[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept;
	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };

};
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.ReadFrom(istrm);
}
[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator+(const Complex& lhs, const double& rhs);
[[nodiscard]] Complex operator-(const Complex& lhs, const double& rhs);
[[nodiscard]] Complex operator/(const Complex& lhs, const double& rhs);
[[nodiscard]] Complex operator*(const Complex& lhs, const double& rhs);
[[nodiscard]] Complex operator+(const double& lhs, const Complex& rhs);
[[nodiscard]] Complex operator-(const double& lhs, const Complex& rhs);
[[nodiscard]] Complex operator/(const double& lhs, const Complex& rhs);
[[nodiscard]] Complex operator*(const double& lhs, const Complex& rhs);





#endif



















