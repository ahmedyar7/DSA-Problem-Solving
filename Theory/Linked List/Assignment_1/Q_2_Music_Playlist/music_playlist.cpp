#include "music_playlist.h"

#include <fstream>
#include <string>

#include "song.h"

//. ---  Insertion ---
void MusicPlaylist::add_song_at_start(Song*& head, string song_name) {
  Song* new_song = new Song(song_name);
  if (head == nullptr) {
    head = new_song;
    return;
  }
  new_song->set_next_song(head);
  head->set_prev_song(new_song);
  head = new_song;
  return;
}

void MusicPlaylist::add_song_at_end(Song*& head, string song_name) {
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
  new_song->set_next_song(nullptr);
  return;
}

void MusicPlaylist::add_song_at_position(Song*& head, string song_name,
                                         int position) {
  if (position <= 0) {
    cout << "Invalid Position\n";
    return;
  }
  Song* new_song = new Song(song_name);

  if (position == 1) {
    add_song_at_start(head, song_name);
    return;
  }
  Song* temp = head;
  for (int i = 1; i < position - 1 && temp->get_next_song() != nullptr; i++) {
    temp = temp->get_next_song();
  }
  new_song->set_next_song(temp->get_next_song());
  if (temp->get_next_song() != nullptr)
    temp->get_next_song()->set_prev_song(new_song);
  new_song->set_prev_song(temp);
  temp->set_next_song(new_song);

  return;
}

Song* MusicPlaylist::remove_song_by_name(Song*& head, string song_name) {
  Song* current_song = head;

  while (current_song != nullptr) {
    if (current_song->get_song() == song_name) {
      // Update the previous node's next pointer
      if (current_song->get_prev_song() != nullptr) {
        current_song->get_prev_song()->set_next_song(
            current_song->get_next_song());
      } else {
        // If current_song is the head, update the head pointer
        head = current_song->get_next_song();
      }
      // Update the next node's previous pointer
      if (current_song->get_next_song() != nullptr) {
        current_song->get_next_song()->set_prev_song(
            current_song->get_prev_song());
      }
      // Store the pointer to the next song before deleting
      Song* next_song = current_song->get_next_song();
      delete current_song;
      return next_song;
    }

    current_song = current_song->get_next_song();
  }

  // If the song was not found, return nullptr
  return nullptr;
}

void MusicPlaylist::display_begin_to_end(Song* head) {
  Song* temp = head;
  while (temp != nullptr) {
    cout << "[" << temp->get_song() << "] <-> ";
    temp = temp->get_next_song();
  }
  cout << "NUll\n";
}

void MusicPlaylist::display_end_to_begin(Song* head) {
  if (head == nullptr) {
    cout << "The playlist is empty.\n";
    return;
  }

  Song* temp = head;

  // Move to the last node
  while (temp->get_next_song() != nullptr) {
    temp = temp->get_next_song();
  }

  // Traverse from the last node to the beginning
  while (temp != nullptr) {
    cout << "[" << temp->get_song() << "]";
    temp = temp->get_prev_song();
    if (temp != nullptr) {
      cout << " <-> ";
    }
  }
  cout << " NULL\n";
}

bool MusicPlaylist::search_song(Song* head, string song_name) {
  Song* temp = head;
  while (temp != nullptr) {
    if (temp->get_song() == song_name) {
      return true;
    }
    temp = temp->get_next_song();
  }
  return false;
}

string MusicPlaylist::play_next_song(Song* head) {
  Song* temp = head;
  if (temp->get_next_song() == nullptr) {
    cout << "There is no next song\n";
  }
  cout << "Next Song is playing: \n";
  return temp->get_next_song()->get_song();
}

string MusicPlaylist::play_previous_song(Song* head) {
  Song* temp = head;
  if (temp->get_prev_song() == nullptr) {
    cout << "There is no next song\n";
  }
  cout << "Next Song is playing: \n";
  return temp->get_prev_song()->get_song();
}

void MusicPlaylist::save_playlist(Song* head, string filename) {
  ofstream file(filename);
  if (!file.is_open()) {
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

void MusicPlaylist::load_playlist(Song*& head, string filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "Error opening file!" << std::endl;
    return;
  }

  string song_name;
  while (getline(file, song_name)) {
    // Add each song to the end of the playlist as we read it from the file
    add_song_at_end(head, song_name);
  }

  file.close();
}
