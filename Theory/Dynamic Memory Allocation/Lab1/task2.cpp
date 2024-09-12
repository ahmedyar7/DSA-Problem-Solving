#include <iostream>
using namespace std;

class DynamicArray {
 private:
  /*
   1. Array already store addresss to the memory location of the values
   2. So we need another pointer to point at those memory locations.
   3. Thus that why we created Pointer-to-Pointer array.
 */

 public:
  int **array;
  int size;
  // Constructor
  DynamicArray(int size) {
    size = size;
    array = new int *[size];  // Pointer pointing toward the index of array
    for (int i = 0; i < size; i++) {
      array[i] = new int(0);  // Initialize all elements to 0
    }
  }

  // Destructor
  ~DynamicArray() {
    for (int i = 0; i < size; i++) {
      delete array[i];
    }
    delete[] array;
  }

  // Methods to set value at a particular index
  void set(int index, int value) {
    if (index >= 0 && index < size) {
      *array[index] = value;
    } else {
      cout << "Index is out of range \n";
    }
  }

  // Method to get value at a particular index
  int get(int index) {
    if (index >= 0 && index < size) {
      return *array[index];
    } else {
      cout << "Index is out of Bound! \n";
      return -1;
    }
  }

  // Method to print all values in the array
  void printArray() {
    for (int i = 0; i < size; i++) {
      cout << *array[i] << " ";
    }
    cout << endl;
  }
};

void main_menu() {
  cout << "\n\n---- WELCOME TO DYNAMIC_ARRAY -----\n\n";
  cout << "1. SET THE VALUE\n";
  cout << "2. GET THE VALUE\n";
  cout << "3. PRINT THE ARRAY\n";
  cout << "4. EXIT PROGRAM\n\n";
}

int main() {
  cout << "Enter the size of array: ";
  int size_of_array;
  cin >> size_of_array;

  DynamicArray d_arr(size_of_array);
  int option;

  while (true) {
    main_menu();
    cin >> option;

    if (option == 1) {
      int index, value;
      cout << "Enter the Index: ";
      cin >> index;
      cout << "Enter the Value: ";
      cin >> value;

      d_arr.set(index, value);
    } else if (option == 2) {
      int index;
      cout << "Enter the index: ";
      cin >> index;
      int value = d_arr.get(index);
      cout << "Value: " << value << endl;
    } else if (option == 3) {
      cout << "Array values: ";
      d_arr.printArray();
    } else if (option == 4) {
      cout << "Exiting the Program\n";
      break;
    } else {
      cout << "Invalid Input\n";
    }
  }

  return 0;
}
