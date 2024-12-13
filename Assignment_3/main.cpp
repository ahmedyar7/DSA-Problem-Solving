#include <iostream>

#include "file.h"
using namespace std;

int main() {
  File file1("example.txt", 500, "2023-12-13");
  File file2("data.bin", 1200, "2023-11-25");

  file1.display();
  file2.display();

  if (File::compare_by_name(file1, file2) < 0)
    std::cout << file1.get_file_name() << " comes before "
              << file2.get_file_name() << std::endl;

  return 0;
}