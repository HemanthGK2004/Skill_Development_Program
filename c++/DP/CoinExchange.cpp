#include<iostream>
using namespace std;
#include<vector>

class Solution {
    public:
    int coinExchange(vector<int>&coins,int amount){
        vector<int>dp(amount+1,amount+1);
        dp[0] = 0;
        for(int coin:coins){
            for(int i = coin;i<=amount;i++){
                dp[i] = min(dp[i], dp[i-coin] + 1); // Update dp[i] with the minimum coins needed
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount]; // If no solution, return -1
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5}; // Example input
    int amount = 11; // Example amount
    int result = solution.coinExchange(coins, amount); // Call the function
    cout << "Minimum coins needed: " << result << endl; // Output the result
    return 0; // Return success
}