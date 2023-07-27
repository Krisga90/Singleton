#include "singleton.h"

#include <iostream>
#include <random>
#include <thread>
#include <vector>

void func(int times) {
  Singleton &s = Singleton::getInstance();
  for (int i = 0; i < times; i++) {
    s.add();
  }
  s.print();
}

int main() {

  int times = 100000;
  std::thread thr1(func, times);
  std::thread thr2(func, times);

  thr1.join();
  thr2.join();
  return 0;
}
