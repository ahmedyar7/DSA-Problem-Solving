

class Solution {
 private:
  int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
      fact *= i;
    }
    return fact;
  }

  // Function to calculate the nth Catalan number
  int catalan(int n) {
    // Using the formula C_n = (2n)! / ((n+1)! * n!)
    int fact_2n = factorial(2 * n);
    int fact_n = factorial(n);
    int fact_n_plus_1 = factorial(n + 1);

    return fact_2n / (fact_n * fact_n_plus_1);
  }

 public:
  int numTrees(int n) { return catalan(n); }
};