#pragma once

// This macro header need to be always included at last

#ifndef UNICODE

#define string std::string;
#define string_view std::string_view
#define cout std::cout;
#define cerr std::cerr;
#define cin std::cin;
#define ifstream std::ifstream;
#define ofstream std::ofstream;
#define t_char char;

#else

#define string std::wstring
#define string_view std::wstring_view
#define cout std::wcout
#define cerr std::wcerr
#define cin std::wcin
#define ifstream std::wifstream
#define ofstream std::wofstream
#define t_char wchar_t

#endif

namespace secsome
{
    constexpr int MAX_LINE_LENGTH = 1024;
}