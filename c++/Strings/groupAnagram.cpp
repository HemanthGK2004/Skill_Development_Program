#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    vector<vector<string>> groupAnagrams(vector<string>&strs){
        vector<vector<string>>result;
        unordered_map<string, vector<string>> map;
        for(string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }
        for(auto it : map){
            result.push_back(it.second);
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs); // Call the function
    cout << "Result: " << endl; // Output the result
    for(auto group : result){
        for(string s : group){
            cout << s << " ";
        }
        cout << endl;
    }
    return 0; // Return success
}