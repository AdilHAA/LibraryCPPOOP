#ifndef StackArr_ARRAY
#define StackArr_ARRAY
#include <iostream>
#include <stdexcept>
#include <complex/complex.hpp>


class StackArr {
public:
    StackArr() = default;
    StackArr(const StackArr& s);
    StackArr(const Complex& value);
    ~StackArr() = default;
    StackArr& operator=(const StackArr& s);
    void Push(const Complex& value);
    void Pop();
    void Pop(const int& count_to_erase);
    bool Is_empty();
    Complex Top() {
        if (top_ != -1) {
            return *(data_+ top_);
        }
        else {
            throw std::logic_error("STACK IS EMPTY");
        }
    };

private:
    std::ptrdiff_t size_ = 0;
    Complex* data_ = nullptr;
    std::ptrdiff_t top_ = -1;

};
#endif;