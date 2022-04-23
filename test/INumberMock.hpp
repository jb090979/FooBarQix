//////////////////////////////////////////////////////////////////////
/// @file  INumberMock.hpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////


#ifndef TEST_INUMBERMOCK_HPP
#define TEST_INUMBERMOCK_HPP

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <interface/INumber.hpp>

namespace interface {

class INumberMock : public INumber
{
   public:
   MOCK_METHOD1(isDivisibleWithoutRemainder, bool(uint32_t divisor));
   MOCK_METHOD0(splitDigits, data::digitList_t());
   MOCK_METHOD1(add, bool(uint32_t addend));
};

}   // namespace interface

#endif
