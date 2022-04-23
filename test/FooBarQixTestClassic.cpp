//////////////////////////////////////////////////////////////////////
/// @file  FooBarQixTestClassic.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////


#include <gtest/gtest.h>
#include <number/Number.hpp>

// include class under test
#include <foobarqix/FooBarQix.hpp>

namespace foobarqix {

/**
  @brief test number which could be divided by X and contain digit X once

  @attention This routine also shows how to return constant return values with goolge mock

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTestClassic, test_compute_NumberDivisibleByXWithX_GetXX)
{
   number::Number       foo(UINT32_C(945));
   foobarqix::FooBarQix testObject(foo);


   std::string actual = testObject.compute();

   std::string expected = "FooBarQixBar";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could be divided by 5 and contains digit X multiple times

  @attention This routine also shows how to return different return values based on function paramter with google mock.

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTestClassic, test_compute_NumberDivisibleBy5WithMultipleX_GetFooXXX)
{
   number::Number       foo(UINT32_C(858355));
   foobarqix::FooBarQix testObject(foo);

   std::string actual = testObject.compute();

   std::string expected = "BarBarFooBarBar";
   EXPECT_EQ(actual, expected);
}

/**
  @brief test number which could not be divided by X and do not contain digit X

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTestClassic, test_compute_NumberNotDivisibleByXWithoutX_GetNumber)
{
   number::Number       foo(UINT32_C(8422));
   foobarqix::FooBarQix testObject(foo);


   std::string actual = testObject.compute();

   std::string expected = "8422";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could not be divided by X and contain digit X once

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTestClassic, test_compute_NumberNotDivisibleByXWithX_GetX)
{
   number::Number       foo(UINT32_C(13));
   foobarqix::FooBarQix testObject(foo);

   std::string actual = testObject.compute();

   std::string expected = "Foo";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could not be divided by X and contain digit X two times

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTestClassic, test_compute_NumberNotDivisibleByXWithMultipleX_GetXX)
{
   number::Number       foo(UINT32_C(7531));
   foobarqix::FooBarQix testObject(foo);

   std::string actual = testObject.compute();

   std::string expected = "QixBarFoo";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could be divided by X and contain digit 0

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTestClassic, test_compute_NumberDivisibleByXWithZeros_GetXWithAtserisk)
{
   number::Number       foo(UINT32_C(7350));
   foobarqix::FooBarQix testObject(foo);

   std::string actual = testObject.compute();

   std::string expected = "FooBarQixQixFooBar*";
   EXPECT_EQ(actual, expected);
}


/**
  @brief test number which could not be divided by X and contain digit 0

         X is 3 (Foo), 5 (Bar) and 7 (Qix)
 */
TEST(FooBarQixTestClassic, test_compute_NumberNotDivisibleByXWithZeros_GetNumberWithAtserisk)
{
   number::Number       foo(UINT32_C(8021));
   foobarqix::FooBarQix testObject(foo);

   std::string actual = testObject.compute();

   std::string expected = "8*21";
   EXPECT_EQ(actual, expected);
}

/**
  @brief test number which could be divided by X and do not contain digit X

         X is 3 (Foo), 5 (Bar) and 7 (Qix)

  @attention This routine also shows how to invoke an free function call with goolge mock


  @attention: Compare this test with Mockist approach. There is no number
              which is divisible by 3,5,7 and do not contain 3,5,7,0.
 */
TEST(FooBarQixTestClassic, test_compute_NumberDivisibleByXWithoutX_GetX)
{
   number::Number       foo(UINT32_C(210));
   foobarqix::FooBarQix testObject(foo);

   std::string actual = testObject.compute();

   std::string expected = "FooBarQix*";
   EXPECT_EQ(actual, expected);
}

}   // namespace foobarqix
