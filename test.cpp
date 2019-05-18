#include "config.h"

#include <iostream>
#include <variant>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "please input config file path." << std::endl;
        return 0;
    }
    const auto first_argument {argv[1]};
    const auto config {config::read(first_argument)};
    std::cout << "Read config file:" << std::endl;
    std::string key("max_iterations");
    std::cout << key << "\t" << std::get<size_t>(config.at(key)) << std::endl;
    key = "write_best";
    std::cout << key << "\t" << std::get<bool>(config.at(key)) << std::endl;
    return 0;
}
