#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
    public:
    bool checkInclusion(string s1 , string s2){
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int>freqS1(26,0);
        vector<int>freqS2(26,0);
        for(char c : s1){
            freqS1[c - 'a']++;
        }

        int left = 0;
        int right = 0;
        while(right < s1.size()){
            freqS2[s2[right] - 'a']++;

            if((right - left + 1 )>s1.size()){
                freqS2[s2[left] - 'a']--;
                left++;
            }
            if(freqS1 == freqS2){
                return true;
            }
            right++;
        }
        return false;
    }
};
int main() {
    Solution solution;
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool result = solution.checkInclusion(s1, s2); // Call the function
    cout << "Result: " << (result ? "true" : "false") << endl; // Output the result
    return 0; // Return success
}