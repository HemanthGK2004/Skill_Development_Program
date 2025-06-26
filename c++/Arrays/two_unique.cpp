#include <vector>
using namespace std;
#include <iostream>

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int xor_all = 0;
        for(int num:arr){
            xor_all^=num;
        }
        int diff_bit = xor_all & -xor_all;
        int x = 0,y=0;
        for(int num:arr){
            if(num & diff_bit)
                x^=num;
            else
                y^=num;
        }
        if(x<y)return {x,y};
        return {y,x};
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 1, 3, 2, 5}; // Example input
    vector<int> result = solution.singleNum(arr); // Call the function
    // Output the result
    for(int num: result) {
        cout << num << " ";
    }
    cout << endl; // Print a newline
    return 0; // Return success
}
// This code finds two unique numbers in an array where all other numbers appear twice.
// It uses XOR to find the unique numbers and prints them in ascending order.