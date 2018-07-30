#include<iostream>
#include<stdio>

using namespace std;

class reader_writer_lock {

std::mutex mtx;
std::condition_variable cv;
int reader;
int writer;

 void readerLock() {
   unique_lock<std::mutex> l(mutex);
   cv.wait(l, [](){l, writer == 0};
   reader++;
 }

 void writerLock() {
   unique_lock<std::mutex> l(mutex);
   cv.wait(l, [](){l, reader == 0};
   reader++;
 }

 void readerUnLock() {
   unique_lock<std::mutex> l(mutex);
   reader--;
 }
}


