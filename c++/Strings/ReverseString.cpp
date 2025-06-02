#include<iostream>
#include<string>
using namespace std;
class Solution{
    public:
    string reveseString(string str){
        int n = str.length();
        int start = 0;
        int end = n - 1;
        while(start<end){
            swap(str[start],str[end]);
            start++;
            end--;
        }
        return str;
    }
};
int main() {
    Solution solution;
    string str = "Hello, World!"; // Example input
    string result = solution.reveseString(str); // Call the function
    cout << "Reversed string: " << result << endl; // Output the result
    return 0; // Return success
}