#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    int rangeAnd(int left , int right ){
        int shift = 0;
        while(left < right){
            left >>=1;
            right >>=1;
            shift++;
        }
        return left << shift;
    }
};
int main(){
    Solution solution;
    int left = 5, right = 7; // Example input
    int result = solution.rangeAnd(left, right); // Call the function
    cout << "Range AND: " << result << endl; // Output the result
    return 0; // Return success
}