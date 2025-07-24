#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
    Span(); 

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;

    template<typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        if (static_cast<unsigned int>(_numbers.size() + std::distance(begin, end)) > _maxSize)
            throw std::overflow_error("Too many numbers to add to Span.");
        _numbers.insert(_numbers.end(), begin, end);
    }
};

#endif
