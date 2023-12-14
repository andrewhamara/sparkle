#include "logic.h"

bool logic(ifstream& in) {
  string line;
  while (getline(in,line)) {
    for (auto c : line) { //shoutout to modern c++
      cout << c << endl;
    }
  }
}
