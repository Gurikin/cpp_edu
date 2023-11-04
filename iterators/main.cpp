#include "find_all.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int, char **) {
  string m{"Mary had a little lamb"};
  for (auto p : find_all(m, 'a')) {
    cout << *p << endl;
    if (*p != 'a') {
      cerr << "string bug!" << endl;
    }
  }

  list<double> listDbl{1.1, 2.2, 3.3, 1.1};
  for (auto p : find_all(listDbl, 1.1)) {
    cout << *p << endl;
    if (*p != 1.1) {
      cerr << "list bug!" << endl;
    }
  }
}
