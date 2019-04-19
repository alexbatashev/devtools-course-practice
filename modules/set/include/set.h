// Copyright 2019 Alexander Batashev

#ifndef MODULES_SET_INCLUDE_SET_H_
#define MODULES_SET_INCLUDE_SET_H_

#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
class Set {
 private:
  std::vector<T> _items;

 public:
  typedef typename std::vector<T>::const_iterator const_iterator;

  Set() = default;
  Set(const Set& src) = default;
  Set(Set&& src) = default;
  Set& operator=(const Set& src) = default;
  Set& operator=(Set&& src) = default;
  ~Set() = default;

  void insert(T item) {
    if (std::find(_items.begin(), _items.end(), item) == _items.end()) {
      _items.push_back(item);
      std::sort(_items.begin(), _items.end());
    }
  }

  void remove(T item) {
    const auto& pos = std::find(_items.begin(), _items.end(), item);
    if (pos != _items.end()) {
      _items.erase(pos);
    }
  }

  const_iterator begin() const { return _items.begin(); }

  const_iterator end() const { return _items.end(); }

  size_t size() { return _items.size(); }
};

#endif  // MODULES_SET_INCLUDE_SET_H_
