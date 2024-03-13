#pragma once

#include <string>

class Titleable {
    public:
        virtual std::string getTitle() const = 0;
};