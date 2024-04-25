#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <stdexcept>
#include <cstddef>

class DynArr {
public:
	DynArr() = default;
	 explicit DynArr(const DynArr& copy);
	 explicit DynArr(const ptrdiff_t size);
	~DynArr();
	DynArr(DynArr&& copy) noexcept;
	DynArr& operator=(const DynArr& value);
	DynArr& operator=(DynArr&& value) noexcept;
	std::ptrdiff_t Size() const noexcept { return size_; }
	std::ptrdiff_t Capacity() const noexcept { return capacity_; }

	void Resize(const std::ptrdiff_t size);
	

	float& operator[](const std::ptrdiff_t i);
	const float& operator[](const std::ptrdiff_t i) const;

private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t capacity_ = 0;
	float* data_ = nullptr;
	float default_value = 0;
};

#endif //DynArr_HPP