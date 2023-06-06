#include "SettingsResolver.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>

std::string SettingsResolver::trim(const std::string& str)
{
    auto start = std::find_if_not(str.begin(), str.end(), ::isspace);
    auto end = std::find_if_not(str.rbegin(), str.rend(), ::isspace).base();
    return (start < end) ? std::string(start, end) : "";
}

Config SettingsResolver::ReadSettings(const std::string& file)
{
    std::ifstream in(file);
    if (!in) throw std::runtime_error("Failed to open settings file");

    setters = {
        {"width", [](Config& config, const std::string& value) { config.width = std::stoi(value); }},
        {"height", [](Config& config, const std::string& value) { config.height = std::stoi(value); }},
        {"fullscreen", [](Config& config, const std::string& value) { config.fullscreen = (value == "true"); }},
    };

    std::string line;
    Config config;

    while (std::getline(in, line))
    {
        std::stringstream ss(line);
        std::string key;
        std::string value;
        std::getline(ss, key, '=');
        std::getline(ss, value, '=');

        key = trim(key);
        value = trim(value);

        auto setter = setters.find(key);
        if (setter == setters.end()) throw std::runtime_error("Unrecognized setting: " + key);

        setter->second(config, value);
    }

    return config;
}
