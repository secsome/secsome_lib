#pragma once

#include <SMath.h>
#include <Point.h>

namespace secsome::distances
{   
#pragma region Euclidean
    // std::true_type for sqrted value
    // std::false_type for un-sqrted value

    template <typename T, std::true_type>
    float Euclidean(const Point2D<T>& a, const Point2D<T>& b)
    {
        return
            sqrtf(
                (a.X - b.X) * (a.X - b.X) +
                (a.Y - b.Y) * (a.Y - b.Y)
            );
    }

    template <typename T, std::true_type>
    float Euclidean(const Point3D<T>& a, const Point3D<T>& b)
    {
        return
            sqrtf(
                (a.X - b.X) * (a.X - b.X) +
                (a.Y - b.Y) * (a.Y - b.Y) +
                (a.Z - b.Z) * (a.Z - b.Z)
            );
    }

    template <typename T, std::true_type>
    float Euclidean(const Point4D<T>& a, const Point4D<T>& b)
    {
        return
            sqrtf(
                (a.X - b.X) * (a.X - b.X) +
                (a.Y - b.Y) * (a.Y - b.Y) +
                (a.Z - b.Z) * (a.Z - b.Z) +
                (a.U - b.U) * (a.U - b.U)
            );
    }

    template <typename T, std::false_type>
    float Euclidean(const Point2D<T>& a, const Point2D<T>& b)
    {
        return
            (a.X - b.X) * (a.X - b.X) +
            (a.Y - b.Y) * (a.Y - b.Y);
    }

    template <typename T, std::false_type>
    float Euclidean(const Point3D<T>& a, const Point3D<T>& b)
    {
        return
            (a.X - b.X) * (a.X - b.X) +
            (a.Y - b.Y) * (a.Y - b.Y) +
            (a.Z - b.Z) * (a.Z - b.Z);
    }

    template <typename T, std::false_type>
    float Euclidean(const Point4D<T>& a, const Point4D<T>& b)
    {
        return
            (a.X - b.X) * (a.X - b.X) +
            (a.Y - b.Y) * (a.Y - b.Y) +
            (a.Z - b.Z) * (a.Z - b.Z) +
            (a.U - b.U) * (a.U - b.U);
    }
#pragma endregion

#pragma region Manhattan
    template <typename T>
    float Manhattan(const Point2D<T>& a, const Point2D<T>& b)
    {
        return
            smath::abs(a.X - b.X) +
            smath::abs(a.Y - b.Y);
    }

    template <typename T>
    float Manhattan(const Point3D<T>& a, const Point3D<T>& b)
    {
        return
            smath::abs(a.X - b.X) +
            smath::abs(a.Y - b.Y) +
            smath::abs(a.Z - b.Z);
    }

    template <typename T>
    float Manhattan(const Point4D<T>& a, const Point4D<T>& b)
    {
        return
            smath::abs(a.X - b.X) +
            smath::abs(a.Y - b.Y) +
            smath::abs(a.Z - b.Z) +
            smath::abs(a.U - b.U);
    }
#pragma endregion

#pragma region Chebyshev
    template <typename T>
    float Chebyshev(const Point2D<T>& a, const Point2D<T>& b)
    {
        return
            std::max
            (
                smath::abs(a.X - b.X),
                smath::abs(a.Y - b.Y)
            );
    }

    template <typename T>
    float Chebyshev(const Point3D<T>& a, const Point3D<T>& b)
    {
        return
            std::max
            (
                smath::abs(a.X - b.X),
                smath::abs(a.Y - b.Y),
                smath::abs(a.Z - b.Z)
            );
    }

    template <typename T>
    float Chebyshev(const Point4D<T>& a, const Point4D<T>& b)
    {
        return
            std::max
            (
                smath::abs(a.X - b.X),
                smath::abs(a.Y - b.Y),
                smath::abs(a.Z - b.Z),
                smath::abs(a.U - b.U)
            );
    }
#pragma endregion
}
