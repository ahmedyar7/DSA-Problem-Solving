#include <iostream>

#include "music_playlist.cpp"
#include "music_playlist.h"
#include "song.h"
using namespace std;

int main() {
  MusicPlaylist playlist;
  Song* head = nullptr;  // Pointer to the head of the playlist
  int choice;
  string song_name;
  int position;
  string filename;

  do {
    display_menu();
    cin >> choice;
    cin.ignore();  // Ignore newline character after reading choice

    switch (choice) {
      case 1:
        cout << "Enter song name: ";
        getline(cin, song_name);
        playlist.add_song_at_start(head, song_name);
        break;

      case 2:
        cout << "Enter song name: ";
        getline(cin, song_name);
        playlist.add_song_at_end(head, song_name);
        break;

      case 3:
        cout << "Enter song name: ";
        getline(cin, song_name);
        cout << "Enter position: ";
        cin >> position;
        playlist.add_song_at_position(head, song_name, position);
        break;

      case 4:
        cout << "Enter song name to remove: ";
        getline(cin, song_name);
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
        getline(cin, song_name);
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
        getline(cin, filename);
        playlist.save_playlist(head, filename);
        break;

      case 11:
        cout << "Enter filename to load playlist: ";
        getline(cin, filename);
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
