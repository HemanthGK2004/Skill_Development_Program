#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<unordered_set>

class Solution {
    public:
    vector<int>missingAndReapeating(vector<vector<int>>&grid){
        int n = grid.size();
        int actualSum = 0;
        int expectedSum =0;
        int a , b;
        vector<int>ans;
        unordered_set<int>s;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                actualSum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expectedSum = (n * n *(n*n + 1))/2;
        b = expectedSum + a - actualSum;
        ans.push_back(b);
        return ans;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> grid = {{9,1,7}, {8,9,2}, {3,4,6}}; // Example input
    vector<int> result = solution.missingAndReapeating(grid); // Call the function
    cout << "Repeating: " << result[0]<<"\n" << "Missing :" << result[1] << endl; // Output the result
    return 0; // Return success
}