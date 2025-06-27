#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <limits>

class Span {
private:
    unsigned int _capacity;
    std::vector<int> _numbers;

public:
    // Constructor
    Span(unsigned int N);

    // Destructor
    ~Span();

    // Copy constructor and assignment
    Span(const Span& other);
    Span& operator=(const Span& other);

    // Add a single number
    void addNumber(int num);

    // Add a range of numbers
    template<typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        if (static_cast<unsigned int>(std::distance(begin, end)) + _numbers.size() > _capacity)
            throw std::out_of_range("Adding this range would exceed span capacity");
        _numbers.insert(_numbers.end(), begin, end);
    }

    // Span computations
    int shortestSpan() const;
    int longestSpan() const;
};

#endif // SPAN_HPP
