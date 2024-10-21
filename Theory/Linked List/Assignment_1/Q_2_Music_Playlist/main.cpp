#include <iostream>

#include "music_playlist.cpp"
#include "music_playlist.h"
#include "song.h"
using namespace std;

void display_menu();

int main() {
  MusicPlaylist playlist;
  Song* head = nullptr;
  int choice;
  char song_name[100];
  int position;
  char filename[100];

  do {
    display_menu();
    cin >> choice;
    cin.ignore();

    switch (choice) {
      case 1:
        cout << "Enter song name: ";
        cin.getline(song_name, 100);
        playlist.add_song_at_start(head, song_name);
        break;

      case 2:
        cout << "Enter song name: ";
        cin.getline(song_name, 100);
        playlist.add_song_at_end(head, song_name);
        break;

      case 3:
        cout << "Enter song name: ";
        cin.getline(song_name, 100);
        cout << "Enter position: ";
        cin >> position;
        playlist.add_song_at_position(head, song_name, position);
        break;

      case 4:
        cout << "Enter song name to remove: ";
        cin.getline(song_name, 100);
        playlist.remove_song_by_name(head, song_name);
        break;

      case 5:
        cout << "\nPlaylist from Start to End:" << endl;
        playlist.display_begin_to_end(head);
        break;

      case 6:
        cout << "\nPlaylist from End to Start:" << endl;
        playlist.display_end_to_begin(head);
        break;

      case 7:
        cout << "Enter song name to search: ";
        cin.getline(song_name, 100);
        if (playlist.search_song(head, song_name)) {
          cout << song_name << " found in the playlist." << endl;
        } else {
          cout << song_name << " not found in the playlist." << endl;
        }
        break;

      case 8:
        cout << "Next song: " << playlist.play_next_song(head) << endl;
        break;

      case 9:
        cout << "Previous song: " << playlist.play_previous_song(head) << endl;
        break;

      case 10:
        cout << "Enter filename to save playlist: ";
        cin.getline(filename, 100);
        playlist.save_playlist(head, filename);
        break;

      case 11:
        cout << "Enter filename to load playlist: ";
        cin.getline(filename, 100);
        playlist.load_playlist(head, filename);
        break;

      case 0:
        cout << "Exiting... Thank you!" << endl;
        break;

      default:
        cout << "Invalid option. Please choose again." << endl;
        break;
    }

  } while (choice != 0);

  return 0;
}

void display_menu() {
  cout << "\n--- Music Playlist Menu ---" << endl;
  cout << "1. Add Song at Start" << endl;
  cout << "2. Add Song at End" << endl;
  cout << "3. Add Song at Position" << endl;
  cout << "4. Remove Song by Name" << endl;
  cout << "5. Display Playlist (From Start to End)" << endl;
  cout << "6. Display Playlist (From End to Start)" << endl;
  cout << "7. Search Song" << endl;
  cout << "8. Play Next Song" << endl;
  cout << "9. Play Previous Song" << endl;
  cout << "10. Save Playlist to File" << endl;
  cout << "11. Load Playlist from File" << endl;
  cout << "0. Exit" << endl;
  cout << "Choose an option: ";
}
