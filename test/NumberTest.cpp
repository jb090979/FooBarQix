//////////////////////////////////////////////////////////////////////
/// @file  NumberTest.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>
#include <number/Number.hpp>


namespace number {


TEST(NumberTest, test_isDivisibleWithoutRemainder_IsDivisibleByX_GetTrue)
{
   Number testobject(112);

   bool actual = testobject.isDivisibleWithoutRemainder(2);

   bool expected = true;
   EXPECT_EQ(actual, expected);
}

TEST(NumberTest, test_isDivisibleWithoutRemainder_IsNotDivisibleByX_GetFalse)
{
   Number testobject(111);

   bool actual = testobject.isDivisibleWithoutRemainder(2);

   bool expected = false;
   EXPECT_EQ(actual, expected);
}

TEST(NumberTest, test_isDivisibleWithoutRemainder_DivisionBy0_GetFalse)
{
   Number testobject(111);
   EXPECT_EQ(testobject.isDivisibleWithoutRemainder(0), false);
}

TEST(NumberTest, test_splitDigits_splitNumber_GetDigigtList)
{
   Number testobject(987654321);

   data::digitList_t list = testobject.splitDigits();

   uint8_t expected = 1;
   for (auto& actual : list)   //[0] => ones digit, [1] => tens digit ...
   {
      EXPECT_EQ(actual, expected);
      expected++;
   }
}

TEST(NumberTest, test_AssignOperator_SplitNewNumber_GetDigitList)
{
   Number testobject(123456789);

   testobject             = 987654321;
   data::digitList_t list = testobject.splitDigits();

   uint8_t expected = 1;
   for (auto& actual : list)   //[0] => ones digit, [1] => tens digit ...
   {
      EXPECT_EQ(actual, expected);
      expected++;
   }
}

TEST(NumberTest, test_operatorPlus_CornerCaseUINT32_Overflow)
{
   Number testobject = 1;

   EXPECT_THROW(testobject + UINT32_MAX, std::overflow_error);
}

TEST(NumberTest, test_operatorPlus_CornerCaseNUMBER_Overflow)
{
   Number testobject = 1;
   Number addend     = UINT32_MAX;
   EXPECT_THROW(testobject + addend, std::overflow_error);
}

TEST(NumberTest, test_operatorPlus_AddX_NoOverflow)
{
   Number testobject(Number(1));

   uint32_t actual = testobject + UINT32_C(1);

   uint32_t expected = 2;
   EXPECT_EQ(actual, expected);
}

TEST(NumberTest, test_operatorPlus_Add0_NoOverflow)
{
   const uint32_t testNumber = UINT32_C(1);
   Number         testobject(testNumber);
   Number         addend(0);

   uint32_t actual = testobject + addend;

   uint32_t expected = UINT32_C(1);
   EXPECT_EQ(actual, expected);
}

TEST(NumberTest, test_additonalConstrutors)
{
   Number testobject(3);
   Number addend;   // 0 is default init value

   addend          = testobject;
   uint32_t actual = testobject + addend;

   uint32_t expected = UINT32_C(6);
   EXPECT_EQ(actual, expected);
}


}   // namespace number
