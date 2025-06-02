#include <iostream>
#include <vector>
#include <cstdint> // Needed for uint32_t

using namespace std;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t result =0;
            for(int i = 0 ;i<32;i++){
                int bit = (n & 1);
                result  = (result<<1)|bit;
                n>>=1;
            }
            return result;
        }
    };

int main() {
    Solution solution;
    uint32_t n = 43261596;
    uint32_t result = solution.reverseBits(n); // Call the function
    cout << "Reversed bits: " << result << endl; // Output the result
    // Convert result to binary string for better visualization

    return 0;
}
