#include "../include/Parser.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Programm using: " << argv[0] << " .txt .csv\n";
        return 1;
    }

    if ((parser::pars_txt_to_csv(argv[1], argv[2])) != 0)
    {
        std::cerr << "Something went wrong" << std::endl;
    }

    return 0;
}