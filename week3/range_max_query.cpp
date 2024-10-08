#include <bits/stdc++.h>
#define inf 1000000007
using namespace std;

const int maxN = 10000007; // Maximum number of elements
int a[maxN]; // The input array
int maxVal[4 * maxN]; // Segment tree to store the minimum values

// Build the segment tree
void build(int id, int l, int r) {
    if (l == r) {
        maxVal[id] = a[l]; // Leaf node will hold the array element
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid); // Build the left subtree
    build(2 * id + 1, mid + 1, r); // Build the right subtree
    maxVal[id] = max(maxVal[2 * id], maxVal[2 * id + 1]); // Internal node will hold the minimum of its children
}

// Query the segment tree to find the minimum in the range [u, v]
int getMax(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return INT_MIN; // If the current segment is outside the query range
    if (l >= u && r <= v) return maxVal[id]; // If the current segment is completely inside the query range
    int mid = (l + r) / 2;
    int maxLeft = getMax(2 * id, l, mid, u, v); // Query the left child
    int maxRight = getMax(2 * id + 1, mid + 1, r, u, v); // Query the right child
    return max(maxLeft, maxRight); // Return the minimum of both sides
}
void update(int id, int l, int r, int i, int val){
    if(l > i || r < i) return;
    if (l==r){
        maxVal[id] = val;
        return;
    }
    int mid = (l+r)/2;
    int leftChild = 2*id;
    int rightChild = 2*id +1;
    update(leftChild, l, mid, i, val);
    update(rightChild, mid+1, r, i, val);
    maxVal[id] = max(maxVal[leftChild], maxVal[rightChild]);
}
int main() {

    ios::sync_with_stdio(false); // Faster I/O
    cin.tie(0);
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read the array
    }

    // Build the segment tree
    build(1, 0, n - 1);

    int m;
    cin >> m;
    string cmd;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin>>cmd;
        if(cmd == "get-max"){
            cin >> u >> v; // Read the query
            cout<<getMax(1, 0, n-1, u-1,v-1)<<endl;
        }
        else if(cmd == "update"){
            cin >> u >> v; // Read the query
            update(1,0, n-1, u-1,v);
        }
        ; // Query the minimum in range [u, v]
    }

    return 0;
}
