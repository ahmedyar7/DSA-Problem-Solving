#ifndef WAITINGROOM_H
#define WAITINGROOM_H

#include <iostream>

#include "patient.h"
using namespace std;

const int MAXSIZE = 100;

class WaitingRoom {
 private:
  Patient queue[MAXSIZE];
  int front;
  int rear;
  int patient_counter;  // Counter to assign to new patient

  // Helper function to compare names
  int compare_names(char name_1[], char name_2[]) {
    int i = 0;
    while (name_1[i] != '\0' && name_2[i] != '\0' && name_1[i] == name_2[i])
      i++;
    return name_1[i] - name_2[i];
  }

 public:
  WaitingRoom() {
    front = -1;
    rear = -1;
    patient_counter = 0;
  }

  bool is_empty() const { return front == -1; }
  bool is_full() const { return ((rear + 1) % MAXSIZE == front); }

  void register_patient(char name[]) {  // Represents enqueue
    if (is_full()) {
      cout << "Waiting Room is Full Currently\n";
      return;
    }
    Patient new_patient;
    new_patient.id = patient_counter++;

    // Copy the name manually
    int i = 0;
    while (name[i] != '\0' && i < 49) {  // Limit name size to avoid overflow
      new_patient.name[i] = name[i];
      i++;
    }
    new_patient.name[i] = '\0';  // Null-terminate

    if (is_empty()) {
      front = 0;
      rear = 0;
    } else {
      rear = (rear + 1) % MAXSIZE;
    }
    queue[rear] = new_patient;
    cout << "Patient: " << new_patient.name << " registered with ID "
         << new_patient.id << endl;
  }

  void serve_patient() {  // Represents dequeue
    if (is_empty()) {
      cout << "No Patient to serve\n";
      return;
    }

    cout << "Serving Patient with Name: " << queue[front].name
         << " Registration ID " << queue[front].id << endl;

    if (front == rear) {
      front = -1;
      rear = -1;
    } else {
      front = (front + 1) % MAXSIZE;
    }
  }

  void cancel_all() {
    front = -1;
    rear = -1;
    cout << "All the Appointments have been canceled.\n";
  }

  bool can_cancel_doc() const { return is_empty(); }

  void show_all_patients() {
    if (is_empty()) {
      cout << "No patients are currently waiting.\n";
      return;
    }

    int count = (rear + MAXSIZE - front) % MAXSIZE + 1;
    Patient* patient_list = new Patient[count];
    int index = 0;

    // Copy patients to temporary array
    for (int i = front; i != rear; i = (i + 1) % MAXSIZE) {
      patient_list[index++] = queue[i];
    }
    patient_list[index] = queue[rear];

    // Bubble sort by name
    for (int i = 0; i < count - 1; ++i) {
      for (int j = 0; j < count - i - 1; ++j) {
        if (compare_names(patient_list[j].name, patient_list[j + 1].name) > 0) {
          Patient temp = patient_list[j];
          patient_list[j] = patient_list[j + 1];
          patient_list[j + 1] = temp;
        }
      }
    }

    cout << "List of all waiting patients (sorted by name):\n";
    for (int i = 0; i < count; ++i) {
      cout << "ID: " << patient_list[i].id << ", Name: " << patient_list[i].name
           << "\n";
    }

    delete[] patient_list;
  }
};

#endif
