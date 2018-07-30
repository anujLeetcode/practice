#include<iostream>
#include<thread>

using namespace std;

void test() {
  for(int i = 0; i < 100000; i++) {
    cout << "in test thread " << endl;
  }
}

int main() {

  thread thread_obj(test);
  thread_obj.join();
  for(int i = 0; i < 10; i++) {
    cout << "In main thread" << endl;
  }

  return 1;
}
