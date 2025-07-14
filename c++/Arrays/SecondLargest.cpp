#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findSecondLargest(const vector<int>& arr) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int num : arr) {
        if (num > largest) {
            secondLargest = largest; // Update second largest before updating largest
            largest = num;
        } else if (num > secondLargest && num != largest) {
            secondLargest = num;
        }
    }
    // Check if second largest was found
    if (secondLargest == INT_MIN)
        return -1;  // or throw an error / custom message
    return secondLargest;
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    int result = findSecondLargest(arr);
    
    if (result != -1)
        cout << "Second largest element is: " << result << endl;
    else
        cout << "Second largest element doesn't exist." << endl;

    return 0;
}
