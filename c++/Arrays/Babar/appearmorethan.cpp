#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> appearMoreThanNbyK(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int n = arr.size();
        vector<int> result;
        for(int num : arr) {
            freq[num]++;
        }
        for(auto& pair : freq) {
            if(pair.second > n / k) {
                result.push_back(pair.first);
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;

    vector<int> result = sol.appearMoreThanNbyK(arr, k);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
