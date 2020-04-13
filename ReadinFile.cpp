#include "library.h"
#include <sstream>
#include <fstream>
#include <string>

void main() {
  ifstream fin(open_file_pop_up("", "", string("select file"));
  int year, month, day;
  double min_t, avg_t, max_t;
  double depth, amount, wind;
  while (true) {
    fin >> year >> month >> day >> min_t >> avg_t >> max_t >> depth >> amount >> wind;
    // cout << year << "_" <<  month << "_" << day << "_" << ":" << avg_t << "\n";
  }
}
