//////////////////////////////////////////////////////////////////////
/// @file  FooBarQix.hpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#ifndef FOOBARQIX_FOOBARQIX_HPP
#define FOOBARQIX_FOOBARQIX_HPP

#include <interface/INumber.hpp>
#include <string>


namespace foobarqix {


class FooBarQix
{
   public:
   FooBarQix(interface::INumber& number);
   FooBarQix() = delete;

   ~FooBarQix();


   /**
      @brief compute the output based on the foobarqix rules
      @return
     */
   std::string compute();

   private:
   interface::INumber& m_Number;
};

}   // namespace foobarqix


#endif
