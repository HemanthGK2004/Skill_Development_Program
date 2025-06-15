// prefix to infix conversion
#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
// Function to convert prefix expression to infix expression
string prefixToInfix(string prefix) {
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) { // If the character is an operand, push it to the stack
            s.push(string(1, c));
        } else if (isOperator(c)) { // If the character is an operator
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string expr = "(" + op1 + c + op2 + ")";
            s.push(expr);
        }
    }
    return s.top(); // The final expression is at the top of the stack
}
int main() {
    string prefix = "*-A/BC-/AKL";
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    return 0;
}