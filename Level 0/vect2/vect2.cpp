/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:45:13 by marvin            #+#    #+#             */
/*   Updated: 2026/05/12 19:45:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}

vect2::vect2(int x, int y)
{
   _x = x;
   _y = y;
}

vect2::vect2(const vect2 &other)
{
   _x = other._x;
   _y = other._y;
}

vect2 &vect2::operator=(const vect2 &other)
{
   if (this != &other)
   {
      _x = other._x;
      _y = other._y;
   }
   return *this;
}

vect2::~vect2() {}

const int &vect2::operator[](int index) const
{
   if (index == 0)
      return _x;
   return _y;
}

int &vect2::operator[](int index)
{
   if (index == 0)
      return _x;
   return _y;
}

vect2 &vect2::operator++()
{
   ++_x;
   ++_y;
   return *this;
}

vect2 vect2::operator++(int)
{
   vect2 temp(*this);
   ++_x;
   ++_y;
   return temp;
}

vect2 &vect2::operator--()
{
   --_x;
   --_y;
   return *this;
}

vect2 vect2::operator--(int)
{
   vect2 temp(*this);
   --_x;
   --_y;
   return temp;
}

bool vect2::operator==(const vect2 &other) const
{
   if (_x == other._x && _y == other._y)
      return true;
   return false;
}

bool vect2::operator!=(const vect2 &other) const
{
   if (_x != other._x || _y != other._y)
      return true;
   return false;
}

vect2 vect2::operator+(const vect2 &other) const
{
   vect2 res;
   res._x = _x + other._x;
   res._y = _y + other._y;
   return (res);
}

vect2 vect2::operator-(const vect2 &other) const
{
   vect2 res;
   res._x = _x - other._x;
   res._y = _y - other._y;
   return (res);
}

vect2 vect2::operator*(int scalar) const
{
   vect2 res;
   res._x = _x * scalar;
   res._y = _y * scalar;
   return (res);
}

vect2 vect2::operator-() const
{
   vect2 res;
   res._x = -_x;
   res._y = -_y;
   return (res);
}

vect2& vect2::operator+=(const vect2 &other)
{
   _x += other._x;
   _y += other._y;
   return *this;
}

vect2& vect2::operator-=(const vect2 &other)
{
   _x -= other._x;
   _y -= other._y;
   return *this;
}

vect2& vect2::operator*=(int scalar)
{
   _x *= scalar;
   _y *= scalar;
   return *this;
}

vect2 operator*(int scalar, const vect2 &v)
{
   return vect2(v[0] * scalar, v[1] * scalar);
}

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
   os << "{" << v[0] << ", " << v[1] << "}";
   return os;
}
