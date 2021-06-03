#pragma once

namespace secsome::point
{

    template <typename T>
    class Point2D
    {
    public:
        Point2D() : X(0), Y(0) {}
        Point2D(const T& x, const T& y) : X(x), Y(y) {}

        Point2D(const Point2D& pnt) = default;
        Point2D(Point2D&& pnt) = default;
        Point2D& operator = (const Point2D& pnt) = default;
        Point2D& operator = (Point2D&& pnt) = default;

        ~Point2D() = default;

        T X, Y;
    };

    template <typename T>
    struct Point3D
    {
    public:
        Point3D() : X(0), Y(0), Z(0) {}
        Point3D(const T& x, const T& y, const T& z) : X(x), Y(y), Z(z) {}

        Point3D(const Point3D& pnt) = default;
        Point3D(Point3D&& pnt) = default;
        Point3D& operator = (const Point3D& pnt) = default;
        Point3D& operator = (Point3D&& pnt) = default;

        ~Point3D() = default;

        T X, Y, Z;
    };

    template <typename T>
    struct Point4D
    {
    public:
        Point4D() : X(0), Y(0), Z(0), U(0) {}
        Point4D(const T& x, const T& y, const T& z, const T& u) : X(x), Y(y), Z(z), U(u) {}

        Point4D(const Point4D& pnt) = default;
        Point4D(Point4D&& pnt) = default;
        Point4D& operator = (const Point4D& pnt) = default;
        Point4D& operator = (Point4D&& pnt) = default;

        ~Point4D() = default;

        T X, Y, Z, U;
    };
}