#include <iostream>

using namespace std;

struct Vector {
  int size;
  double *elem; //Указатель на массив элементов
};

void vectorInit(Vector &v, int size) {
  v.elem = new double[size]; //Массив из элементов типа double размером size
  v.size = size;
}

double readAndSum(Vector &v, int s) {
  vectorInit(v, s);
  double sum = 0;
  for (int i = 0; i != s; ++i) {
    cin >> v.elem[i];
    sum += v.elem[i];
  }
  return sum;
}

void printVectorInfo(Vector v, Vector &rv, Vector *pv) {
  cout << "By name (.): " << v.size << endl;
  cout << "By name (.): " << v.elem << endl;
  cout << "By reference (.): " << rv.size << endl;
  cout << "By reference (.): " << rv.elem << endl;
  cout << "By pointer (->): " << pv->size << endl;
  cout << "By pointer (->): " << pv->elem << endl;
}

int main(int, char **) {
  Vector v;
  cout << "Sum of vector = " << readAndSum(v, 3) << endl;
  cout << "Print vector info:" << endl;
  printVectorInfo(v, v, &v);
  return 0;
}
