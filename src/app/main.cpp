//////////////////////////////////////////////////////////////////////
/// @file  main.cpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <foobarqix/FooBarQix.hpp>
#include <number/Number.hpp>

void printOutputFor(uint32_t _number)
{
   number::Number       number(_number);
   foobarqix::FooBarQix fooBarQix(number);

   // uint32_t max 10 digits
   std::cout << std::setw(10) << number << " => " << fooBarQix.compute() << "\n";
}

void realMain()
{
   std::cout << "#####     Step1     #####\n";
   printOutputFor(1);
   printOutputFor(2);
   printOutputFor(3);
   printOutputFor(4);
   printOutputFor(5);
   printOutputFor(6);
   printOutputFor(7);
   printOutputFor(8);
   printOutputFor(9);
   printOutputFor(10);
   printOutputFor(13);
   printOutputFor(15);
   printOutputFor(21);
   printOutputFor(33);
   printOutputFor(51);
   printOutputFor(53);
   std::cout << "\n#####     Step2     #####\n";
   printOutputFor(101);
   printOutputFor(303);
   printOutputFor(105);
   printOutputFor(10101);
}

#ifdef MAIN
int main(void)
{
   realMain();
   return 0;
}
#endif
