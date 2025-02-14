#include <iostream>
#include <thread>


int a = 0;

int main(){
  std::thread first([](){
    for (int i = 0; i < 100000000; i++) {
      a++; 
      //printf("Thread #1: %d\n", a);
    }
  });  

  std::thread second([](){
    for (int i = 0; i < 100000000; i++) {
      a++;
      //printf("Thread #2: %d\n", a);
    }
  });

  first.join();
  second.join();

  std::cout << "Final A: " << a << std::endl;

  return 0;
}
