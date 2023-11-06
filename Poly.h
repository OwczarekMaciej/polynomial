#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <map>

#pragma once

class Poly
{
    friend std::ostream &operator<<(std::ostream &os, const Poly &rhs);
    friend Poly operator+(const Poly &lhs, const Poly &rhs);
    friend Poly operator-(const Poly &lhs, const Poly &rhs);
    friend Poly operator*(const Poly &lhs, const Poly &rhs);
public:
    Poly(double value = 0);
    ~Poly() = default;
    double &operator[](int exp);

private:
    std::map<int, double> coefficients;
};

#endif