#include "Vector.h"
#include <algorithm>
#include <iostream>
#include <sys/time.h>
#include <thread>
#include <vector>

using namespace std;

void task(string msg) {
  timeval tm;
  gettimeofday(&tm, NULL);
  cout << msg << " at:\t" << tm.tv_sec << "." << tm.tv_usec / 1000 << "\t(sec)" << endl;
  this_thread::sleep_for(std::chrono::milliseconds(200));
}

Vector init(int n) {
  vector<thread> myThreads;
  for (int i = 0; i < n; i++) {
    thread t(task, "hello"); // запускаем thread
    t.join();
    myThreads.push_back(std::move(t)); // перемещаем t в пул потоков
  }

  Vector vec(n);
  for (int i = 0; i < vec.size(); i++) {
    vec[i] = i;
  }
  return vec; // ПЕРЕМЕЩАЕМ результат из init()
}

int main(int, char **) {
  auto v = init(10); // стартуем потоки из пула и инициализируем v как Vector
  for (int i = 0; i < v.size(); i++) {
    cout << "Vector[" << i << "] = " << v[i] << endl;
  }
}
