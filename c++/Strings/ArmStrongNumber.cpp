#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
    public:
    bool isArmStrong(int n){
        int copyOfN = n;
        int sum = 0;
        while(n!=0){
            int digit = n % 10;
            sum+= digit * digit * digit;
            n /= 10;
        }
        return sum == copyOfN;
    }
};
int main() {
    Solution solution;
    int n = 153; // Example number
    bool result = solution.isArmStrong(n); // Call the function
    cout << "Result: " << (result ? "true" : "false") << endl; // Output the result
    return 0; // Return success
}