//Maximize total value without exceeding capacity

#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    
    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            // If current item fits
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]], // take item
                    dp[i - 1][w]                          // skip item
                );
            } else {
                dp[i][w] = dp[i - 1][w]; // cannot take
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;

    cout << "Max Value: " << knapsack(wt, val, wt.size(), W);

    return 0;
}