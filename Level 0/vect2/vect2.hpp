/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:13:42 by marvin            #+#    #+#             */
/*   Updated: 2026/05/12 18:13:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>

class vect2
{
   private:
      int   _x;
      int   _y;

   public:
      vect2();
      vect2(int x, int y);
      vect2(const vect2 &other);
      vect2 &operator=(const vect2 &other);
      ~vect2();

      const int &operator[](int index) const;
      int &operator[](int index);

      vect2 &operator++();
      vect2 operator++(int);
      vect2 &operator--();
      vect2 operator--(int);

      bool operator==(const vect2 &other) const;
      bool operator!=(const vect2 &other) const;

      vect2 operator+(const vect2 &other) const;
      vect2 operator-(const vect2 &other) const;
      vect2 operator*(int scalar) const;
      vect2 operator-() const;
      
      vect2 &operator+=(const vect2 &other);
      vect2 &operator-=(const vect2 &other);
      vect2 &operator*=(int scalar);
};

vect2 operator*(int scalar, const vect2 &v);
std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif