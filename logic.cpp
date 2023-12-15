#include "logic.h"

bool logic(ifstream& in) {
  std::vector<unsigned char> vals{0};
  unsigned long curIdx = 0;

  string line;
  while (getline(in,line)) {
    for (auto &c : line) { //shoutout to Scott Meyers
      switch (c) {

        // -------------------------------
        case '>':
          curIdx++;
          if (curIdx >= vals.size()) {
            vals.push_back(0);
          }
          break;
        // -------------------------------

        // -------------------------------
        case '<':
          if (curIdx != 0) {
            curIdx--;
          }
          break;
        // -------------------------------

        // -------------------------------
        case 'p':
          std::cout << vals[curIdx];
          break;
        // -------------------------------

        // -------------------------------
        case 'a':
          vals[curIdx]++;
          break;
        // -------------------------------

        // -------------------------------
        case 's':
          vals[curIdx]--;
          break;
        // -------------------------------
      }
    }
  }
  return true;
}
