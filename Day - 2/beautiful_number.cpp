// Beautiful Number
// ================
// A beautiful number is a number that is equal to the sum of its digits multiplied by the number of digits. For example, 123 is a beautiful number because 1+2+3 = 6 and 6*3 = 18. Write a program that reads a number and determines whether it is a beautiful number or not.
#include <iostream>
#include <string>
using namespace std;
int main() {
    int number, sum = 0, digits = 0;
    cout << "Enter a number: ";
    cin >> number;
    string str = to_string(number);
    for (int i = 0; i < str.length(); i++) {
        sum += str[i] - '0';
        digits++;
    }
    if (sum * digits == number) {
        cout << "Beautiful Number" << endl;
    } else {
        cout << "Not a Beautiful Number" << endl;
    }
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
// Input: 123
// Output: Beautiful Number
// Input: 1234
// Output: Not a Beautiful Number