#include <stackarr/stackarr.hpp>
#include <complex/complex.hpp>

StackArr& StackArr::operator=(const StackArr& s) {
    size_ = s.size_;
    data_ = new Complex[size_];
     top_ = s.top_;
    for (int i = 0; i < size_; i++) {
        *(data_ + i) = *(s.data_ + i);
    }
    return *this;
}

StackArr::StackArr(const StackArr& s) {
    size_ = s.size_;
    data_ = new Complex[size_];
    top_ = s.top_;
    for (int i = 0; i < size_; i++) {
        *(data_ + i) = *(s.data_ + i);
    }
};

StackArr::StackArr(const Complex& value) {
    size_ = 2;
    data_ = new Complex[size_];
    top_ = 0;
    *(data_ + top_) = value;
}


bool StackArr::Is_empty() {
    if (top_ == -1) {
        return true;
    }
    else {
        return false;
    }
   }

void StackArr::Push(const Complex& value) {
    Complex* old_data;
    old_data = data_;
    top_++;
    if ((top_ + 1) > size_) {
        size_ = size_ +1;
    }
    std::memcpy(data_, old_data, sizeof(int) * size_);
    *(data_ + top_) = value;
}

void StackArr::Pop() {
    if (top_ == -1) {
        throw std::logic_error("StackArr IS EMPTY");
    }
    else {
        top_--;
    }
}
void StackArr::Pop(const int& count_to_erase) {
    if (top_ == -1) {
        throw std::logic_error("StackArr IS EMPTY");
    }
    else {
        top_-= count_to_erase;
    }
}
