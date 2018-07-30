#include<iostream>

class parent {

};

class brother : public parent {

};

class sister : public parent {

};


int main() {

  parent p;
  brother b;
  sister s;
  return 1;
}
