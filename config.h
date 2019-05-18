#pragma once

// Reads a config file containing lines with format "KEY VALUE".
// KEY and VALUE can be separated by any manner of whitespace.
// Only first two whitespace-separated tokens are read on each line.
// If '#' is anywhere in line, the line is ignored as a comment.
// In the case of repeated keys, the last value is used.

#include <algorithm> // transform, all_of
#include <cctype> // tolower, isdigit
#include <fstream>
#include <sstream>
#include <string> // getline, stoul
#include <unordered_map>
#include <variant>

namespace config {

using Value = std::variant<bool, size_t, std::string>;
using Dictionary = std::unordered_map<std::string, Value>;

Dictionary read(const std::string& file_path)
{
    std::ifstream input_stream(file_path);
    std::string line;
    Dictionary d;

    while (std::getline(input_stream, line))
    {
        if (line.find('#') != std::string::npos) // line is comment.
        {
            continue;
        }
        std::stringstream line_stream(line);

        std::string key;
        line_stream >> key;
        if (key.empty())
        {
            continue;
        }

        std::string value;
        line_stream >> value;
        if (value.empty())
        {
            continue;
        }

        // check boolean.
        auto lower {value};
        std::transform(std::begin(value), std::end(value), std::begin(lower), ::tolower);
        if (lower == "true")
        {
            d[key] = true;
            continue;
        }
        else if (lower == "false")
        {
            d[key] = false;
            continue;
        }

        // check size_t.
        if (std::all_of(std::cbegin(value), std::cend(value), ::isdigit))
        {
            d[key] = std::stoul(value);
            continue;
        }

        d[key] = value;
    }
    return d;
}

} // namespace config


