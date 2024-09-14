#include <iostream>
using namespace std;

class CharacterGrid {
 private:
  int row, col;
  char** charactergrid;

  CharacterGrid(int row, int col) {
    this->row = row;
    this->col = col;

    for (int i = 0; i < row; i++) {
      charactergrid[i] = new char[row];
      for (int j = 0; j < col; j += 1) {
        charactergrid[i][j] = '_';
      }
    }
  }
  ~CharacterGrid() {
    for (int i = 0; i < row; i++) {
      delete charactergrid[i];
      for (int j = 0; j < col; j++) {
        delete charactergrid[j];
      }
    }
  }

  void set_char(int gridrow, int gridcol, char value) {
    if (gridrow >= 0 && gridrow < row && (gridcol > 0 && gridcol < col)) {
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          charactergrid[i][j] = value;
        }
      }
    }
  }

  char get_char(int gridrow, int gridcol, char value) {
    if ((gridrow > 0 && gridrow < row) && (gridcol > 0 && gridcol < col)) {
      return charactergrid[gridrow][gridcol];
    }
  }

  bool search_string(int gridrow, int gridcol, string key) {
    int strlen = key.length();
    for (int i = 0; i < gridcol; i++) {
      for (int j = 0; j <= strlen - gridcol; j++) {
        bool found = true;
        for (int k = 0; k < strlen - j; k++) {
          if (charactergrid[i][k - j] != key[k]) {
            found = false;
            break;
          }
        }
      }
    }

    void print_grid() {
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          cout << charactergrid[i][j] << " ";
        }
        cout << "\n";
      }
    }
  };