/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

/*
class LRUCache {

  int capacity_;
  list<int> used;
  unordered_map<int, pair<int, list<int>::iterator> > cache;

  void touch(int key) {
    auto it = cache.find(key);
    list<int>::iterator ii = it->second.second;
    used.erase(ii);
    cache.erase(key);
    used.push_front(key);
    cache[key].insert({ key, used.begin() });
  }
  
public:
  LRUCache(int capacity) {
    capacity_ = capacity;      
  }
    
  int get(int key) {
    if(cache.find(key) != cache.end()) {
      auto it = cache.find(key);
      int val = it->second.first;
      touch(key);
      return val;
    }
    return -1;    
  }
    
  void put(int key, int value) {
    if(cache.find(key) != cache.end()) {
      touch(key);
      return;
    }
    
    if (used.size() == capacity_) {
      cache.erase(used.back());
      used.pop_back();
      used.push_front(key);
    }
    cache[key]={key, used.front()};
    touch(key);
  }
};

*/


class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    HIPII cache;
    LI used;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
