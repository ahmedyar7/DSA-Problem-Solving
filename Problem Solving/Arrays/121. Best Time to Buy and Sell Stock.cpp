#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minimum_cost = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) {
      int cost = prices[i] - minimum_cost;
      cost = min(minimum_cost, prices[i]);
      profit = max(cost, profit);
    }

    return profit;
  }
};