#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a , int b){
    while((a >0) && (b > 0)){
        if(a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    if(a == 0){
        return b;
    }
    else{
        return a;
    }
};
int main(){
    int a = 56, b = 98; // Example input
    int result = gcd(a, b); // Call the function
    cout << "GCD of " << a << " and " << b << " is: " << result << endl; // Output the result
    return 0; // Return success
}