#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int maximumProfit(vector<int>&prices){
        int maxSum = 0;
        int bestBuy = prices[0];
        for(int i =1; i<prices.size();i++){
            if(prices[i]>maxSum){
                maxSum = max(maxSum, prices[i]-bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxSum;
    }
};
int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input
    int result = solution.maximumProfit(prices); // Call the function
    cout << "Maximum profit: " << result << endl; // Output the result
    return 0; // Return success
}