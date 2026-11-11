#include "set.hpp"

Set::Set():size_(0), capacity_(1){
	data_ = new shape*[capacity_];
}
Set::Set(const Set& x):size_(x.size_), capacity_(x.capacity_) {
	data_ = new shape*[capacity_];
	for (size_t i = 0; i < x.size_; ++i) {
		data_[i] = x.data_[i]->clone();
	}
}
Set::Set(Set&& x) noexcept :size_(x.size_), capacity_(x.capacity_)  {

	if (*this == x)
		return;

	for (size_t i = 0; i < size_; ++i) {
		delete data_[i];
	}
	data_ = x.data_;

	x.data_ = nullptr;
	x.capacity_ = 0;
	x.size_ = 0;
}
Set& Set::operator=(const Set& other) {
	if (this == &other)
		return *this;
	Set tmp(other);
	std::swap(data_, tmp.data_);
	std::swap(size_, tmp.size_);
	std::swap(capacity_, tmp.capacity_);
	return *this;
}

Set& Set::operator=(Set&& x) noexcept {

	if(this == &x)
		return *this;

	delete[] data_;
	data_ = x.data_;
	capacity_ = x.capacity_;
	size_ = x.size_;
	x.data_ = nullptr;
	x.capacity_ = 0;
	x.size_ = 0;
	return *this;
}
Set::~Set() {

	for (size_t i = 0; i < size_; ++i) {
		delete data_[i];
		data_[i] = nullptr;
	}
	delete[] data_;
	data_ = nullptr;
}

bool Set::contains(shape* x) const {
	if (!x)
		return false;
	if (data_) {
		size_t L = 0, R = size_, M;
		while (L < R) {
			M = (L + R) / 2;
			if (*data_[M] < *x)
				L = M+1;
			else if (*data_[M] == *x) {
				return 1;
			}
			else 
				R = M;
		}
		return L < size_ && *data_[L] == *x;
	}
	return 0;
}

bool Set::add(shape* x) {
	if (contains(x))
		return false;

	if (size_ == capacity_) {
		size_t new_capacity = (capacity_>0? capacity_:1) *2;
		shape** new_data = new shape*[new_capacity];
		std::memcpy(new_data, data_, size_*sizeof(shape*));
		delete[] data_;
		data_ = new_data;
		capacity_ = new_capacity;
	}

	size_t L = 0, R = size_, M;
	while (L < R) {
		M = (L + R) / 2;
		if (*data_[M] < *x)
			L = M + 1;
		else if (*data_[M] == *x) {
			return 0;
		}
		else
			R = M;
	}
	
	for (size_t i = size_; i > R; --i)
		data_[i] = data_[i - 1];
	data_[R] = x;
	size_++;
	return true;
}
bool Set::remove(shape* x) {
	if (!x)
		return false;
	size_t L = 0, R = size_,M;
	while (L < R) {
		M = L + (R - L) / 2;
		if (*data_[M] < *x)
			L = M + 1;
		else
			R = M;
	}
	if (L >= size_ || !(*data_[L] == *x))
		return false;

	delete data_[L];
	data_[L] = nullptr;

	for (size_t i = L + 1; i < size_; ++i)
		data_[i - 1] = data_[i];
	--size_;
	return true;
}

bool Set::operator()(shape* x) const {
	return contains(x);
}
std::size_t Set::size() const {
	return size_;
}
bool Set::empty() const {
	return size_ == 0;
}
Set& Set::operator+=(shape* x) {
	add(x);
	return *this;
}
Set& Set::operator-=(shape* x) {
	remove(x);
	return *this;
}

bool Set::operator==(const Set& x) const {
	bool res = 1;
	if (size_ != x.size_) {
		res = 0;
	}
	else {
		for (size_t i = 0; i < size_; ++i) {
			res = *data_[i] == *x.data_[i];
			if (!res)
				break;
		}
	}
	return res;
}
bool Set::operator!=(const Set& x) const {
	return !((*this)==x);
}

std::ostream& operator<<(std::ostream& os, const Set& s) {
	os << "{ ";
	for (size_t i = 0; i < s.size_; ++i)
		os << (*s.data_[i]) << "; ";
	return os << "}";
}