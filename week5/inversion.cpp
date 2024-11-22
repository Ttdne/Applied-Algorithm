#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> temp(n); // Temporary array for merging

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = merge_sort_and_count(arr, temp, 0, n - 1);
    cout << result << endl;

    return 0;
}
