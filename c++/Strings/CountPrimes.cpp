#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
class Solution{
    public:
    int countPrimes(int n){
        if(n<= 2){
            return 0;
        }
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i < n; i++){
            if(isPrime[i]){
                for(int j = i * i; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        return count(isPrime.begin(), isPrime.end(), true);
    }
};
int main() {
    Solution solution;
    int n = 10;
    int result = solution.countPrimes(n); // Call the function
    cout << "Result: " << result << endl; // Output the result
    return 0; // Return success
}