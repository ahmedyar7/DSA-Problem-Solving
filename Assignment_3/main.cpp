#include <iostream>

#include ".include/file_management_app.h"
using namespace std;

int main() {
  try {
    FileManagementApp app;
    app.run();
    // app.run(
    //     "C:\\Users\\MULTITECH\\Desktop\\3rd Semester\\Statistics & "
    //     "Probability");
  } catch (const exception& e) {
    cerr << "An error occurred: " << e.what() << endl;
    return 1;
  }

  system("pause");
  return 0;
}