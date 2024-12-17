#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findLIS(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);}}}
    return *max_element(dp.begin(), dp.end());}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  }
    vector<int> evenSeq, oddSeq;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            evenSeq.push_back(arr[i]);
        } else {
            oddSeq.push_back(arr[i]);}}
    int evenLIS = findLIS(evenSeq);
    int oddLIS = findLIS(oddSeq);
    cout << max(evenLIS, oddLIS);
    return 0;}
