template <class T> class Vector {
public:
  Vector(int s) {
    elem = new T[s];
    sz = s;
  }
  ~Vector() { delete[] elem; } // деструктор: освобождение ресурсов

  T &operator[](int i) { return elem[i]; }
  const T &operator[](int i) const { return elem[i]; }
  int size() const { return sz; };
  const T *begin() const { return &elem[0]; }
  const T *end() const { return &elem[size()]; }

private:
  T *elem;
  int sz;
};