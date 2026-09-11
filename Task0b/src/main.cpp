#include "../include/Parser.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Использование программы: " << argv[0] << ".txt .csv\n";
        return 1;
    }

    return 0;
}