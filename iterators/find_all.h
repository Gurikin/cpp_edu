#ifndef FIND_ALL
#define FIND_ALL

#include <iterator>
#include <vector>

using namespace std;

template <typename T> using Iterator = typename T::iterator;

template <typename C, typename V>
vector<Iterator<C>> find_all(C &c, V v) {
  vector<Iterator<C>> result;
  for (auto p = c.begin(); p != c.end(); p++) {
    if (*p == v)
      result.push_back(p);
  }
  return result;
}

#endif