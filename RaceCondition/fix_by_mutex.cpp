#include <iostream>
#include <thread>
#include <mutex>

using namespace std::chrono_literals;

int a = 0;
std::mutex mtx;

int main(){
  std::thread first([](){
    for (int i = 0; i < 100000000; i++) {
      mtx.lock();
      a++;
      //printf("Thread #1: %d\n", a);
      mtx.unlock();
      //std::this_thread::sleep_for(1ms);
    }
  });  

  std::thread second([](){
    for (int i = 0; i < 100000000; i++) {
      mtx.lock();
      a++;
      //printf("Thread #2: %d\n", a);
      mtx.unlock();
      //std::this_thread::sleep_for(1ms);
    }
  });

  first.join();
  second.join();

  std::cout << "Final A: " << a << std::endl;

  return 0;
}
