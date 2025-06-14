#include<iostream>
#include<unordered_map>
#include<string>
#include<cmath>
using namespace std;
class Solution {
    public:
    int romanToInt(string s){
        unordered_map<char,int>roman={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int total = 0;
        int n = s.size();
        for(int i =0;i<n;i++){
            if( i < n-1 && roman[s[i]]<roman[s[i+1]]){
                total -= roman[s[i]];
            }
            else{
                total += roman[s[i]];
            }
        }
        return total;
    }
};
int main() {
    Solution solution;
    string s = "MMM"; // Example input
    int result = solution.romanToInt(s); // Call the function
    cout << "Integer value: " << result << endl; // Output the result
    return 0; // Return success
}