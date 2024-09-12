#include <iostream>
using namespace std;

class CharGrid {
 private:
  char **grid;  // Pointer-to-Pointer for 2D array
  int row, col;

 public:
  // CONSTRUCTOR
  CharGrid(int row, int col) {
    this->row = row;
    this->col = col;

    grid = new char *[row];

    for (int i = 0; i < row; i++) {
      grid[i] = new char[col];
      for (int j = 0; j < col; j++) {
        grid[i][j] = '-';
      }
    }
  }

  // DESTRUCTOR
  ~CharGrid() {
    for (int i = 0; i < row; i++) {
      delete[] grid[i];
    }
    delete[] grid;
  }

  // METHODS
  void set_char(int set_row, int set_cols, char value) {
    if ((set_row >= 0 && set_row < row) && (set_cols >= 0 && set_cols < col)) {
      grid[set_row][set_cols] = value;
    } else {
      cout << "Invalid Postion in the Grid" << endl;
    }
  }

  char get_char(int get_row, int get_col) {
    if ((get_row >= 0 && get_row < row) && (get_col >= 0 && get_col < col)) {
      return grid[get_row][get_col];
    } else {
      cout << "No Char found on the Provided Indices \n";
    }
  }

  /*
    EXPLAINATION OF (search_string) FUNCTION:

      1. str_len = Store the length of string we are trying to find.
      2. Outer loop will move through each row.

      3. Inner loop will check for all starting position in the grid
        if str <= col-str_len this means that if string is less or equal then
        the total number of coloumn then the string might exits otherwise not.

    STRING COMPARISON:

      - This will compare character in string and char in grid.
      - The k itterate over the string length's.
      - grid[i][j+k] this access the chars from valid starting position(j) till
        string's length(k).
      - If missmatched is found then return false.
  */

  bool search_string(string &str) {
    int str_len = str.length();

    // Outer loop itterate over the rows of the grid
    for (int i = 0; i < row; i++) {
      // Inner loop : Itter over possible starting position
      for (int j = 0; j <= col - str_len; j++) {
        // String Comparison:
        bool found = true;
        for (int k = 0; k < str_len; k++) {
          if (grid[i][j + k] != str[k]) {
            found = false;
            break;
          }
        }
      }
    }
  }

  void print_grid() {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cout << grid[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
};

void main_menu() {
  cout << "\n\n-------> WELCOME THE CHARACTER-GRID <---------\n\n";
  cout << "1. SET CHARACTERS\n";
  cout << "2. GET CHARACTERS\n";
  cout << "3. PRINT CHARACTER GRID\n";
  cout << "4. SEARCH STRING\n\n\n";
}

int main() {
  cout << "Enter the row and column: ";
  int row, col;
  cin >> row >> col;

  CharGrid char_grid(row, col);
  int option;

  while (true) {
    main_menu();
    cin >> option;

    if (option == 1) {
      int row, col;
      char value;
      cout << "Enter row: ";
      cin >> row;
      cout << "Enter col: ";
      cin >> col;
      cout << "Enter Value: ";
      cin >> value;

      char_grid.set_char(row, col, value);
    }

    else if (option == 2) {
      int row, col;
      cout << "Enter row: ";
      cin >> row;
      cout << "Enter col: ";
      cin >> col;

      char value = char_grid.get_char(row, col);
      cout << "Value: " << value << "\n";
    }

    else if (option == 3) {
      cout << "Printing the Character Grid\n";
      char_grid.print_grid();
      break;
    } else if (option == 4) {
      cout << "Enter the String: ";
      string str;
      cin >> str;

      if (char_grid.search_string(str)) {
        cout << "String Found";
      } else {
        cout << "String not found " << endl;
      }
    }

    else {
      cout << "Invalid Input\n";
    }
  }
}