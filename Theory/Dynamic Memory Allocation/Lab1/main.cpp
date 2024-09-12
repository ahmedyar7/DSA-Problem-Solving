#include <iostream>
using namespace std;

struct Contact {
  string name;
  string phone_number;
};

struct Contact_List {
  Contact *ptr;
  int numcontacts;
  int maximumCapacity;

  // Constructor
  Contact_List(int capacity) {
    maximumCapacity = capacity;
    numcontacts = 0;
    ptr = new Contact[maximumCapacity];
  }

  // Destructor
  ~Contact_List() { delete[] ptr; }

  void add_contact(string const &name, string const &phone_number) {
    if (numcontacts < maximumCapacity) {
      ptr[numcontacts].name = name;
      ptr[numcontacts].phone_number = phone_number;
      numcontacts++;
    }
  }

  void print_contact() {
    if (numcontacts == 0) {
      cout << "There are no contact currently available " << endl;
    }
    for (int i = 0; i < numcontacts; i++) {
      cout << "Contact " << i + 1 << ": " << ptr[i].name << " "
           << ptr[i].phone_number << "\n";
    }
  }

  int remaining_contacts() { return maximumCapacity - numcontacts; }
};

int main() {
  int max_capacity;
  cout << "Enter the maximum capacity of your contacts you want: \n";
  cin >> max_capacity;

  Contact_List contact_list(max_capacity);

  int option;
  while (true) {
    cout << "\n";
    cout << "Welcome to MY CONTACT\n";
    cout << "1.Adding the Contact\n";
    cout << "2.Printing the Contacts\n";
    cout << "4.Exit the Program\n";
    cout << "Enter the option: \n";
    cout << "\n";

    cin >> option;

    if (option == 1) {
      if (contact_list.remaining_contacts() == 0) {
        cout << "The Contacts are all filled\n";
      } else {
        string name, phone_number;
        cout << "Enter the Name: ";
        cin >> name;
        cout << "Enter the Phone Number: ";
        cin >> phone_number;
        contact_list.add_contact(name, phone_number);
        cout << "Contacts are load Successfully\n\n";
        cout << "Contacts filled: " << contact_list.numcontacts << endl;
        cout << "Contact Remaining: " << contact_list.remaining_contacts()
             << endl;
      }
    }

    else if (option == 2) {
      cout << "Printing all contacts\n";
      contact_list.print_contact();
    } else if (option == 4) {
      cout << "Exiting the Program Goodbye\n";
      break;
    } else {
      cout << "Not a valid Input\n";
    }
  }

  return 0;
}