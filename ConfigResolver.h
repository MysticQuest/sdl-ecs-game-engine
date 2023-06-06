#pragma once

#include <fstream>
#include <string>
#include <map>

struct Config
{
    int width;
    int height;
    bool fullscreen;
};

class ConfigResolver
{
public:
    Config ReadSettings(const std::string& file)
    {
        std::ifstream in(file);
        std::string line;
        Config config;

        while (std::getline(in, line))
        {
            std::stringstream ss(line);
            std::string key;
            std::string value;
            std::getline(ss, key, '=');
            std::getline(ss, value, '=');

            if (key == "width")
                config.width = std::stoi(value);
            else if (key == "height")
                config.height = std::stoi(value);
            else if (key == "fullscreen")
                config.fullscreen = value == "true" ? true : false;
        }

        return config;
    }
};
