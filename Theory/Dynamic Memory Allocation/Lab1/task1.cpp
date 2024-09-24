#include <iostream>
using namespace std;

struct Contact {
  string name;
  string phone_number;
};

struct ContactList {
  Contact* contact_ptr;
  int num_contacts;           // The number of contacts;
  int max_contacts_capacity;  // The maximum contacts capacity

  // Constructor
  ContactList(int max_capacity) {
    max_contacts_capacity = max_capacity;
    num_contacts = 0;
    contact_ptr = new Contact[max_capacity];  // Pointer pointing towards the
                                              // array of contacts
  }

  // Destructor
  ~ContactList() { delete[] contact_ptr; }

  // Adding contact
  void add_contact(string const& name, string const& phone_number) {
    if (num_contacts < max_contacts_capacity) {
      contact_ptr[num_contacts].name = name;
      contact_ptr[num_contacts].phone_number = phone_number;
      num_contacts++;
    } else
      cout << "There are no contacts currently avaliable\n";
  }

  // This would print all the contacts
  void print_all_contact() {
    if (num_contacts <= max_contacts_capacity) {
      for (int i = 0; i < num_contacts; i++) {
        cout << "Contact " << i + 1 << ": " << contact_ptr[i].name << " ";
        cout << contact_ptr[i].phone_number << "\n";
      }
    } else
      cout << "There are not contacts to print\n";
  }

  int remaining_contact() { return max_contacts_capacity - num_contacts; }
};

void main_menu() {
  cout << "\n\n";
  cout << "------ WELCOME TO MAIN MENU -------\n";
  cout << "1. ADD CONTACTS\n";
  cout << "2. PRINTING ALL THE CONTACTS\n";
  cout << "3. EXIT THE PROGRAM\n";
  cout << "\n\n";
}

int main() {
  int maxcapacity;
  cout << "Enter the maximum Capacity of Contacts\n";
  cin >> maxcapacity;

  ContactList contactlist(maxcapacity);

  int option;

  while (true) {
    main_menu();
    cin >> option;

    if (option == 1) {
      if (contactlist.remaining_contact() == 0)
        cout << "All contacts are filled\n";
      else {
        string name;
        string phone_number;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone Number: ";
        cin >> phone_number;
        contactlist.add_contact(name, phone_number);
        cout << "Contact Added Successfully! \n\n";
        cout << "Number of Contacts Filled: " << contactlist.num_contacts
             << "\n";
        cout << "Number of Contacts Remaining:- "
             << contactlist.remaining_contact() << "\n";
      }
    }

    else if (option == 2) {
      cout << "Printing all the contacts\n";
      contactlist.print_all_contact();
    } else if (option == 3) {
      cout << "Exiting the Program \n";
      break;
    } else {
      cout << "Please enter valid input" << endl;
    }
  }
}