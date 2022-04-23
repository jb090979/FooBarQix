//////////////////////////////////////////////////////////////////////
/// @file  Number.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include <number/Number.hpp>
#include <string>
#include <stdexcept>

namespace number {


Number::Number(uint32_t number) : m_Number(number)
{
}

Number::Number() : m_Number(UINT32_C(0))
{
}

Number::Number(const Number& _number) : m_Number(_number)
{
}

Number& Number::operator=(const Number& _number)
{
   m_Number = _number;
   return *this;
}

bool Number::isDivisibleWithoutRemainder(uint32_t divisor)
{
   bool ret = false;
   if (divisor != 0)
   {
      ret = (m_Number % divisor == UINT32_C(0)) ? true : false;
   }
   return ret;
}

data::digitList_t Number::splitDigits()
{
   data::digitList_t list;

   uint32_t tmpNumber = m_Number;
   do
   {
      data::digit_t onceDigit = static_cast<data::digit_t>(tmpNumber % 10UL);
      list.push_back(onceDigit);

      // shift to right by one digit
      tmpNumber = tmpNumber / 10UL;
   } while (tmpNumber > 0);

   return list;
}


interface::INumber& Number::operator=(uint32_t other_)
{
   m_Number = other_;
   return *this;
}

Number Number::operator+(const Number& addend)
{
   uint32_t tmp = m_Number;

   tmp += addend.m_Number;

   if (tmp >= m_Number)
   {
      m_Number = tmp;
   }
   else
   {
      throw std::overflow_error("Addtition overflow occure!");
   }
   return *this;
}

Number Number::operator+(const uint32_t& addend)
{
   uint32_t tmp = m_Number;

   tmp += addend;

   if (tmp >= m_Number)
   {
      m_Number = tmp;
   }
   else
   {
      throw std::overflow_error("Addtition overflow occure!");
   }
   return *this;
}

Number::operator uint32_t() const
{
   return m_Number;
}

Number::~Number()
{
}

}   // namespace number
