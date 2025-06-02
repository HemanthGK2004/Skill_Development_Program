#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
class  Solution{
    public:
    int compression(vector<char>&chars){
        int n = chars.size();
        int idx = 0;
        for(int i =0;i<n;i++){
            int count = 0;
            char ch = chars[i];
            while(i < n && chars[i] == ch){
                count++;
                i++;
            }
            if(count==1){
                chars[idx++] = ch;
            }
            else{
                chars[idx++]= ch;
                string digit = to_string(count);
                for(char c : digit){
                    chars[idx++] = c;
                }
            }
            i--;
        }
        return idx;
    }
};
int main() {
    Solution solution;
    vector<char> cha = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int result = solution.compression(cha); // Call the function
    cout << "Result: " << result << endl; // Output the result
    return 0; // Return success
}