#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
    public:
    int frogClimb(vector<int>& heights){
        int n = heights.size();
        int prev1 = 0 , prev2 = 0, curr;
        for(int i =1;i<=n;i++){
            int jumPone = prev1 + abs(heights[i] - heights[i-1]);
            int jumpTwo = INT_MAX;
            if(i > 1) {
                jumpTwo = prev2 + abs(heights[i] - heights[i-2]);
            }
            curr = min(jumPone, jumpTwo);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1; // Return the minimum cost to reach the top
    }
};
int main(){
    Solution solution;
    vector<int> heights = {10, 30, 40, 20, 50};
    int result = solution.frogClimb(heights); // Call the function
    cout << "Minimum cost to reach the top: " << result << endl; // Output the result
    return 0; // Return success
}