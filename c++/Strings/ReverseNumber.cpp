#include<iostream>
using namespace std;
class Solution {
public:
    int reverseNumber(int n) {
        int reversed = 0;
        while (n!=0) {
            int digit = n % 10; 
            // Get the last digit
            if(reversed > INT_MAX /10 || reversed < INT_MIN / 10) {
                return 0; // Handle overflow
            }
            reversed = reversed * 10 + digit; // Append it to the reversed number
            n /= 10; // Remove the last digit from n
        }
        return reversed;
    }
};
int main() {
    Solution solution;
    int number = -12345; // Example input
    int reversedNumber = solution.reverseNumber(number); // Call the function
    cout << "Reversed number: " << reversedNumber << endl; // Output the result
    return 0; // Return success
}