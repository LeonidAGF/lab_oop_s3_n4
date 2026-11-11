#pragma once
#include <iostream>
#include "3D.hpp"

class Set final {
public:
	Set();
	Set(const Set& x);
	Set(Set&& x) noexcept;
	Set& operator=(const Set& other);
	Set& operator=(Set&& x) noexcept;
	~Set();
	bool add(shape* x);
	bool remove(shape* x);
	bool contains(shape* x) const;
	bool operator()(shape* x) const;
	std::size_t size() const;
	bool empty() const;
	Set& operator+=(shape* x);
	Set& operator-=(shape* x);
	bool operator==(const Set& x) const;
	bool operator!=(const Set& x) const;
	double sum_metrics() const;
	friend std::ostream& operator<<(std::ostream&, const Set&);
	

private:
	shape** data_ = nullptr;
	std::size_t size_ = 0;
	std::size_t capacity_ = 0;
};