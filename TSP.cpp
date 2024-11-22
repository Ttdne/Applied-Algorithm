#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int INF = 1e9;

// Input variables
int n;
int C[N][N];

// Memoization table
int mem[N][1 << N];

// Trace table to reconstruct the path
int nextCity[N][1 << N];

// TSP function using dynamic programming with bitmask
int TSP(int i, int S) {
    // Base case: All cities visited, return to city 1
    if (S == (1 << n) - 1) {
        return C[i][0]; // Cost to return to the starting city
    }

    // If already computed, return the result
    if (mem[i][S] != -1) return mem[i][S];

    int res = INF;

    // Try visiting every city j not yet visited
    for (int j = 0; j < n; j++) {
        if (S & (1 << j)) continue; // Skip if city j is already visited
        int temp = C[i][j] + TSP(j, S | (1 << j));
        if (temp < res) {
            res = temp;
            nextCity[i][S] = j; // Store the next city for path reconstruction
        }
    }

    return mem[i][S] = res; // Store the result in memoization table
}

// Function to reconstruct and print the optimal path
void tracePath() {
    int S = 1; // Start with only city 0 visited
    int currentCity = 0;

    cout << 1; // City 1 (0-indexed as city 0)
    while (S != (1 << n) - 1) {
        int next = nextCity[currentCity][S];
        cout << " " << next + 1; // Convert back to 1-based indexing
        currentCity = next;
        S |= (1 << currentCity); // Mark the next city as visited
    }
    cout << endl; // Return to the starting city
}

int main() {
    // Input the number of cities
    cin >> n;

    // Input the distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> C[i][j];
        }
    }

    // Initialize memoization and trace tables with -1
    memset(mem, -1, sizeof(mem));
    memset(nextCity, -1, sizeof(nextCity));

    // Solve TSP starting from city 0 with only city 0 visited
    int result = TSP(0, 1);

    // Output the result
    cout<< result << endl;

    // Trace and print the optimal path
    tracePath();

    return 0;
}
