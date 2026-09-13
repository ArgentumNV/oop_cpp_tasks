#pragma once

#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>
#include <iomanip>

namespace parser
{
    int pars_txt_to_csv(std::string txt_name, std::string csv_name);
}