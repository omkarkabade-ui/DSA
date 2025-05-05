#include <bits/stdc++.h>
using namespace std;

// Function to calculate sum of frequencies from i to j
int sum(int frequency[], int i, int j) {
    int s = 0;
    for (int x = i; x <= j; x++)
        s += frequency[x];
    return s;
}

// Function to find the optimal cost of the binary search tree
int optimalSearchTree(int keys[], int frequency[], int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill diagonal (when only one key is in the BST)
    for (int i = 0; i < n; i++)
        dp[i][i] = frequency[i];

    // Consider chains of length L (from 2 to n)
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            int frequencySum = sum(frequency, i, j);

            // Try making each key in the range [i, j] the root
            for (int r = i; r <= j; r++) {
                int cost = ((r > i) ? dp[i][r - 1] : 0) + ((r < j) ? dp[r + 1][j] : 0);
                dp[i][j] = min(dp[i][j], cost + frequencySum);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;

    // Taking input from the user
    cout << "Enter the number of keys: ";
    cin >> n;

    int keys[n], frequency[n];

    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "Enter the frequencies for the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> frequency[i];
    }

    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, frequency, n) << endl;

    return 0;
}
