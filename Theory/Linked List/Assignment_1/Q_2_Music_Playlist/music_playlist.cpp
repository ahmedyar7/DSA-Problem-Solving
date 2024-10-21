#include "music_playlist.h"

#include <fstream>

#include "song.h"

// Helper function to compare two char arrays
bool compare_strings(const char* str1, const char* str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      return false;
    }
    i++;
  }
  return str1[i] == str2[i];
}

// ---  Insertion ---
void MusicPlaylist::add_song_at_start(Song*& head, const char* song_name) {
  Song* new_song = new Song(song_name);
  if (head == nullptr) {
    head = new_song;
    return;
  }
  new_song->set_next_song(head);
  head->set_prev_song(new_song);
  head = new_song;
}

void MusicPlaylist::add_song_at_end(Song*& head, const char* song_name) {
  Song* new_song = new Song(song_name);
  if (head == nullptr) {
    head = new_song;
    return;
  }
  Song* temp = head;
  while (temp->get_next_song() != nullptr) {
    temp = temp->get_next_song();
  }
  temp->set_next_song(new_song);
  new_song->set_prev_song(temp);
}

void MusicPlaylist::add_song_at_position(Song*& head, const char* song_name,
                                         int position) {
  if (position <= 0) {
    cout << "Invalid Position\n";
    return;
  }
  if (position == 1) {
    add_song_at_start(head, song_name);
    return;
  }
  Song* new_song = new Song(song_name);
  Song* temp = head;
  for (int i = 1; i < position - 1 && temp->get_next_song() != nullptr; i++) {
    temp = temp->get_next_song();
  }
  new_song->set_next_song(temp->get_next_song());
  if (temp->get_next_song() != nullptr) {
    temp->get_next_song()->set_prev_song(new_song);
  }
  new_song->set_prev_song(temp);
  temp->set_next_song(new_song);
}

Song* MusicPlaylist::remove_song_by_name(Song*& head, const char* song_name) {
  Song* current_song = head;
  while (current_song != nullptr) {
    if (compare_strings(current_song->get_song(), song_name)) {
      if (current_song->get_prev_song() != nullptr) {
        current_song->get_prev_song()->set_next_song(
            current_song->get_next_song());
      } else {
        head = current_song->get_next_song();
      }
      if (current_song->get_next_song() != nullptr) {
        current_song->get_next_song()->set_prev_song(
            current_song->get_prev_song());
      }
      Song* next_song = current_song->get_next_song();
      delete current_song;
      return next_song;
    }
    current_song = current_song->get_next_song();
  }
  return nullptr;
}

// --- Display ---
void MusicPlaylist::display_begin_to_end(Song* head) {
  Song* temp = head;
  while (temp != nullptr) {
    cout << "[" << temp->get_song() << "] <-> ";
    temp = temp->get_next_song();
  }
  cout << "NULL\n";
}

void MusicPlaylist::display_end_to_begin(Song* head) {
  if (head == nullptr) {
    cout << "The playlist is empty.\n";
    return;
  }
  Song* temp = head;
  while (temp->get_next_song() != nullptr) {
    temp = temp->get_next_song();
  }
  while (temp != nullptr) {
    cout << "[" << temp->get_song() << "]";
    temp = temp->get_prev_song();
    if (temp != nullptr) {
      cout << " <-> ";
    }
  }
  cout << " NULL\n";
}

// --- Search Song ---
bool MusicPlaylist::search_song(Song* head, const char* song_name) {
  Song* temp = head;
  while (temp != nullptr) {
    if (compare_strings(temp->get_song(), song_name)) {
      return true;
    }
    temp = temp->get_next_song();
  }
  return false;
}

// --- Play Next Song ---
const char* MusicPlaylist::play_next_song(Song* head) {
  Song* temp = head;
  if (temp->get_next_song() == nullptr) {
    cout << "There is no next song\n";
    return "";
  }
  cout << "Next Song is playing: \n";
  return temp->get_next_song()->get_song();
}

// --- Play Previous Song ---
const char* MusicPlaylist::play_previous_song(Song* head) {
  Song* temp = head;
  if (temp->get_prev_song() == nullptr) {
    cout << "There is no previous song\n";
    return "";
  }
  cout << "Previous Song is playing: \n";
  return temp->get_prev_song()->get_song();
}

// --- Save Playlist ---
void MusicPlaylist::save_playlist(Song* head, const char* filename) {
  ofstream file(filename);
  if (!file) {
    cout << "Error opening file!" << endl;
    return;
  }
  Song* temp = head;
  while (temp != nullptr) {
    file << temp->get_song() << endl;
    temp = temp->get_next_song();
  }
  file.close();
}

// --- Load Playlist ---
void MusicPlaylist::load_playlist(Song*& head, const char* filename) {
  ifstream file(filename);
  if (!file) {
    cout << "Error opening file!" << endl;
    return;
  }
  char song_name[100];
  while (file.getline(song_name, 100)) {
    add_song_at_end(head, song_name);
  }
  file.close();
}
