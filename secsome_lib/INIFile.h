#pragma once

#include <fstream>
#include <string>

#include <VectoredMap.h>
#include <Base.h>

namespace secsome::file
{
    using INIEntry = string;

    class INISection
    {
    public:
        using SectionDict = secsome::structure::VectoredMap<string, INIEntry>;

        explicit INISection(const string& name) : section_{ name } {}

        bool is_empty() const;
        void add_entry(const string key, const INIEntry& entry);
        string* get_entry(const string key);
        string get_section_name() const;
        size_t get_entry_count() const;

        using iterator = SectionDict::iterator;
        using const_iterator = SectionDict::const_iterator;

        [[nodiscard]] iterator begin() noexcept { return dict_.begin(); }
        [[nodiscard]] const_iterator begin() const noexcept { return dict_.begin(); }
        [[nodiscard]] iterator end() noexcept { return dict_.end(); }
        [[nodiscard]] const_iterator end() const noexcept { return dict_.end(); }

        INIEntry& operator[](string key);

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
        size_t get_section_count();

        INISection& operator[] (string section);

    private:
        bool trim_comment(string& src);

        bool loaded_;
        string path_;
        INIDict dict_;
    };
}