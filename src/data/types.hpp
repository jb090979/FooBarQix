//////////////////////////////////////////////////////////////////////
/// @file  types.hpp
/// @author jb090979@web.de
/// Copyright (c) 2022 by Jens Baumann
/// License:  Give me chocolate and you can use the code :-)
//////////////////////////////////////////////////////////////////////

#ifndef DATA_TYPES_HPP
#define DATA_TYPES_HPP

#include <stdint.h>
#include <vector>

namespace data {

typedef uint8_t              digit_t;   ///< one digit 0...9
typedef std::vector<digit_t> digitList_t;

}   // namespace data

#endif
