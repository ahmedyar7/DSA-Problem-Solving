#include "FileManagementApp.h"

int main() {
  FileManagementApp app;

  // Option 1: Scan all drives
  //   app.run();

  // Option 2: Scan a specific directory (uncomment and modify path)
  app.run(
      "C:\\Users\\MULTITECH\\Desktop\\3rd Semester\\Statistics & Probability");

  return 0;
}