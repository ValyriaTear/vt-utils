///////////////////////////////////////////////////////////////////////////////
//            Copyright (C) 2004-2011 by The Allacrost Project
//            Copyright (C) 2012-2016 by Bertram (Valyria Tear)
//                         All Rights Reserved
//
// This code is licensed under the GNU GPL version 2. It is free software
// and you may modify it and/or redistribute it under the terms of this license.
// See http://www.gnu.org/copyleft/gpl.html for details.
///////////////////////////////////////////////////////////////////////////////

/** ****************************************************************************
*** \file    utils.cpp
*** \author  Tyler Olsen, roots@allacrost.org
*** \author  Yohann Ferreira, yohann ferreira orange fr
*** \brief   Source file for the utility code.
*** ***************************************************************************/

#include "utils_numeric.h"

#include <cmath>

namespace vt_utils
{
float Lerp(float start, float end, float amount) {
    return start * (1.0f - amount) + end * amount;
}

uint32_t RoundUpPow2(uint32_t x)
{
    x -= 1;
    x |= x >>  1;
    x |= x >>  2;
    x |= x >>  4;
    x |= x >>  8;
    x |= x >> 16;
    return x + 1;
}

bool IsPowerOfTwo(uint32_t x)
{
    return ((x & (x - 1)) == 0);
}

bool IsOddNumber(uint32_t x)
{
    // NOTE: this happens to work for both little and big endian systems
    return (x & 0x00000001);
}

bool IsFloatInRange(float value, float lower, float upper)
{
    return (value >= lower && value <= upper);
}

bool IsFloatEqual(float value, float base, float delta)
{
    return (value >= (base - delta) && value <= (base + delta));
}

float GetFloatFraction(float value)
{
    return (value - GetFloatInteger(value));
}

float GetFloatInteger(float value)
{
    return static_cast<float>(static_cast<int>(value));
}

float FloorToFloatMultiple(const float value, const float multiple)
{
    return multiple * std::floor(value / multiple);
}

} // namespace utils
