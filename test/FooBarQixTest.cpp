//////////////////////////////////////////////////////////////////////
/// @file  FooBarQixTest.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>
#include "INumberMock.hpp"

// include class under test
#include <foobarqix/FooBarQix.hpp>

namespace gt = ::testing;
using ::testing::_;

namespace foobarqix {


bool isDivisibleWithoutRemainderTrue(uint32_t /*divisor*/)
{
   return true;
}

bool isDivisibleWithoutRemainderFalse(uint32_t /*divisor*/)
{
   return false;
}

data::digitList_t splitDigitsWithout3570()
{
   data::digitList_t list = { 1, 2, 4, 8 };
   return list;
}


/**
  @brief test number which could be divided by X and contain digit X once

  @attention This routine also shows how to return constant return values with goolge mock

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTest, test_compute_NumberDivisibleByXWithX_GetXX)
{
   interface::INumberMock mock;
   foobarqix::FooBarQix   testObject(mock);
   data::digitList_t      list = { 1, 2, 4, 8, 5 };
   EXPECT_CALL(mock, isDivisibleWithoutRemainder(_)).WillRepeatedly(gt::Return(true));
   EXPECT_CALL(mock, splitDigits()).WillRepeatedly(gt::Return(list));

   std::string actual = testObject.compute();

   std::string expected = "FooBarQixBar";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could be divided by 5 and contains digit X multiple times

  @attention This routine also shows how to return different return values based on function paramter with google mock.

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTest, test_compute_NumberDivisibleBy5WithMultipleX_GetFooXXX)
{
   interface::INumberMock mock;
   foobarqix::FooBarQix   testObject(mock);
   data::digitList_t      list = { 5, 5, 3, 8, 5, 8 };

   // the order of EXPECT_CALL is important. The last EXPECT_CALL will be evaluated first.
   EXPECT_CALL(mock, isDivisibleWithoutRemainder(_)).WillRepeatedly(gt::Return(false));
   EXPECT_CALL(mock, isDivisibleWithoutRemainder(5)).WillRepeatedly(gt::Return(true));
   EXPECT_CALL(mock, splitDigits()).WillRepeatedly(gt::Return(list));

   std::string actual = testObject.compute();

   std::string expected = "BarBarFooBarBar";
   EXPECT_EQ(actual, expected);
}

/**
  @brief test number which could not be divided by X and do not contain digit X

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTest, test_compute_NumberNotDivisibleByXWithoutX_GetNumber)
{
   interface::INumberMock mock;
   foobarqix::FooBarQix   testObject(mock);

   data::digitList_t list = { 2, 2, 4, 8 };
   EXPECT_CALL(mock, isDivisibleWithoutRemainder(_)).WillRepeatedly(gt::Return(false));
   EXPECT_CALL(mock, splitDigits()).WillRepeatedly(gt::Return(list));

   std::string actual = testObject.compute();

   std::string expected = "8422";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could not be divided by X and contain digit X once

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTest, test_compute_NumberNotDivisibleByXWithX_GetX)
{
   interface::INumberMock mock;
   foobarqix::FooBarQix   testObject(mock);

   data::digitList_t list = { 3, 1 };
   EXPECT_CALL(mock, isDivisibleWithoutRemainder(_)).WillRepeatedly(gt::Return(false));
   EXPECT_CALL(mock, splitDigits()).WillRepeatedly(gt::Return(list));

   std::string actual = testObject.compute();

   std::string expected = "Foo";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could not be divided by X and contain digit X two times

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTest, test_compute_NumberNotDivisibleByXWithMultipleX_GetXX)
{
   interface::INumberMock mock;
   foobarqix::FooBarQix   testObject(mock);

   data::digitList_t list = { 1, 2, 4, 8, 3, 5, 7 };
   EXPECT_CALL(mock, isDivisibleWithoutRemainder(_)).WillRepeatedly(gt::Return(false));
   EXPECT_CALL(mock, splitDigits()).WillRepeatedly(gt::Return(list));

   std::string actual = testObject.compute();

   std::string expected = "QixBarFoo";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could be divided by X and contain digit 0

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTest, test_compute_NumberDivisibleByXWithZeros_GetXWithAtserisk)
{
   interface::INumberMock mock;
   foobarqix::FooBarQix   testObject(mock);

   data::digitList_t list = { 1, 2, 0, 8, 5, 3, 7 };
   EXPECT_CALL(mock, isDivisibleWithoutRemainder(_)).WillRepeatedly(gt::Return(true));
   EXPECT_CALL(mock, splitDigits()).WillRepeatedly(gt::Return(list));

   std::string actual = testObject.compute();

   std::string expected = "FooBarQixQixFooBar*";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could not be divided by X and contain digit 0

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTest, test_compute_NumberNotDivisibleByXWithZeros_GetNumberWithAtserisk)
{
   interface::INumberMock mock;
   foobarqix::FooBarQix   testObject(mock);

   data::digitList_t list = { 1, 2, 0, 8 };
   EXPECT_CALL(mock, isDivisibleWithoutRemainder(_)).WillRepeatedly(gt::Return(false));
   EXPECT_CALL(mock, splitDigits()).WillRepeatedly(gt::Return(list));

   std::string actual = testObject.compute();

   std::string expected = "8*21";
   EXPECT_EQ(actual, expected);
}

/**
  @brief test number which could be divided by X and do not contain digit X

         X is 3 (Foo), 5 (Bar) and 7 (Qix)

  @attention This routine also shows how to invoke an free function call with goolge mock


  @attention: This test makes no sense. We create a number which is divisible by 3, 5 and 7 but do not contain
              3, 5, 7, or 0. A number divisible by 5 always ends with 0 or 5.

              This test should demonstrate that a mock do not use real values. The devoloper
              configures the attributes of a number independently of each other. So make sure
              to test only real use cases.

              Therefore in a classic test approach we use 210 as number but it contains a 0. Therefore the result
              of the classic approach is FooBarQix*
 */
TEST(FooBarQixTest, test_compute_NumberDivisibleByXWithoutX_GetX)
{
   interface::INumberMock mock;
   foobarqix::FooBarQix   testObject(mock);
   EXPECT_CALL(mock, isDivisibleWithoutRemainder(_)).WillRepeatedly(gt::Invoke(isDivisibleWithoutRemainderTrue));
   EXPECT_CALL(mock, splitDigits()).WillRepeatedly(gt::Invoke(splitDigitsWithout3570));


   std::string actual = testObject.compute();

   std::string expected = "FooBarQix";
   EXPECT_EQ(actual, expected);
}

}   // namespace foobarqix
