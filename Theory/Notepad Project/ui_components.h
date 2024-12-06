#ifndef UI_COMPONENTS_H
#define UI_COMPONENTS_H

using namespace std;
#include <graphics.h>

#include <string>

// Theme class with method-based color getters
class Theme {
 public:
  static int Primary() { return COLOR(51, 51, 51); }        // Dark gray
  static int Secondary() { return COLOR(241, 241, 241); }   // Light gray
  static int Accent() { return COLOR(0, 120, 215); }        // Windows blue
  static int TextColor() { return COLOR(33, 33, 33); }      // Almost black
  static int Background() { return COLOR(255, 255, 255); }  // Pure white
  static int Shadow() { return COLOR(150, 150, 150); }      // Shadow color
};

class UIManager {
 private:
  int width;
  int height;

 public:
  UIManager(int w = 1280, int h = 720) : width(w), height(h) {}

  void drawTitleBar() {
    for (int i = 0; i < 40; i++) {
      setcolor(COLOR(51, 51, 51 + i));  // Smooth gradient effect
      line(0, i, width, i);
    }

    setfillstyle(SOLID_FILL, Theme::Accent());
    fillellipse(25, 20, 12, 12);  // Larger app icon

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    setbkcolor(Theme::Primary());
    outtextxy(45, 10, "Professional Notepad");

    drawWindowControls();  // Modular function for window buttons
  }

  void drawStatusBar(const std::string& status, int cursorLine = 1,
                     int cursorCol = 1) {
    // Draw a soft gradient background for the status bar
    for (int i = height - 40; i < height; i++) {
      setcolor(
          COLOR(241, 241, 241 - (i - (height - 40)) / 2));  // Smooth gradient
      line(0, i, width, i);
    }

    // Draw shadowed status text for better visibility
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    setcolor(Theme::Shadow());
    setbkcolor(Theme::Background());  // Transparent background
    outtextxy(11, height - 29, const_cast<char*>(status.c_str()));  // Shadow

    // Main status text
    setcolor(Theme::TextColor());
    outtextxy(10, height - 30, const_cast<char*>(status.c_str()));

    // Cursor position in the status bar (better font size)
    char posInfo[50];
    sprintf(posInfo, "Ln %d, Col %d", cursorLine, cursorCol);
    setcolor(Theme::TextColor());
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    outtextxy(width - 120, height - 30, const_cast<char*>(posInfo));
  }

  void drawLineNumbers(int startLine, int endLine) {
    setfillstyle(SOLID_FILL, Theme::Secondary());
    bar(0, 40, 40, height - 40);  // Line number background

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    setcolor(COLOR(150, 150, 150));  // Light gray for line numbers

    for (int i = startLine, y = 50; i <= endLine && y < height - 40;
         i++, y += 25) {
      char number[10];
      sprintf(number, "%d", i);
      outtextxy(10, y, number);  // Line number at left side
    }
  }

  void drawCursor(int x, int y, bool atEnd) {
    // Make sure the cursor is visible at the current position
    if (!atEnd) {
      setcolor(RED);  // Set a visible color for the cursor (e.g., red)
      rectangle(x, y, x + 2, y + 16);  // Draw a vertical line for the cursor
    }
  }

  void UIManager::clearTextArea() {
    // Set background color to a neutral color (e.g., white or light gray)
    setbkcolor(WHITE);  // Adjust to your preference
    cleardevice();  // Clear the graphics window, but ensure this is done only
                    // in necessary areas
  }

  void drawTextArea() {
    setfillstyle(SOLID_FILL,
                 LIGHTGRAY);  // Set light background for the text area
    bar(50, 50, 1240, 670);   // Draw the text area with a solid fill
    setcolor(BLACK);          // Text color should be set separately
  }

 private:
  void drawWindowControls() {
    // Simulate window control buttons (close, minimize, maximize)
    setfillstyle(SOLID_FILL, Theme::Background());
    bar(width - 80, 10, width - 60, 30);  // Minimize button
    bar(width - 50, 10, width - 30, 30);  // Maximize button
    bar(width - 20, 10, width - 10, 30);  // Close button
  }
};

#endif
