#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, L1, L2;
    cin >> n >> L1 >> L2;

    vector<int> a(n + 1);  // Gold amounts (1-indexed)
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);  // DP array to store the max gold up to warehouse i
    deque<int> q;  // Deque to store indices of the DP array for efficient range max calculation

    for (int i = 1; i <= n; ++i) {
        // Remove indices from the deque that are out of the range [i - L2, i - L1]
        while (!q.empty() && q.front() < i - L2) {
            q.pop_front();
        }

        // If the deque is not empty, the front element gives us the best DP value in range [i - L2, i - L1]
        if (!q.empty()) {
            dp[i] = dp[q.front()] + a[i];
        } else {
            dp[i] = a[i];  // If no valid previous warehouse, just take the gold of the current warehouse
        }

        // Maintain the deque: Remove elements from the back if their dp value is less than dp[i]
        while (!q.empty() && dp[q.back()] <= dp[i]) {
            q.pop_back();
        }

        // Add current index to the deque
        q.push_back(i);
    }

    // The result is the maximum value in the dp array
    cout << *max_element(dp.begin() + 1, dp.end()) << endl;

    return 0;
}
