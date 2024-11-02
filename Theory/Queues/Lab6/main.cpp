#include <iostream>

#include "patient.h"
#include "waiting_room.h"

int main() {
  WaitingRoom waitingRoom;

  // Example usage:
  waitingRoom.register_patient("Ahmed");
  waitingRoom.register_patient("Umar");
  waitingRoom.register_patient("Asjad");

  waitingRoom.show_all_patients();

  waitingRoom.serve_patient();
  waitingRoom.serve_patient();

  if (waitingRoom.can_cancel_doc())
    cout << "Doctor can go home.\n";
  else
    cout << "Patients are still waiting.\n";

  waitingRoom.cancel_all();
  waitingRoom.show_all_patients();

  return 0;
}