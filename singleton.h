

class Singleton {
private:
  Singleton();

public:
  Singleton(const Singleton &) = delete;
  Singleton(const Singleton &&) = delete;
  Singleton &operator=(const Singleton &) = delete;
  Singleton &operator=(const Singleton &&) = delete;

  static Singleton &getInstance() {
    static Singleton m_singleton;
    return m_singleton;
  }
  void add();
  void print();

private:
  int m_value;
};