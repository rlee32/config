#pragma once

#include <unordered_map>
#include <string>
#include <variant>

namespace config {

using key = std::string;
using value = std::variant<int, std::string>;
using dictionary = std::unordered_map<key, value>;




} // namespace config


