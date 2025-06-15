#include<iostream>
#include<vector>

using namespace std;
class Solution{
    public:
    bool isPalindrom(int x){
        if((x< 0 )||(x!=0 && x%10==0)){
            return false;
        }
        int reverseHalf = 0;
        while(x > reverseHalf){
            reverseHalf = reverseHalf * 10 + x %10;
            x /= 10;
        }
        return (x == reverseHalf || x == reverseHalf / 10);
    }
};
int main() {
    Solution solution;
    int x = 121; // Example input
    bool result = solution.isPalindrom(x); // Call the function
    cout << "Is palindrome: " << (result ? "true" : "false") << endl; // Output the result
    return 0; // Return success
}
