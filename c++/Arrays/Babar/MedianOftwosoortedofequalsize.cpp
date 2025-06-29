// Median of Two Sorted Arrays of Equal Size
// Given two sorted arrays of equal size, the task is to find their median.

#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    
    if (n != m) {
        throw invalid_argument("Arrays must be of equal size");
    }

    int i = 0, j = 0;
    int count;
    double median = 0.0;

    for (count = 0; count < n + m; count++) {
        if (i < n && (j >= m || nums1[i] <= nums2[j])) {
            if (count == (n + m - 1) / 2) {
                median += nums1[i];
            }
            i++;
        } else {
            if (count == (n + m - 1) / 2) {
                median += nums2[j];
            }
            j++;
        }
    }

    if ((n + m) % 2 == 0) {
        median /= 2.0; // If total number of elements is even, return average of two middle elements
    }

    return median;
}

int main() {
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {2, 4, 6, 8};

    try {
        double median = findMedianSortedArrays(nums1, nums2);
        cout << "Median of the two sorted arrays: " << median << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0; // Return success
}