#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : _capacity(N) {}

// Destructor
Span::~Span() {}

// Copy constructor
Span::Span(const Span& other) : _capacity(other._capacity), _numbers(other._numbers) {}

// Assignment operator
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _capacity = other._capacity;
        _numbers = other._numbers;
    }
    return *this;
}

// Add a single number
void Span::addNumber(int num) {
    if (_numbers.size() >= _capacity)
        throw std::out_of_range("Cannot add number: Span is full");
    _numbers.push_back(num);
}

// Shortest span
int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> temp(_numbers);
    std::sort(temp.begin(), temp.end());

    int minSpan = std::numeric_limits<int>::max();
    for (std::size_t i = 1; i < temp.size(); ++i) {
        int diff = temp[i] - temp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

// Longest span
int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}
