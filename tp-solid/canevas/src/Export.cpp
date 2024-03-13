#include "Export.hpp"
#include <iterator>

void Export::exportYAML(std::ostream &os, std::vector<Description> ds) {
    for (const auto &description: ds) {
        for (const auto pair : description) {
            os << pair.first << " : " << pair.second << "\n";
        }
        os << "\n";
    }
}

void Export::exportJSON(std::ostream &os, std::vector<Description> ds) {
    os << "[\n";
    for (const auto &description: ds) {
        os << " {\n";
        for (const auto pair : description) {
            os << "     " << "\"" << pair.first << "\" : \"" << pair.second << "\",\n";
        }
        os << " },\n";
    }
    os << "]\n";
}