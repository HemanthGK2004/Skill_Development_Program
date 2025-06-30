#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int peakIndex(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] > arr[mid + 1]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {0, 2, 3, 4, 5, 4, 3, 2, 1}; // Example mountain array
    int peakIndex = solution.peakIndex(arr); // Call the function
    cout << "Peak index: " << peakIndex << endl; // Output the result
    return 0;
}
