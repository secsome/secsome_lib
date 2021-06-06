#pragma once

#include <fstream>
#include <string>

#include <VectoredMap.h>
#include <Base.h>

namespace secsome::file
{
    class INIEntry
    {
    public:
        explicit INIEntry(const string& key, const string& value) : Key{ key }, Value{ value }{}

        bool operator< (const INIEntry &another) const { return Key < another.Key; }

        string Key;
        string Value;
    };


    class INISection
    {
    public:
        using SectionDict = secsome::structure::VectoredMap<string, INIEntry>;

        explicit INISection(const string& name) : section_{ name } {}

        bool is_empty() const;
        void add_entry(const INIEntry& entry);
        string get_section_name() const;

        using iterator = SectionDict::iterator;
        using const_iterator = SectionDict::const_iterator;

        [[nodiscard]] iterator begin() noexcept
        {
            return dict_.begin();
        }

        [[nodiscard]] const_iterator begin() const noexcept
        {
            return dict_.begin();
        }

        [[nodiscard]] iterator end() noexcept
        {
            return dict_.end();
        }

        [[nodiscard]] const_iterator end() const noexcept
        {
            return dict_.end();
        }

    private:
        string section_;
        SectionDict dict_;
    };


    class INIFile
    {
    public:
        using INIDict = secsome::structure::VectoredMap<string, INISection>;

        explicit INIFile() : loaded_{ false }, path_{ L"" }, dict_{}{}

        bool close();
        bool load_from_file(ifstream& fin);
        bool save_to_file(ofstream& fout) const;
        string get_file_path() const;
        bool is_loaded() const;
        void add_section(const INISection& section);
        INISection* get_section(string section);

    private:
        bool trim_comment(string& src);

        bool loaded_;
        string path_;
        INIDict dict_;
    };
}