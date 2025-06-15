// Ascending Order's Program
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    string str = to_string(number);
    sort(str.begin(), str.end());
    cout << "Ascending Order: " << str << endl;
    return 0;
}
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Input: 123
// Output: Ascending Order: 123
// Input: 1234
// Output: Ascending Order: 1234