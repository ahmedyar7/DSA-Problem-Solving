// ui_components.h
#ifndef UI_COMPONENTS_H
#define UI_COMPONENTS_H

#include <graphics.h>

#include <string>

// Theme class with method-based color getters
class Theme {
 public:
  // Static methods to return colors
  static int Primary() { return COLOR(51, 51, 51); }        // Dark gray
  static int Secondary() { return COLOR(241, 241, 241); }   // Light gray
  static int Accent() { return COLOR(0, 120, 215); }        // Windows blue
  static int TextColor() { return COLOR(33, 33, 33); }      // Almost black
  static int Background() { return COLOR(255, 255, 255); }  // Pure white
};

class UIManager {
 private:
  int width;
  int height;

 public:
  UIManager(int w = 1280, int h = 720) : width(w), height(h) {}

  void drawTitleBar() {
    // Draw gradient background
    for (int i = 0; i < 40; i++) {
      setcolor(COLOR(51, 51, 51 + i));
      line(0, i, width, i);
    }

    // Draw application icon
    setfillstyle(SOLID_FILL, Theme::Accent());
    fillellipse(25, 20, 10, 10);

    // Draw title text
    settextstyle(8, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(45, 12, const_cast<char*>("Professional Notepad"));

    // Draw window controls
    setfillstyle(SOLID_FILL, Theme::Background());
    bar(width - 80, 10, width - 60, 30);  // Minimize
    bar(width - 50, 10, width - 30, 30);  // Maximize
    bar(width - 20, 10, width - 10, 30);  // Close
  }

  void drawStatusBar(const std::string& status, int cursorLine = 1,
                     int cursorCol = 1) {
    // Draw status bar background
    for (int i = height - 40; i < height; i++) {
      setcolor(COLOR(241, 241, 241 - (i - (height - 40)) / 2));
      line(0, i, width, i);
    }

    // Draw status text
    settextstyle(8, HORIZ_DIR, 1);
    setcolor(COLOR(150, 150, 150));
    outtextxy(11, height - 29, const_cast<char*>(status.c_str()));  // Shadow
    setcolor(Theme::TextColor());
    outtextxy(10, height - 30, const_cast<char*>(status.c_str()));  // Main text

    // Draw cursor position
    char posInfo[50];
    sprintf(posInfo, "Ln %d, Col %d", cursorLine, cursorCol);
    outtextxy(width - 100, height - 30, const_cast<char*>(posInfo));
  }

  void drawLineNumbers(int startLine, int endLine) {
    setfillstyle(SOLID_FILL, Theme::Secondary());
    bar(0, 40, 40, height - 40);

    settextstyle(8, HORIZ_DIR, 1);
    setcolor(COLOR(150, 150, 150));

    for (int i = startLine, y = 50; i <= endLine && y < height - 40;
         i++, y += 25) {
      char number[10];
      sprintf(number, "%d", i);
      outtextxy(10, y, number);
    }
  }

  void drawCursor(int x, int y, bool visible) {
    if (visible && (GetTickCount() / 500) % 2) {
      setfillstyle(SOLID_FILL, Theme::Accent());
      bar(x - 1, y, x + 1, y + 20);
    }
  }

  void clearTextArea() {
    setfillstyle(SOLID_FILL, Theme::Background());
    bar(40, 40, width, height - 40);
  }
};

#endif