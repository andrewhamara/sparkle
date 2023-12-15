#include "logic.h"

bool logic(ifstream& in) {
  std::ofstream outFile("output.cpp");
  outFile << "#include <iostream>\n";
  outFile << "#include <vector>\n";
  outFile << "int main() {\n";
  outFile << "  std::vector<unsigned char> vals(25000,0);\n";
  outFile << "  unsigned long idx = 0;\n";

  string line;
  while (getline(in,line)) {
    for (auto &c : line) { //shoutout to Scott Meyers
      switch (c) {

        // -------------------------------
        case '>':
          outFile << "  idx++;\n";
          outFile << "  if (idx >= vals.size()) {vals.push_back(0);}\n";
          break;
        // -------------------------------

        // -------------------------------
        case '<':
          outFile << "  if (curIdx != 0) {curIdx--;}\n";
          break;
        // -------------------------------

        // -------------------------------
        case '?':
          outFile << "  std::cout << vals[curIdx];\n";
          break;
        // -------------------------------

        // -------------------------------
        case '*':
          outFile << "  vals[curIdx]++;\n";
          break;
        // -------------------------------

        // -------------------------------
        case '!':
          outFile << "  vals[curIdx]--;\n";
          break;
        // -------------------------------
      }
    }
  }
  return true;
}
