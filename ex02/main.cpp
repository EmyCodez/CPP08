#include <iostream>
#include <string>
#include "MutantStack.hpp"

int main()
{
    // === Test Case 1: int with iterator ===
    std::cout << "=== Test Case 1: int with iterator ===" << std::endl;
    MutantStack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    MutantStack<int>::iterator it = intStack.begin();
    MutantStack<int>::iterator ite = intStack.end();

    std::cout << "Elements in intStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // === Test Case 2: float with const_iterator ===
    std::cout << "\n=== Test Case 2: float with const_iterator ===" << std::endl;
    MutantStack<float> floatStack;
    floatStack.push(1.1f);
    floatStack.push(2.2f);
    floatStack.push(3.3f);

    MutantStack<float>::const_iterator cit = floatStack.begin();
    MutantStack<float>::const_iterator cite = floatStack.end();

    std::cout << "Elements in floatStack:" << std::endl;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    // === Test Case 3: string with reverse_iterator ===
    std::cout << "\n=== Test Case 3: string with reverse_iterator ===" << std::endl;
    MutantStack<std::string> stringStack;
    stringStack.push("one");
    stringStack.push("two");
    stringStack.push("three");

    MutantStack<std::string>::reverse_iterator rit = stringStack.rbegin();
    MutantStack<std::string>::reverse_iterator rite = stringStack.rend();

    std::cout << "Elements in stringStack (reversed):" << std::endl;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    return 0;
}
