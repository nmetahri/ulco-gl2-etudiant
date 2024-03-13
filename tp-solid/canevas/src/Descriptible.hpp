#pragma once

#include <string>
#include <map>

using Description = std::map<std::string, std::string>;

class Descriptible{

public:
    virtual Description toDescription() const = 0;
};