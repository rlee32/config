#include "Config.h"

#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "please input config file path." << std::endl;
        return 0;
    }

    const auto first_argument {argv[1]};
    Config config(first_argument);

    std::cout << "Read config file:" << std::endl;

    std::string key("max_iterations");
    std::cout << key << "\t" << config.get<size_t>(key) << std::endl;

    key = "write_best";
    std::cout << key << "\t" << config.get<bool>(key) << std::endl;

    key = "undefined";
    std::cout << key << "\t" << config.get<size_t>(key, 42) << std::endl;

    return 0;
}
