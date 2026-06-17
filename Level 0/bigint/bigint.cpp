#include "bigint.hpp"

bigint::bigint() : _value("0") {}

bigint::bigint(unsigned int num)
{
   std::stringstream ss;
   ss << num;
   _value = ss.str();
}
bigint::bigint(const bigint &other)
{
    _value = other._value;
}

bigint &bigint::operator=(const bigint &other)
{
   if(*this != other)
      _value = other._value;
   return *this;
}

bigint::~bigint(){}

const std::string &bigint::get_value() const
{
   return _value;
}

bigint bigint::operator+(const bigint &other) const
{
   bigint result;
   result._value.clear();
   int i = _value.size() - 1;
   int j = other._value.size() - 1;
   int carry = 0;
   while (i >= 0 || j >= 0 || carry)
   {
      int sum = carry;
      if (i >= 0)
         sum += _value[i--] - '0';
      if (j >= 0)
         sum += other._value[j--] - '0';
      
      result._value.insert(result._value.begin(), (sum % 10) + '0');
      carry = sum/10;
   }
   return result;
}

bigint &bigint::operator+=(const bigint &other)
{
   *this = *this + other;
   return *this;
}

bigint &bigint::operator++()
{
   *this = *this + bigint(1);
   return *this;
}

bigint bigint::operator++(int)
{
   bigint tmp(*this);
   ++(*this);
   return(tmp);
}

bigint bigint::operator<<(unsigned int n) const //add zeros at the end
{
   if (_value == "0")
      return bigint(0);
   bigint temp(*this);
   temp._value.append(n, '0');
   return temp;
}
bigint &bigint::operator<<=(unsigned int n)
{
   *this = *this << n;
   return *this;
}
bigint bigint::operator>>(unsigned int n) const //remove digits from the end
{
   if (n >= _value.size())
      return bigint(0);
   bigint temp(*this);
   temp._value.erase(temp._value.size()-n, n);
   return temp;
}
bigint &bigint::operator>>=(unsigned int n)
{
   *this = *this >> n;
   return *this;
}

static unsigned int to_unsigned(std::string str)
{
   std::stringstream ss(str);
   unsigned int res;

   ss >> res;
   return res;
}
bigint bigint::operator<<(const bigint &other) const
{
   return (*this << to_unsigned(other._value));
}
bigint &bigint::operator<<=(const bigint &other)
{
   *this = *this << other;
   return *this;
}
bigint bigint::operator>>(const bigint &other) const
{
   return (*this >> to_unsigned(other._value));
}
bigint &bigint::operator>>=(const bigint &other)
{
   *this = *this >> other;
   return *this;
}


bool bigint::operator==(const bigint &other) const
{
   return (_value == other._value);
}
bool bigint::operator!=(const bigint &other) const
{
   return (!(_value == other._value));
}
bool bigint::operator>(const bigint &other) const
{
   if (_value.size() != other._value.size())
      return (_value.size() > other._value.size());
   return (_value > other._value);
}
bool bigint::operator>=(const bigint &other) const
{
   return (*this > other || *this == other);
}
bool bigint::operator<(const bigint &other) const
{
   if (_value.size() != other._value.size())
      return (_value.size() < other._value.size());   
   return (_value < other._value);
}
bool bigint::operator<=(const bigint &other) const
{
   return (*this < other || *this == other);
}


std::ostream &operator<<(std::ostream &os, const bigint &num)
{
   os << num.get_value();
   return os;
}