#include "singleton.h"

#include <iostream>
#include <mutex>

namespace {
// std::mutex m_mutex in unnamed namespace
std::mutex m_mutex;
} // namespace

Singleton::Singleton() : m_value{0} {
  std::cout << "object wit address: " << this << " created\n";
}

void Singleton::add() {
  // case we have a lot of rewrites so we use normal mutex, we also dont get
  // throw;
  m_mutex.lock();
  m_value++;
  m_mutex.unlock();
}
void Singleton::print() {
  m_mutex.lock();
  std::cout << "object wit address: " << this << ", value = " << this->m_value
            << "\n";
  m_mutex.unlock();
}