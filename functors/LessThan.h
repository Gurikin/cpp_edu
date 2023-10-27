template <typename T> class LessThan {
public:
  LessThan(const T &v) : val(v){};
  bool operator()(const T &x) const {
    return x < val;
  };
private:
  const T val;
};