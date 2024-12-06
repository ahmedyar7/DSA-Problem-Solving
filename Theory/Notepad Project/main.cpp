// main.cpp
#include <conio.h>
#include <graphics.h>

#include "editor.h"

int main() {
  int width = 1280, height = 720;
  initwindow(width, height, "Professional Notepad");

  // setbkcolor(Theme::BACKGROUND);
  cleardevice();

  UIManager uiManager(width, height);
  Editor editor(uiManager);
  char ch;

  while (true) {
    editor.renderText();  // Ensure text is rendered continuously
    delay(20);            // Control refresh rate to avoid flickering

    if (kbhit()) {
      ch = getch();
      if (ch == 0 || ch == 224) {
        ch = getch();
        switch (ch) {
          case 59:  // F5 (Save)
            editor.saveToFile("notepad.txt");
            break;
          case 61:  // F6 (Exit)
            closegraph();
            return 0;
        }
      } else if (ch == 27) {  // ESC (Exit)
        closegraph();
        return 0;
      } else {
        editor.handleInput(ch);  // Handle input and update text
      }
    }
  }

  return 0;
}