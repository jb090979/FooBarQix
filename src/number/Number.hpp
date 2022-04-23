//////////////////////////////////////////////////////////////////////
/// @file  Number.hpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#ifndef NUMBER_NUMBER_HPP
#define NUMBER_NUMBER_HPP

#include <stdint.h>
#include <interface/INumber.hpp>

namespace number {

/**
 * @brief The Number class represent integer data type uint32_t not as a primitive type but as an high level type like std::string or
 std::stream.

          For this unit test example this class is kept simple and implementation is very incomplete. You will miss a lot of necessary
 functions.

 */
class Number : public interface::INumber
{
   public:
   Number(uint32_t number);
   Number();
   Number(Number const& _number);
   Number& operator=(Number const& _number);

   virtual bool              isDivisibleWithoutRemainder(uint32_t divisor) override;
   virtual data::digitList_t splitDigits() override;

   virtual interface::INumber& operator=(uint32_t other_);


   /**
      @brief operator +

         The operator sum the stored number with the given addend.

      @attention In case the summation overflows the std::overflow_error exception is thrown

      @param addend
      @return result
    */
   virtual Number operator+(const Number& addend);
   virtual Number operator+(const uint32_t& addend);

   operator uint32_t() const;

   virtual ~Number();

   private:
   uint32_t m_Number;
};

}   // namespace number

#endif
