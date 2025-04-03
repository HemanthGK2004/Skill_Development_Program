#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to check if person 'a' knows person 'b'
bool knows(vector<vector<int>> &M, int a, int b) {
    return M[a][b] == 1;
}

// Function to find the celebrity
int findCelebrity(vector<vector<int>> &M, int n) {
    stack<int> s;

    // Step 1: Push all people into the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Find a potential celebrity
    while (s.size() > 1) {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        if (knows(M, A, B)) {
            // A knows B → A is not a celebrity
            s.push(B);
        } else {
            // A does not know B → B is not a celebrity
            s.push(A);
        }
    }

    int candidate = s.top();
    
    // Step 3: Verify if the candidate is a real celebrity
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            // Candidate must be known by everyone & should not know anyone
            if (knows(M, candidate, i) || !knows(M, i, candidate)) {
                return -1; // No celebrity found
            }
        }
    }

    return candidate;
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = M.size();
    int celebrity = findCelebrity(M, n);

    if (celebrity == -1)
        cout << "No celebrity found" << endl;
    else
        cout << "Celebrity is person " << celebrity << endl;

    return 0;
}
