#include "Poly.h"
#include <iostream>
#include <map>

Poly::Poly(double value)
{
    coefficients[0] = value;
}

double &Poly::operator[](int exp)
{
    return coefficients[exp];
}

std::ostream &operator<<(std::ostream &os, const Poly &rhs)
{
    bool first_coef = true;

    for (auto it = rhs.coefficients.crbegin(); it != rhs.coefficients.crend(); it++)
    {
        if (it->second != 0.0)
        {
            if (!first_coef && it->second > 0)
            {
                os << " +";
            }
            if (it->second != 1)
            {
                os << " " << it->second;
            }
            if (it->first > 0)
            {
                os << "x";
                if (it->first > 1)
                {
                    os << "^" << it->first;
                }
            }
            first_coef = false;
        }
    }
    if (first_coef)
    {
        os << "0";
    }

    return os;
}

Poly operator+(const Poly &lhs, const Poly &rhs)
{
    Poly temp;
    for (auto it1 = lhs.coefficients.cbegin(), end_it1 = lhs.coefficients.cend(),
              it2 = rhs.coefficients.cbegin(), end_it2 = rhs.coefficients.cend();
         it1 != end_it1 || it2 != end_it2;)
    {
        if (it1 != end_it1)
        {
            temp[it1->first] += it1->second;
            it1++;
        }
        if (it2 != end_it2)
        {
            temp[it2->first] += it2->second;
            it2++;
        }
    }
    return temp;
}

Poly operator-(const Poly &lhs, const Poly &rhs)
{
    Poly temp;
    for (auto it1 = lhs.coefficients.cbegin(), end_it1 = lhs.coefficients.cend(),
              it2 = rhs.coefficients.cbegin(), end_it2 = rhs.coefficients.cend();
         it1 != end_it1 || it2 != end_it2;)
    {
        if (it1 != end_it1)
        {
            temp[it1->first] += it1->second;
            it1++;
        }
        if (it2 != end_it2)
        {
            temp[it2->first] -= it2->second;
            it2++;
        }
    }
    return temp;
}

Poly operator*(const Poly &lhs, const Poly &rhs)
{
    Poly temp;
    for (auto it1 = lhs.coefficients.cbegin(); it1 != lhs.coefficients.cend(); it1++)
    {
        for (auto it2 = rhs.coefficients.cbegin(); it2 != rhs.coefficients.cend(); it2++)
        {
            temp[it1->first + it2->second] += it1->first * it2->second;
        }
    }
    return temp;
}