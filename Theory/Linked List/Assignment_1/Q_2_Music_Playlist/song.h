#ifndef SONG_H
#define SONG_H

#include <iostream>
using namespace std;

class Song {
 private:
  Song* next;
  Song* prev;
  string song_name;

 public:
  Song(string song_name) {
    this->song_name = song_name;
    next = nullptr;
    prev = nullptr;
  }
  void set_next_song(Song* song) { next = song; }
  void set_prev_song(Song* song) { prev = song; }

  Song* get_next_song() { return next; }
  Song* get_prev_song() { return prev; }
  string get_song() { return song_name; }
};

#endif