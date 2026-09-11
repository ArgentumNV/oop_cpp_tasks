#include "../include/module1.h"
#include "../include/module2.h"
#include "../include/module3.h"

// using std::cout; чтобы не писать все время std::cout, а просто cout

#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Hello world!" << "\n";

    std::cout << Module1::getMyName() << "\n";
    std::cout << Module2::getMyName() << "\n";

    using namespace Module1;
    std::cout << getMyName() << "\n"; // (A)
    std::cout << Module2::getMyName() << "\n";

    // using namespace Module2;          // (B)
    // std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

    using Module2::getMyName;
    std::cout << getMyName() << "\n"; // (D)
}
