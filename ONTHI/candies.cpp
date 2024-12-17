#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // DP array to store the number of ways to distribute candies
    vector<int> dp(K + 1, 0);
    dp[0] = 1; // There's 1 way to give 0 candies

    // Process each child
    for (int i = 0; i < N; i++) {
        // Temporary array to store the new DP values
        vector<int> new_dp(K + 1, 0);

        for (int j = 0; j <= K; j++) {
            if (dp[j] != 0) {
                // The current child can receive candies from 0 to a[i]
                for (int x = 0; x <= a[i] && j + x <= K; x++) {
                    new_dp[j + x] = (new_dp[j + x] + dp[j]) % MOD;
                }
            }
        }

        // Update dp with the new values
        dp = new_dp;
    }

    // The result is the number of ways to distribute exactly K candies
    cout << dp[K] << endl;
    return 0;
}
