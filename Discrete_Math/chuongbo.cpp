#include<bits/stdc++.h>
#define MAX 300008
#define ll long long
using namespace std;
ll n, m;   // n: number of nodes, m: number of edges
ll s, t;   // s: the index of source node, t: the index of sink node
vector<vector<ll>> capG;    // Original graph capacities
vector<vector<ll>> capRG;   // Residual graph capacities
ll visited[MAX];            // Array to mark visited nodes
ll pred[MAX];               // Array to store predecessors on augmenting paths
queue<ll> Q;                // Queue for BFS

void input(){
    cin>>n>>m;
    capG.resize(n+1, vector<ll>(n+1, 0));
    capRG.resize(n+1, vector<ll>(n+1, 0));
    ll u, v, c;
    for(ll i=1; i<=m; i++){
        cin>>u>>v>>c;
        capG[u][v] = c;
        capG[v][u] = c;
    }
}

bool BFS(ll s, ll t) {
    memset(visited, 0, sizeof(visited));  // Reset visited array
    while (!Q.empty()) Q.pop();  // Clear the queue before each BFS
    Q.push(s);
    visited[s] = 1;
    pred[s] = -1;  // No predecessor for the source

    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (ll i = 1; i <= n; i++) {
            // If not visited and residual capacity exists
            if (visited[i] == 0 && capRG[u][i] > 0) {
                pred[i] = u;
                if (i == t) {
                    return true;  // Found augmenting path
                }
                Q.push(i);
                visited[i] = 1;
            }
        }
    }
    return false;  // No augmenting path found
}

ll EK(ll s, ll t) {
    // Reset residual graph to original graph before each query
    for (ll u = 1; u <= n; u++) {
        for (ll v = 1; v <= n; v++) {
            capRG[u][v] = capG[u][v];
        }
    }

    ll max_flow = 0;  // Initial maximum flow is 0

    while (BFS(s, t)) {
        ll capP = LLONG_MAX;  // Minimum residual capacity on the augmenting path

        // Find the minimum capacity along the augmenting path
        for (ll v = t; v != s; v = pred[v]) {
            ll u = pred[v];
            capP = min(capP, capRG[u][v]);
        }

        // Update residual graph and flow
        for (ll v = t; v != s; v = pred[v]) {
            ll u = pred[v];
            capRG[u][v] -= capP;  // Decrease forward capacity
            capRG[v][u] += capP;  // Increase backward capacity
        }

        max_flow += capP;  // Add the flow to the total max flow
    }

    return max_flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    ll num;
    cin>>num;
    while (num--) {
        ll s, t;
        cin>>s>>t;
        cout << EK(s, t) << endl;
    }
    return 0;
}
