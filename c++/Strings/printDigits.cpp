#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class solution{
    public:
    void printDigits(int n){
        if(n < 0){
            cout << "Negative number" << endl;
            return;
        }
        if(n == 0){
            cout << "0" << endl;
            return;
        }
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            sum += digit;

            n /= 10;
        }
        cout << "Sum of digits: " << sum << endl;
    }
};
int main() {
    solution sol;
    int n = 12345;
    sol.printDigits(n); // Call the function
    return 0; // Return success
}