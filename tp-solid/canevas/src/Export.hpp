#pragma once

#include "Descriptible.hpp"
#include <ostream>
#include <vector>

class Export {
    public:

    void exportYAML(std::ostream &os, std::vector<Description> ds);
    void exportJSON(std::ostream &os, std::vector<Description> ds);
};