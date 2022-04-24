//////////////////////////////////////////////////////////////////////
/// @file  INumber.hpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#ifndef INTERFACE_INUMBER_HPP
#define INTERFACE_INUMBER_HPP

#include <stdint.h>
#include <data/types.hpp>


namespace interface {

class INumber
{
   public:
   /**
     @brief determine devision is without remainder
     @param[in] divisor
     @return true if devision is without remainder, else false
             0 will return false.
    */
   virtual bool isDivisibleWithoutRemainder(uint32_t divisor) = 0;

   /**
     @brief split the number into a list of digits in ascending order
     [0] == ones digit
     [1] == tens digit
     ...

     @return list

    */
   virtual data::digitList_t splitDigits() = 0;


   virtual ~INumber()
   {
   }
};


}   // namespace interface
#endif
