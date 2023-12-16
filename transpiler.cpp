#include "transpiler.h"

void logic(ifstream& in) {
  std::ofstream outFile("output.cpp");
  outFile << "#include <iostream>\n";
  outFile << "#include <vector>\n";
  outFile << "int main() {\n";
  outFile << "  std::vector<unsigned char> vals(25000,0);\n";
  outFile << "  unsigned long idx = 0;\n";

  std::stringstream buffer;
  buffer << in.rdbuf();
  std::string content = buffer.str();

  cout << content << endl;

  for (size_t i = 0; i < content.length(); i++) {
    auto c = content[i];

    if (c == '\n' || c == '\r' || c == ' ' || c == '\t')
      continue;

    size_t count = 1;

    while (i+1 < content.length()) {
      auto next = content[i+1];
      if (next == c) {
        count++;
        i++;
      }
      else if (next == '\n' || next == '\r' || next == ' ' || next == '\t') {
        i++;
      }
      else {
        break; // go to next valid instruction
      }

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
        outFile << "  if (idx < 0) {idx = 0;}\n";
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

      // -------------------------------
      default:
        break;
      // -------------------------------
    }
  }
  outFile << "}\n";
}
