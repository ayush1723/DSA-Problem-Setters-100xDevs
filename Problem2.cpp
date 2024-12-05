// Problem 1:-> Given an Integer Array. Find the Longest consecutive subsequence in an array.
// Longest consecutive subsequence of array [8, 2, 4, 9, 7] is [7, 8, 9].
// You have to return only the starting and ending element. 

// Example Test Cases:

// Test case 1:                                        Output: 
// N = 13                                                 [8, 12]
// A = [2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6]      The longest consecutive sequence here is [8, 9, 10, 11, 12].
//                                                        So the output is the starting and ending of this sequence: [8, 12].



#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveSequence(vector<int> &A, int n) {

    unordered_map<int, bool> Freq;
    vector<int> Answer;
    int maxTotal=0;

    for(int i=0; i<n; i++) {
        Freq[A[i]] = true;
    }

    for(int i=0; i<n; i++) {
        int x = A[i];
        int max = 0;

        while(Freq.count(x) > 0) {
            x++;
            max++;
        }
        
        if(max > maxTotal) {
            maxTotal = max;

            while(Answer.size() > 0) {
                Answer.pop_back();
            }

            if(max == 1) {
                Answer.push_back(A[i]);
            } 
            else {
                Answer.push_back(A[i]);
                Answer.push_back(x-1);
            }
        }
    }
    return Answer;
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

    vector<int> Answer = longestConsecutiveSequence(A, n);

    for(int i = 0; i < Answer.size(); i++) {
        cout << Answer[i] << " ";
    }

    cout << "\n";
}