#pragma once

#include <cmath>

namespace secsome::smath
{
    template<typename T>
    T abs(T&& v)
    {
        return v >= 0 ? v : -v;
    }
}