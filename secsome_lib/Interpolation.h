#pragma once

#include <SMath.h>

namespace secsome::interpolation
{
    float Linear(const float a, const float b, float t)
    {
        return a * t + (1 - t) * b;
    }

    float Cosine(const float a, const float b, float t)
    {
        float ft = t * std::numbers::pi;
        t = (1 - cos(ft)) * 0.5;
        return Linear(a, b, t);
    }

    float Cubic(float v0, float v1, float v2, float v3, float t)
    {
        return v0 + 0.5 * t * (v2 - v0 + t * (2.0 * v0 - 5.0 * v1 + 4.0 * v2 - v3 + t * (3.0 * (v1 - v2) + v3 - v0)));
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="v0"> left </param>
    /// <param name="m0"> left vec </param>
    /// <param name="v1"> right </param>
    /// <param name="m1"> right vec </param>
    /// <param name="t"> where </param>
    /// <returns></returns>
    float Hermite(float v0, float m0, float v1, float m1, float t)
    {
        return v0 + t * (m0 + t * (-3 * v0 - 2 * m0 - m1 + 3 * v1 + t * (2 * v0 + m0 + m1 - 2 * v1)));
    }
}