#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
    public:
    string longestCommonPrefix(vector<string>&strs){
        int n = strs.size();
        if(strs.empty()){
            return "";
        }
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[n - 1];
        int i =0;
        while(i < first.size() && first[i] == last[i]){
            i++;
        }
        return first.substr(0, i);
    }
};
int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = solution.longestCommonPrefix(strs); // Call the function
    cout << "Result: " << result << endl; // Output the result
    return 0; // Return success
}