#include "INIFile.h"

#include "Strings.h"

bool secsome::file::INIFile::close()
{
    if(!loaded_)
        return false;

    path_.clear();
    dict_.clear();
    return true;
}

bool secsome::file::INIFile::load_from_file(ifstream& fin)
{
    string buffer;
    while (!fin.eof())
    {
        std::getline(fin, buffer);
        if (fin.eof())   return false;
        secsome::strings::trim(buffer);
        if (buffer[0] == '[' && buffer.find_first_of(']') != string::npos)
            break;
    }

    while (!fin.eof())
    {
        auto last = buffer.find_first_of(']');
        if (last != string::npos)
            buffer = buffer.substr(1, last - 1);
        INISection section{ buffer };

        while (!fin.eof())
        {
            std::getline(fin, buffer);
            if (buffer.empty()) continue;
            if (buffer[0] == '[' && buffer.find_first_of(']') != string::npos)
                break;

            trim_comment(buffer);
            if (buffer.empty() || buffer[0] == ';' || buffer[0] == '=')
                continue;

            secsome::strings::trim(buffer);
            auto divider = buffer.find_first_of('=');
            if (divider == string::npos) continue;

            INIEntry entry{ buffer.substr(0,divider),buffer.substr(divider + 1) };
            section.add_entry(entry);
        }

        if (!section.is_empty())
            add_section(section);
    }
    return true;
}

bool secsome::file::INIFile::save_to_file(ofstream& fout) const
{
    if (!fout.is_open())
        return false;

    for (const auto& section : dict_)
    {
        fout << L"[" << section.first << L"]\n";
        for (const auto& pair : section.second)
            fout << pair.first << L"=" << pair.second.Value << L"\n";
        fout << L"\n";
    }

    return true;
}

string secsome::file::INIFile::get_file_path() const
{
    return path_;
}

bool secsome::file::INIFile::is_loaded() const
{
    return loaded_;
}

void secsome::file::INIFile::add_section(const INISection& section)
{
    dict_.insert(section.get_section_name(), section);
}

secsome::file::INISection* secsome::file::INIFile::get_section(string section)
{
    return dict_.find(section);
}

bool secsome::file::INIFile::trim_comment(string& src)
{
    if (auto const flag = src.find(';') != string::npos)
    {
        src = src.substr(0, flag);
        return true;
    }
    return false;
}

bool secsome::file::INISection::is_empty() const
{
    return dict_.empty();
}

void secsome::file::INISection::add_entry(const INIEntry& entry)
{
    dict_.insert(entry.Key, entry);
}

string secsome::file::INISection::get_section_name() const
{
    return section_;
}
