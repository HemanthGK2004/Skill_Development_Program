// Merge-intervals.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        vector<int> currentInterval = intervals[0];

        for (const auto& interval : intervals) {
            // If the current interval overlaps with the next one, merge them
            if (interval[0] <= currentInterval[1]) {
                currentInterval[1] = max(currentInterval[1], interval[1]);
            } else {
                // No overlap, add the current interval to the result and update it
                merged.push_back(currentInterval);
                currentInterval = interval;
            }
        }
        // Add the last interval
        merged.push_back(currentInterval);

        return merged;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = solution.mergeIntervals(intervals);

    cout << "Merged Intervals: ";
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0; // Return success
}