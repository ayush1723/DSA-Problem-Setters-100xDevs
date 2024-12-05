// Problem 1:-> Given an Integer Array. Find the pair of element in the array which sum to 0.

// Example Test Cases:

// Test case 1:              Output: 
// N = 5                     2
// A = [2, 1, -2, 2, 3]      (2, -2) and (-2, 2) will reselt to 0.

// Test Case 2:              Output:
// N = 5                     10
// A = [0, 0, 0, 0, 0]       All are (0, 0).


#include <bits/stdc++.h>
using namespace std;

int pairSum(vector<int> &A, int n) {
    map<int, int> frequency;
    int pairCount = 0;

    for(int i = 0; i < n; ++i) {
        int complement = -A[i];

        if(frequency.find(complement) != frequency.end()) {
            pairCount += frequency[complement];
        }

        ++frequency[A[i]];
    }
    return pairCount;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << pairSum(A, n) << "\n";
}