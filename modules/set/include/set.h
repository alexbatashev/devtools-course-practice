// Copyright 2019 - Alexander Batashev
#ifndef SET_H_
#define SET_H_

#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
class set {
 private:
  std::vector<T> _items;

 public:
  typedef typename std::vector<T>::const_iterator const_iterator;

  set() = default;
  set(const set& src) = default;
  set(set&& src) = default;
  set& operator=(const set& src) = default;
  set& operator=(set&& src) = default;

  void insert(T item) {
    if (std::find(_items.begin(), _items.end(), item) == _items.end()) {
      _items.push_back(item);
      std::sort(_items.begin(), _items.end());
    }
  };

  void remove(T item) {
    const auto& pos = std::find(_items.begin(), _items.end(), item);
    if (pos != _items.end()) {
      _items.erase(pos);
    }
  };

  const_iterator begin() const { return _items.begin(); }

  const_iterator end() const { return _items.end(); };

  size_t size() { return _items.size(); }
};

#endif
