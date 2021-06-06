#pragma once

#include <Base.h>

namespace secsome::strings
{
    bool not_null_char(t_char ch)
    {
        if (ch == '\0' || ch == '\t' || ch == '\n' || ch == ' ' || ch == '\r')
            return false;
        return true;
    }

    void trim_left(string& src)
    {
        const auto itr = std::find_if(src.begin(), src.end(), not_null_char);
        if (itr != src.end())
            src = src.substr(_STD distance(src.begin(), itr));
    }

    void trim_right(string& src)
    {
        const auto itr = std::find_if(src.rbegin(), src.rend(), not_null_char);
        if (itr != src.rend())
            src = src.substr(0, src.size() - _STD distance(src.rbegin(), itr));
    }

    void trim(string& src)
    {
        trim_left(src);
        trim_right(src);
    }

}