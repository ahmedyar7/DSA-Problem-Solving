#include <conio.h>
#include <graphics.h>

#include <iostream>

using namespace std;

int main() {
  // Initialize the graphics system
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");  // Initialize graphics mode

  // Your graphics code here
  setcolor(WHITE);                // Set the color for drawing
  rectangle(100, 100, 400, 300);  // Draw a rectangle

  setcolor(YELLOW);
  line(100, 100, 400, 300);  // Draw a line

  outtextxy(150, 150, "Hello, Graphics!");  // Display text

  // Wait for a key press before closing
  getch();

  // Close the graphics mode
  closegraph();

  return 0;
}
