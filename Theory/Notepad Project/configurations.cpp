#include <conio.h>  // For getch()
#include <graphics.h>

#include <fstream>
#include <iostream>
#include <string>

#include "stack.h"
using namespace std;
struct Command {
  enum Operation { ADD, REMOVE };
  Operation op;
  string text;
};

// Global stack to store commands

void display_menu() {
  cleardevice();

  setbkcolor(LIGHTGRAY);
  setcolor(BLUE);
  settextstyle(10, 0, 3);  // Large font for the header
  outtextxy(50, 30, const_cast<char *>("Ahmed Yar - Notepad - v.1.1"));

  setcolor(BLACK);
  settextstyle(8, 0, 2);  // Medium font for the menu
  outtextxy(100, 150, const_cast<char *>("1. New Text"));
  outtextxy(100, 200, const_cast<char *>("2. Save Text"));
  outtextxy(100, 250, const_cast<char *>("3. Exit"));

  setcolor(DARKGRAY);
  settextstyle(8, 0, 1);  // Footer
  outtextxy(50, 450, const_cast<char *>("Created by Ahmed Yar | v.1.1"));
  outtextxy(50, 480, const_cast<char *>("Use the keyboard to navigate."));
}

void display_text(const string &text) {
  cleardevice();
  setbkcolor(WHITE);
  setcolor(BLACK);
  settextstyle(8, 0, 2);
  outtextxy(50, 50, const_cast<char *>("Current Text:"));

  int y = 100;  // Start position for text display
  for (size_t i = 0; i < text.length(); i += 70) {  // Break text into lines
    string line = text.substr(i, 70);
    outtextxy(100, y, const_cast<char *>(line.c_str()));
    y += 30;  // Move down for the next line
  }
}