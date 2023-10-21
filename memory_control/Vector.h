class Vector {
public:
  Vector(int s); // конструктор: создает инвариант, захват ресурсов
  ~Vector() { delete[] elem; } // деструктор: освобождение ресурсов

  Vector(const Vector &v); // конструктор: копирующий
  Vector(Vector&& v); // конструктор: перемещающий
  Vector &operator=(const Vector &v); // присваивание: копирующее
  Vector &operator=(const Vector &&v); // присваивание: перемещающее
  // we don't change members, but could change that in what they point
  // example: {elem = {1,2,3} is restricted; but *elem = {1,2,3} is allowed;}
  double &operator[](int i) const;
  int size() const;

private:
  double *elem;
  int sz;
};