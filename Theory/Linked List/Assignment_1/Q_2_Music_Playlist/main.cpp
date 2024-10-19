#include <iostream>

#include "music_playlist.cpp"
#include "music_playlist.h"
#include "song.h"
using namespace std;

int main() {
  Song* head = nullptr;
  MusicPlaylist list;

  cout << "Insert at head\n";

  list.add_song_at_start(head, "Ahmed");
  list.add_song_at_start(head, "Yar");
  list.add_song_at_start(head, "Khan");

  list.display_begin_to_end(head);

  cout << "\n Insert at tail\n";

  list.add_song_at_end(head, "Ahmed");
  list.add_song_at_end(head, "Yar");
  list.add_song_at_end(head, "Khan");

  list.display_begin_to_end(head);

  cout << "\n insert at postion\n";
  list.add_song_at_position(head, "kushkush", 2);
  list.add_song_at_position(head, "kushkush2", 4);
  list.add_song_at_position(head, "kushkush1", 1);

  list.display_begin_to_end(head);

  cout << "\nRemoving song by title\n";
  list.remove_song_by_name(head, "kushkush");
  list.display_begin_to_end(head);

  cout << "\nfrom end to begin\n";

  list.display_end_to_begin(head);

  cout << list.search_song(head, "kushkush2");
}