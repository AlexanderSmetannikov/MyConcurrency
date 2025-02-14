#include <iostream>
#include <thread>
#include "../Atomic/atomic.hpp"

Atomic a;

int main(){
  std::thread first([](){
    for (int i = 0; i < 100000000; i++) {
      a.increment();
    }
  });  

  std::thread second([](){
    for (int i = 0; i < 100000000; i++) {
      a.increment();
    }
  });

  first.join();
  second.join();

  std::cout << "Final A: " << a.load() << std::endl;

  return 0;
}
