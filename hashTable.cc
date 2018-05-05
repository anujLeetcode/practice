#incluce<iostream>


using namespase std;
 
class hashNode {
  int key_;
  int value_;

public:
  hashNode(int key, int value) : key_(key), value_(value) {}
  int getKey() {
    return key_;
  }  

  int setKey(int key) {
    key_ = key;
  } 
 
  int getValue() {
    return value_;
  }

  int setValue(int value) {
   value_ = value;
  }  
}

class hashTable {
    hashNode** table;
    int size_;
  public:
    hashTable(int size=128) {
      table = new hashNode*[size];
      size_ = size;
    }
    
    int put(int key, value) {
      int hash = key % size_;
      while(table[hash] != NULL && table[hash].getKey() != key) {
        hash = (hash + 1) % size_;
      }
      
      if(table[hash] != NULL) delete table[hash];
      table[temp] = new hashNode(key, value);
      return 1;
    }

    int get(int key) {
      int hash = key % size_;
      while(table[hash] != NULL && table[hash].getKey() != key) {
        hash = (hash + 1) % size_;
      }
      
      if(table[hash] != NULL) return value;
      return -1;
    }

    int delete(int key) {
      int hash = key % size_;
      while(table[hash] != NULL && table[hash].getKey() != key) {
        hash = (hash + 1) % size_;
      }
      
      if(table[hash] != NULL) delete table[hash];
      return -1;
    }

 }

}
