#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::vector<int>::iterator itVec = easyfind(vec, 2);
        std::cout << "Found in vector: " << *itVec << std::endl;

        std::list<int>::iterator itLst = easyfind(lst, 30);
        std::cout << "Found in list: " << *itLst << std::endl;

        easyfind(vec, 42);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
