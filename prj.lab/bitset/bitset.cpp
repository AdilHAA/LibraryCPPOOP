#include <bitset/bitset.hpp>



BitSet::BitSet(const int32_t& size) {
	if (size < 0) {
		throw std::logic_error("Size can not be lower 0");
	}
	else {
		for (int i = 0; i < size; i++) {
			data_.push_back(0);
		}
		size_ = size;
	}
};

BitSet::BitSet(const BitSet& copy) {
	data_ = copy.data_;
	size_ = copy.size_;
}

BitSet::BitSet(BitSet&& copy) noexcept {
	std::swap(data_, copy.data_);
	std::swap(size_, copy.size_);
}


BitSet& BitSet::operator=(const BitSet& copy) {
	data_ = copy.data_;
	size_ = copy.size_;
	return *this;
}

BitSet& BitSet::operator=(BitSet&& copy) noexcept {
		size_ = copy.size_;
		data_.clear();
		for (int i = 0; i < size_; i++) {
			data_.push_back(copy.data_[i]);
		}
		copy.size_ = 0;
		copy.data_.clear();
		return *this;
};
BitSet& BitSet::operator&=(const BitSet& val) {
	if (size_ != val.size_) {
		throw std::logic_error("Not same size bitsets");
	}
	else {
		for (int i = 0; i <= size_ - 1 / 32; i++) {
			data_[i] &= val.data_[i];
		}
	}
	return *this;
};


BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
	return BitSet(lhs) &= rhs;
};


BitSet& BitSet::operator|=(const BitSet& val) {
	if (size_ != val.size_) {
		throw std::logic_error("Not same size bitsets");
	}
	else {
		for (int i = 0; i <= size_ - 1 / 32; i++) {
			data_[i] |= val.data_[i];
		}
	}
	return *this;
}

BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
	return BitSet(lhs) |= rhs;
}

BitSet& BitSet::operator^=(const BitSet& val) {
	if (size_ != val.size_) {
		throw std::logic_error("Not same size bitsets");
	}
	else {
		for (int i = 0; i <= size_ - 1 / 32; i++) {
			data_[i] ^= val.data_[i];
		}
	}
	return *this;
}

BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
	return BitSet(lhs) ^= rhs;
}


void BitSet::operator~() {
	for (int i = 0; i <= (this->size_ - 1) / 32; i++) {
		data_[i] = ~data_[i];
	}
}

bool BitSet::operator==(const BitSet& val) {
	if (size_ == val.size_) {
		if (size_ == 0) {
			return true;
		}
		bool flag = true;
		for (int i = 0; i < size_ - 1 / 32; i++) {
			if (data_[i] != val.data_[i]) {
				flag = false;
				break;
			}
		}
		return flag;
	}
	return false;
}

bool BitSet::operator!=(const BitSet& val) {
	return !(operator==(val));
}


void BitSet::Resize(const int32_t& size) {

	if (size_ < 0) {
		throw std::logic_error("Size can not be lower 0");
	}
	else if (size == 0) {
		data_.push_back(0);
		size_ = 0;
	}
	else if (size > size_) {
		int curr_box = size_ -1 / 32;
		int need_box = size-1 / 32;
		if (need_box == curr_box) {
			size_ = size;
		}
		else {
			while (curr_box != need_box) {
				data_.push_back(0);
				curr_box +=1;
			}
			size_ = size;
		}
	}
	else if (size < size_) {
		int curr_box = size_-1 / 32;
		int need_box = size-1 / 32;
		int current_id = (size_-1) % 32+1;
		int need_id = (size - 1) % 32+1;
		while (curr_box != need_box) {
			data_[curr_box] = 0;
			curr_box -= 1;
			current_id = 31;
		}
		while (current_id != need_id) {
			data_[curr_box] &= ~(1 << current_id);
			current_id--;
		}
		size_ = size;
	}
};


bool BitSet::Get(const int32_t& id) const {
	int num_cell = id / 32;
	int num_in_cell = id % 32 - 1;

	if ((data_[num_cell] & (1 << num_in_cell)) == (1 << num_in_cell)) {
		return true;
	}
		else {
			return false;
		}
}

void BitSet::Set(const int32_t& id, const bool& val) {
	if (val != 0 && val != 1) {
		throw std::logic_error("Bit can not be not 0 or 1");
	}

	int num_cell = id / 32;
	int num_in_cell = id % 32 - 1;

	//add bit
	if (val == 0) {
		data_[num_cell] &= ~(1 << num_in_cell);
	}
	else if (val == 1) {
		data_[num_cell] |= (1 << num_in_cell);
	}
}


BitSet::BiA BitSet::operator[](const int32_t& id) {
	if (id >= 0) {
		BiA a(*this,id);

		return a;
	}
	else {
		throw std::logic_error("Id can not be lower 0");
	}
}




