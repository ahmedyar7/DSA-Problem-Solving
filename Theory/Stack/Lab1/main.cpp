#include <climits>

#include "stack.h"
using namespace std;

int main() {
  char exp1[] = "1 + 2 * (3 / 4)";
  char exp2[] = "1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10) – 11 + (12*8)] + 14";
  char exp3[] =
      "1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10)} – 11 + (12*8) / {13 +13}] + "
      "14";

  Stack st(100);

  if (st.valid_parenthesis(exp1)) {
    cout << "This expression is correct.\n";
  }

  if (st.valid_parenthesis(exp2)) {
    cout << "This expression is correct\n";
  } else {
    cout << "This expression is NOT correct e.g. error at character # 10. ‘{‘- "
            "not closed.\n";
  }

  if (st.valid_parenthesis(exp3)) {
    cout << "This expression is correct.\n";
  }
}