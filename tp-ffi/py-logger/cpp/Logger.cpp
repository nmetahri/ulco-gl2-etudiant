#include "Logger.hpp"

#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>
#include <vector>

void Logger::addItem(Level l, const std::string &m)
{
  _items.push_back(std::make_tuple(l, m));
}

std::string Logger::reportByAdded() const
{
  std::string output = "**** report_by_added ****\n";

  for (const auto &tuple : _items)
  {
    switch (std::get<0>(tuple))
    {
    case Level::Info:
      output += "[I]";
      break;
    case Level::Warning:
      output += "[W]";
      break;
    case Level::Error:
      output += "[E]";
      break;
    default:
      output += "[Unknown]";
    }
    output += std::get<1>(tuple) + "\n";
  }

  return output;
}

std::string Logger::reportByLevel() const
{
  std::string output = "**** report_by_level ****\n";

  std::vector<Item> info; 
  std::vector<Item> warning; 
  std::vector<Item> error;

  for (auto &tuple: _items)
  {
    const auto lev = std::get<0>(tuple); 
    if (lev == Level::Info){
      info.push_back(tuple);
    } else if (lev == Level::Warning) {
      warning.push_back(tuple);
    } else if (lev == Level::Error) {
      error.push_back(tuple);
    }
  }

  for (auto &tuple: info)
  {
    output += "[I]" + std::get<1>(tuple) + "\n";
  }

  for (auto &tuple: warning)
  {
    output += "[W]" + std::get<1>(tuple) + "\n";
  }

  for (auto &tuple: error)
  {
    output += "[E]" + std::get<1>(tuple) + "\n";
  }

  return output;
}
