#ifndef MUSIC_PLAYLIST_H
#define MUSIC_PLAYLIST_H

#include "song.h"

class MusicPlaylist {
 private:
 public:
  //. ---  Insertion ---
  void add_song_at_start(Song*& head, string song_name);
  void add_song_at_end(Song*& head, string song_name);
  void add_song_at_position(Song*& head, string song_name, int position);

  //. --- Removal ---
  Song* remove_song_by_name(Song*& head, string song_name);

  //. --- Display ---
  void display_begin_to_end(Song* head);
  void display_end_to_begin(Song* head);

  //. --- Search Song ---
  bool search_song(Song* head, string song_name);

  //. --- Play Next Song ---
  string play_next_song(Song* head);

  //. --- Play Previous Song ---
  string play_previous_song(Song* head);

  //. --- Save Playlist ---
  void save_playlist(Song* head, string filename);
  void load_playlist(Song*& head, string filename);
};

#endif
