#ifndef SONG_H
#define SONG_H

#include <iostream>
using namespace std;

class Song {
 private:
  Song* next;
  Song* prev;
  char song_name[100];

 public:
  Song(const char* song_name) {
    int i = 0;
    while (song_name[i] != '\0' && i < 99) {
      this->song_name[i] = song_name[i];
      i++;
    }
    this->song_name[i] = '\0';
    next = nullptr;
    prev = nullptr;
  }
  void set_next_song(Song* song) { next = song; }
  void set_prev_song(Song* song) { prev = song; }

  Song* get_next_song() { return next; }
  Song* get_prev_song() { return prev; }
  const char* get_song() { return song_name; }
};

#endif
