#include "browser_history.cpp"
#include "browser_history.h"
// Example usage
int main() {
  BrowserHistory browser("leetcode.com");
  browser.visit("google.com");
  browser.visit("faceboosafdfk.com");
  browser.visit("youtube.com");

  cout << browser.back(1) << endl;     // Output: facebook.com
  cout << browser.back(1) << endl;     // Output: google.com
  cout << browser.forward(1) << endl;  // Output: facebook.com

  browser.visit("linkedin.com");
  cout << browser.forward(2) << endl;  // Output: linkedin.com
  cout << browser.back(2) << endl;     // Output: google.com
  cout << browser.back(7) << endl;     // Output: leetcode.com

  return 0;
}
