#include <iostream>
#include <vector>
#include <string>
using namespace std;

string A = "AGGTAB";
string B = "GXTXAYB";

// Memoization table
vector<vector<int> > memo;
string lcsResult = "";

// LCS length function with memoization
int LCS(int i, int j) {
    if (i >= A.length() || j >= B.length()) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    if (A[i] == B[j]) {
        memo[i][j] = 1 + LCS(i + 1, j + 1);
    } else {
        memo[i][j] = max(LCS(i + 1, j), LCS(i, j + 1));
    }
    return memo[i][j];
}

// Construct the actual LCS string
string construct_LCS(int i, int j) {
    if (i >= A.length() || j >= B.length()) return "";

    if (A[i] == B[j]) {
        return A[i] + construct_LCS(i + 1, j + 1);
    }

    if (memo[i + 1][j] >= memo[i][j + 1]) {
        return construct_LCS(i + 1, j);
    } else {
        return construct_LCS(i, j + 1);
    }
}

int main() {
    int n = A.length();
    int m = B.length();

    // Initialize memo table with -1
    memo = vector<vector<int> >(n + 1, vector<int>(m + 1, -1));

    int length = LCS(0, 0);
    string lcsString = construct_LCS(0, 0);

    cout << "Longest Common Subsequence is of length " << length << endl;
    cout << "Longest Common Subsequence: " << lcsString << endl;

    return 0;
}
