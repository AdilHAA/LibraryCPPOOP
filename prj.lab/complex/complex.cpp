#include <iostream>
#include <sstream>
#include <complex/complex.hpp>

Complex::Complex(const double real){
	re = real;
	im = 0.0;

}

Complex::Complex(const double real, const double imaginary) {
	re = real;
	im = imaginary;

}

Complex::Complex(const Complex& copy) {
	re = copy.re;
	im = copy.im;
}
Complex::Complex(Complex&& copy) noexcept {
	std::swap(re, copy.re);
	std::swap(im, copy.im);
}

Complex& Complex::operator=(const Complex& copy) {
	re = copy.re;
	im = copy.im;
	return *this;
}

Complex& Complex::operator=(Complex&& copy) noexcept{
	std::swap(re, copy.re);
	std::swap(im, copy.im);
	return *this;
}
bool Complex::operator==(const Complex& rhs) const
{
	return (std::abs(re - rhs.re) < 2* std::numeric_limits<double>::epsilon() && (std::abs(im - rhs.im) < 2* std::numeric_limits<double>::epsilon()));
}
bool Complex::operator!=(const Complex& rhs) const
{
	return !operator==(rhs);
}


Complex Complex::operator-() noexcept { return Complex(-re, -im); }
Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}
Complex operator+(const Complex& lhs, const double& rhs)
{
	return Complex(lhs) += rhs;
}
Complex operator+(const double& lhs, const Complex& rhs)
{
	return Complex(lhs) += rhs;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs)-=rhs;
}
Complex operator-(const Complex& lhs, const double& rhs)
{
	return Complex(lhs) -= Complex(rhs);
}
Complex operator-(const double& lhs, const Complex& rhs)
{
	return Complex(lhs) -= rhs;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	double tempre = (rhs.re * re) - (im * rhs.im);
	double tempim = (rhs.im * re) + (im * rhs.re);
	re = tempre;
	im = tempim;
	return *this;
}
Complex operator*(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs) *= rhs;
}
Complex operator*(const Complex& lhs, const double& rhs)
{
	return Complex(lhs) *= rhs;
}
Complex operator*(const double& lhs, const Complex& rhs)
{
	return Complex(lhs) *= rhs;
}

Complex& Complex::operator/=(const Complex& rhs) {
	if ((pow(im, 2) + pow(rhs.im, 2)) == 0.0) {
		throw std::string("Zero in denum");
	}
	else {
		double tempre = re;
		re = ((re * rhs.re + im * rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2)));
		im = (((im * rhs.re) - (tempre * rhs.im)) / (pow(rhs.re, 2) + pow(rhs.im, 2)));
		return *this;
	}
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs) /= rhs;
}
Complex operator/(const Complex& lhs, const double& rhs)
{
	return Complex(lhs) /= rhs;
}
Complex operator/(const double& lhs, const Complex& rhs)
{
	return Complex(lhs) /= rhs;
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::ReadFrom(std::istream& istrm) noexcept
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;

		}
		else {
			istrm.setstate(std::ios_base::failbit);

		}

	}
	return istrm;
}












