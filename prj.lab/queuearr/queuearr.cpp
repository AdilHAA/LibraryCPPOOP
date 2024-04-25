#include <queuearr/queuearr.hpp>

QueueArr::QueueArr(const QueueArr& data) {
	head_ = data.head_;
	tail_ = data.head_;
	size_ = data.size_;
}

QueueArr::QueueArr(const int& data) {
	size_ = 5;
	head_ = new int{ data };
	tail_ = head_;
}


bool QueueArr::Is_empty() {
	return size_ == 0;
}

void QueueArr::Push(const int& data) {
	if (this->Is_empty() == true) {
		capacity_ = 5;
		head_ = new int[capacity_];
		*(head_) = data;
	}
	else {
		if
	}
}