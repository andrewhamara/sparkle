#include "transpiler.h"

void logic(ifstream& in) {
  std::ofstream outFile("output.cpp");
  outFile << "#include <iostream>\n";
  outFile << "#include <vector>\n";
  outFile << "int main() {\n";
  outFile << "  std::vector<unsigned char> vals(25000,0);\n";
  outFile << "  unsigned long idx = 0;\n";

  string line;
  while (getline(in,line)) {
    for (size_t i = 0; i < line.length(); i++) {
      auto c = line[i];
      size_t count = 1;

      while (i+1 < line.length() && line[i+1] == c) {
        count++;
        i++;
      }
      switch (c) {

        // -------------------------------
        case '>':
          outFile << "  idx += " << count << ";\n";
          outFile << "  if (idx >= vals.size()) {vals.resize(idx+1, 0);}\n";
          break;
        // -------------------------------

        // -------------------------------
        case '<':
          outFile << "  idx -= " << count << ";\n";
          outFile << "  if (curIdx < 0) {idx = 0;}\n";
          break;
        // -------------------------------

        // -------------------------------
        case '?':
          for (size_t j = 0; j < count; j++) {
            outFile << "  std::cout << vals[idx];\n";
          }
          break;
        // -------------------------------

        // -------------------------------
        case '*':
          outFile << "  vals[idx] += " << count << ";\n";
          break;
        // -------------------------------

        // -------------------------------
        case '!':
          outFile << "  vals[idx]-= " << count << ";\n";
          break;
        // -------------------------------
      }
    }
  }
  outFile << "}\n";
}
