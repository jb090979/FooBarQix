//////////////////////////////////////////////////////////////////////
/// @file  mainTest.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include <sstream>
#include <iostream>
#include <gtest/gtest.h>

void realMain(void);

TEST(MainTest, test_realMain_ProcessAll_GetWholeString)
{
   // reconfigure output to catch cout
   std::ostringstream oss;
   std::streambuf*    p_cout_streambuf = std::cout.rdbuf();
   std::cout.rdbuf(oss.rdbuf());

   // get the output
   realMain();

   std::cout.rdbuf(p_cout_streambuf);   // restore

   std::stringstream expectedLines;
   expectedLines << "#####     Step1     #####\n"
                 << "         1 => 1\n"
                 << "         2 => 2\n"
                 << "         3 => FooFoo\n"
                 << "         4 => 4\n"
                 << "         5 => BarBar\n"
                 << "         6 => Foo\n"
                 << "         7 => QixQix\n"
                 << "         8 => 8\n"
                 << "         9 => Foo\n"
                 << "        10 => Bar*\n"
                 << "        13 => Foo\n"
                 << "        15 => FooBarBar\n"
                 << "        21 => FooQix\n"
                 << "        33 => FooFooFoo\n"
                 << "        51 => FooBar\n"
                 << "        53 => BarFoo\n"
                 << "\n#####     Step2     #####\n"
                 << "       101 => 1*1\n"
                 << "       303 => FooFoo*Foo\n"
                 << "       105 => FooBarQix*Bar\n"
                 << "     10101 => FooQix**\n";

   // test your oss content...
   EXPECT_TRUE(oss);
   EXPECT_EQ(oss.str(), expectedLines.str());
}
