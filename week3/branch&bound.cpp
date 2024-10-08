#include<bits/stdc++.h>
#define MAX 25
using namespace std;

bool visited[MAX] = {0};  // Keep track of visited nodes (pickup & delivery)
int load = 0;  // Current bus load (number of passengers on the bus)
int n, k;  // n = number of passengers, k = bus capacity
int c[MAX][MAX];  // Distance matrix
int cmin = INT_MAX;  // Minimum travel distance between any two points
int fopt = INT_MAX;  // Optimal (minimal) route length
int x[MAX];  // To store the current path
int f = 0;  // Current cost

// Function to check whether visiting node i is valid
bool UCV(int i) {
    if (i <= n) {
        // For pickup points (1 to n), check if not visited and bus has capacity
        return !visited[i] && load < k;
    } else {
        // For delivery points (n+1 to 2n), check if corresponding pickup is visited
        return !visited[i] && visited[i-n] && load > 0;
    }
}

// Backtracking function to explore possible routes
void Try(int k) {
    for (int i = 1; i <= 2 * n; i++) {  // Start from 1 (pickup point)
        if (UCV(i)) {  // Check if we can visit node i
            // Update load based on pickup or delivery
            if (i <= n) load++;  // Pickup point
            else load--;  // Delivery point

            x[k] = i;  // Assign current point to path
            visited[i] = true;  // Mark as visited
            f += c[x[k - 1]][i];  // Add the distance to cost

            if (k == 2 * n) {  // If all passengers served
                int ftemp = f + c[x[k]][0];  // Add return cost to depot (0)
                if (ftemp < fopt) fopt = ftemp;  // Update optimal cost
            } else {
                // Calculate the optimistic lower bound for the remaining cost
                int g = f + (2 * n - k + 1) * cmin;
                if (g < fopt) Try(k + 1);  // Explore further only if bound is promising
            }

            // Backtrack: Unmark visited, undo changes to load and cost
            visited[i] = false;
            if (i <= n) load--;  // Undo pickup
            else load++;  // Undo delivery
            f -= c[x[k - 1]][i];  // Undo the cost
        }
    }
}

int main() {
    freopen("test.txt", "r", stdin);  // Read from a file, replace if needed
    cin >> n >> k;

    // Read the distance matrix and find the minimum cost between any two distinct points
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j && cmin > c[i][j]) cmin = c[i][j];
        }
    }

    // Initialize starting state
    load = 0;  // No passengers on the bus initially
    x[0] = 0;  // Start from depot (index 0)
    f = 0;  // Initial cost is 0

    // Start backtracking from the first passenger
    Try(1);

    // Output the optimal route length
    cout << fopt << endl;
}
