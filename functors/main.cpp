#include "Vector.h" 
#include "LessThan.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <list>

using namespace std;

template <typename C, typename P> int count(const C &c, P predicate) {
  int cnt = 0;
  for (const auto &x : c) {
    if (predicate(x)) {
      cnt++;
    }
  }
  return cnt;
}

void f(const Vector<int> &vecInt, const Vector<string> &vecStr, int &x, string &str) {
  cout << "number of values less than " << x << ":\t"
       << count(vecInt, LessThan<int>{x}) << endl;
  cout << "number of values less than " << str << ":\t"
       << count(vecStr, LessThan<string>{str}) << endl;
}

int main(int, char **) {
  Vector<int> vecInt(5);
  vecInt[0] = 1;
  vecInt[1] = 5;
  vecInt[2] = 10;
  vecInt[3] = 15;
  vecInt[4] = 20;

  Vector<string> vecStr(5);
  vecStr[0] = "Back00";
  vecStr[1] = "Back01";
  vecStr[2] = "Back02";
  vecStr[3] = "Back03";
  vecStr[4] = "Back04";

  string s = "Aack01";
  int i = 2;

  f(vecInt, vecStr, i, s);
}
