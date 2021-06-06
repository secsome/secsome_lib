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

    template<typename T>
    T gcd(const T&& a, const T&& b)
    {
        if (a < b)
            std::swap(a, b);
        while (b > 0)
        {
            a %= b;
            std::swap(a, b);
        };
        return a;
    }
}