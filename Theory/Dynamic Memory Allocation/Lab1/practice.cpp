#include <iostream>
using namespace std;

struct Contact {
  string name;
  string phone_number;
};

struct ContactList {
  int max_contact_cap;
  int contact_num;
  Contact *ptr;

  ContactList(int maxcapacity) {
    max_contact_cap = maxcapacity;
    contact_num = 0;
    ptr = new Contact[max_contact_cap];
  }

  ~ContactList() { delete[] ptr; }

  void add_contact(string const &name, string const &phone_number) {
    if (contact_num <= max_contact_cap) {
      ptr[contact_num].name = name;
      ptr[contact_num].phone_number = phone_number;
      contact_num++;
    }
  }

  void print_contact() {
    if (contact_num == 0) cout << "There are no contact currently available\n";
    for (int i = 0; i < contact_num; i++) {
      cout << "Contact: " << (i + 1) << endl;
      cout << "Name: " << ptr[i].name << endl;
      cout << "Phone NUmber: " << ptr[i].phone_number << endl;
    }
  }

  int remaining_contact() { return max_contact_cap - contact_num; }
};
