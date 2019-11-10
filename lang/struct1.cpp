#include <iostream>
#include <string>

struct Data {
  Data(std::string n, double v) : name(n), value(v) { 
      std::cout << "from Data ctor: begin" << std::endl; 
  }

  std::string name;
  double value;
};


int main(int argc, char ** argv) {
  std::cout << "from main(): begin" << std::endl;
  Data d = {"Dimitar", 1.01};
}
