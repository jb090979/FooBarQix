////////////////////////////////////////////////////////////////////
/// @file  FooBarQix.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include <foobarqix/FooBarQix.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

namespace foobarqix {

FooBarQix::FooBarQix(interface::INumber& number) : m_Number(number)
{
}

FooBarQix::~FooBarQix()
{
}

std::string FooBarQix::compute()
{
   std::string output      = "";
   bool        printNumber = true;
   if (m_Number.isDivisibleWithoutRemainder(3))
   {
      output += "Foo";
      printNumber = false;
   }
   if (m_Number.isDivisibleWithoutRemainder(5))
   {
      output += "Bar";
      printNumber = false;
   }

   if (m_Number.isDivisibleWithoutRemainder(7))
   {
      output += "Qix";
      printNumber = false;
   }

   data::digitList_t list = m_Number.splitDigits();
   std::reverse(std::begin(list), std::end(list));

   for (auto& i : list)
   {
      switch (i)
      {
         case 0:
            output += "*";
            break;
         case 3:
            output += "Foo";
            printNumber = false;
            break;
         case 5:
            output += "Bar";
            printNumber = false;
            break;
         case 7:
            output += "Qix";
            printNumber = false;
            break;
         default:
            break;
      }
   }

   if (printNumber)
   {
      output = "";   // delete possible character -> just the number
      for (auto& i : list)
      {
         if (i != 0)
         {
            output += std::to_string(i);
         }
         else
         {
            output += "*";
         }
      }
   }
   return output;
}

}   // namespace foobarqix
