// #include <iostream>
// using namespace std;

// class Shop {
//  private:
//   int item_id[100];
//   int item_price[100];
//   int counter;

//  public:
//   void init_counter(void) { counter = 0; }

//   void get_price(void) {}

//   void set_price(void) {
//     cout << "Enter Id of your item No" << counter + 1 << endl;
//     cin >> item_id[counter];
//     cout << "Enter Price of your item" << endl;
//     cin >> item_price[counter];
//     counter++;
//   }

//   void display_price(void) {
//     for (int i = 0; i < counter; i++) {
//       cout << "The Price of item with id " << item_id[i] << " is "
//            << item_price[i] << endl;
//     }
//   }
// };

// int main() {
//   Shop dukan;
//   dukan.init_counter();
//   dukan.set_price();
//   dukan.set_price();
//   dukan.set_price();
//   dukan.display_price();
// }

// #include <iostream>
// using namespace std;

// int main() {
//   int arr[3] = {10, 20, 30};
//   int *p = arr;
//   cout << "First Element " << *(p + 1) << endl;
//   cout << "2nd Element " << *(p + 2) << endl;
//   cout << "3rd Element " << *(p + 3) << endl;
// }

// int *create_array(int size) {
//   return new int[size];  // Dynamically allocating the memory
// }

// int main() {
//   int *arr = create_array(5);  // Create a Pointer Variable
//   for (int i = 0; i < 100; i++) {
//     arr[i] = i + 1;
//     cout << arr[i] << " ";
//   }
//   delete[] arr;
// }

// struct Person {
//   string name;
//   int age;
// };
// int main() {
//   Person p = {"Ahmed", 19};
//   Person *ptr = &p;

//   cout << ptr->age << endl;
//   cout << ptr->name << endl;
// }

// int main() {
//   int *p = new int(3);
//   cout << "Dynamically Allocated Integer " << endl;
//   cout << *p << endl;

//   delete p;  // Delete the memory
// }

#include <iostream>
using namespace std;

class Car {
 public:
  string model;
  int year;

  // Constructor
  Car(string m, int y) {
    model = m;
    year = y;
  }

  // Method to display details
  void display() {
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
  }
};

int main() {
  // Creating object using pointer
  Car *carPtr =
      new Car("Toyota", 2020);  // Dynamically allocate memory for object

  // Accessing members using pointer
  carPtr->display();

  // Don't forget to deallocate the memory after use
  delete carPtr;

  return 0;
}
