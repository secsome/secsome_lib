#pragma once

#include <algorithm>
#include <numbers>

namespace secsome::smath {

    template<typename T>
    T abs(const T&& v)
    {
        return v >= 0 ? v : -v;
    }

    template<typename T>
    T Rad2Deg(const T&& v)
    {
        return v / std::numbers::pi * 180;
    }

    template<typename T>
    T Deg2Rad(const T&& v)
    {
        return v * std::numbers::pi / 180;
    }
}