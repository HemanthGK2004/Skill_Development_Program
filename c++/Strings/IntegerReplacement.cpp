#include<iostream>
using namespace std;
// Function to reverse a number
class Solution{
    public:
    int replacement(int n){
        int count =0;
        while(n>1){
            if(n%2==0){
                n/=2;
            }
            else{
                if((n==3)||(n&2)==0){
                    n-=1;
                }
                else{
                    n+=1;
                }
            }
            count++;
        }
        return count;
    }
};
int main() {
    Solution solution;
    int number = 8; // Example input
    int result = solution.replacement(number); // Call the function
    cout << "Number of replacements: " << result << endl; // Output the result
    return 0; // Return success
}