#pragma once

#include <string>
#include <functional>
#include <map>

struct Config
{
    int width;
    int height;
    bool fullscreen;
    int frame_rate;
};

class SettingsResolver
{
public:
    Config ReadSettings(const std::string& file);

private:
    std::string trim(const std::string& str);
    std::map<std::string, std::function<void(Config&, const std::string&)>> setters;
};
