#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> a = 0;

int main(){
  std::thread first([](){
    for (int i = 0; i < 100000000; i++) {
      a.fetch_add(1);
    }
  });  

  std::thread second([](){
    for (int i = 0; i < 100000000; i++) {
      a.fetch_add(1);
    }
  });

  first.join();
  second.join();

  std::cout << "Final A: " << a << std::endl;

  return 0;
}
