#include <iostream>

#include "file.h"
#include "utility.h"
using namespace std;

int main() {
  const char* directory_path =
      "C:\\Users\\MULTITECH\\Documents";  // Example path
  traverse_directory(directory_path);
  return 0;
}