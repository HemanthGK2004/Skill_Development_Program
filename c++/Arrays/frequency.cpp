#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
class Solution {
public:
    string frequencyOfCharacters(string s) {
        vector<int> freq(26, 0);
        for(char c :s){
            freq[c - 'a']++;
        }
        string result = "";
        for(int i = 0; i < 26; i++) {
            if(freq[i]>1) {
                result+= (char)(i + 'a'); // Append character
                result += " ";
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "bababc"; // Example input
    string result = solution.frequencyOfCharacters(s); // Call the function
    cout << "Frequency of characters: " << result << endl; // Output the result
    return 0; // Return success
}