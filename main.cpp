#include "logic.h"

using std::endl;
using std::cerr;
using std::ifstream;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <filename>" << endl;
    return -1;
  }

  ifstream in(argv[1]);

  if (in.fail()) {
    cerr << "File " << argv[1] << " not found" << endl;
    return -2;
  }

  logic(in);

  return 0;
}
