#ifndef MUSIC_PLAYLIST_H
#define MUSIC_PLAYLIST_H

#include "song.h"

class MusicPlaylist {
 public:
  void add_song_at_start(Song*& head, const char* song_name);
  void add_song_at_end(Song*& head, const char* song_name);
  void add_song_at_position(Song*& head, const char* song_name, int position);
  Song* remove_song_by_name(Song*& head, const char* song_name);
  void display_begin_to_end(Song* head);
  void display_end_to_begin(Song* head);
  bool search_song(Song* head, const char* song_name);
  const char* play_next_song(Song* head);
  const char* play_previous_song(Song* head);
  void save_playlist(Song* head, const char* filename);
  void load_playlist(Song*& head, const char* filename);
};

#endif
