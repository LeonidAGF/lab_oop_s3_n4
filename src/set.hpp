#pragma once
#include <cstddef>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstring>
#include "3D.hpp"

class Set final {
public:
	Set();
	Set(const Set& x);
	Set(Set&& x) noexcept;
	Set& operator=(const Set& other);
	Set& operator=(Set&& x) noexcept;
	~Set();
	bool add(const shape& x);
	bool remove(const shape& x);
	bool contains(const shape& x) const;
	bool operator()(const shape& x) const;
	std::size_t size() const;
	bool empty() const;
	Set& operator+=(const shape& x);
	Set& operator-=(const shape& x);
	bool operator==(const Set& x) const;
	bool operator!=(const Set& x) const;
	friend std::ostream& operator<<(std::ostream&, const Set&);

private:
	shape* data_ = nullptr;
	std::size_t size_ = 0;
	std::size_t capacity_ = 0;
};