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

    std::cout << "\nRead Config values:\n\n";

    std::string key("max_iterations");
    std::cout << key << "\t\t" << config.get<size_t>(key) << std::endl;

    key = "write_best";
    std::cout << key << "\t\t" << config.get<bool>(key) << std::endl;

    key = "undefined";
    std::cout << key << "\t\t" << config.get<size_t>(key, 42) << std::endl;

    key = "fraction";
    std::cout << key << "\t\t" << config.get<double>(key) << std::endl;

    key = "invalid_fraction";
    std::cout << key << "\t" << config.get<std::string>(key) << std::endl;

    key = "neg_fraction";
    std::cout << key << "\t\t" << config.get<double>(key) << std::endl;

    key = "neg_int";
    std::cout << key << "\t\t\t" << config.get<long>(key) << std::endl;
    try
    {
        const auto read_value = config.get<double>(key);
        std::cout << key << "\t\t\t" << read_value << " (double)\n";
    }
    catch (...)
    {
        std::cout << key << "\t\t\tneg_int was not read as a double; exception caught.\n";
    }

    key = "kmax";
    try
    {
        const auto read_value = config.get<double>(key);
        std::cout << key << "\t\t\t" << read_value << std::endl;
    }
    catch (...)
    {
        std::cout << key << "\t\t\tno entry nor default value; exception caught.\n";
    }

    std::cout << "\nOther tests:\n\n";

    key = "non_existent_key";
    std::cout << "has " << key << "?\t" << config.has(key) << std::endl;

    std::cout << "\n";
    return 0;
}
