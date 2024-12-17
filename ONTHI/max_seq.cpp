#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
using namespace std;

ll n;
ll a[MAX];
ll f[MAX];

int main() {
    cin >> n;
    ll res = LLONG_MIN;  // Khởi tạo giá trị res với LLONG_MIN để kiểm tra khi không có dãy con hợp lệ

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    f[0] = 0;  // Khởi tạo tổng dãy con ban đầu là 0 (trước phần tử đầu tiên)

    for (ll i = 1; i <= n; i++) {
        // Cập nhật tổng dãy con hiện tại
        f[i] = max(f[i-1] + a[i], a[i]);

        // Kiểm tra nếu tổng dãy con hiện tại là chẵn
    }
    for(ll i=1; i<=n; i++){
        if(f[i] % 2 == 0)
            res = max(res, f[i]);
    }
    // Nếu không tìm thấy dãy con hợp lệ (res vẫn là LLONG_MIN), in ra NOT_FOUND
    if (res == LLONG_MIN) {
        cout << "NOT_FOUND" << endl;
    } else {
        cout << res << endl;  // In ra giá trị lớn nhất của dãy con có tổng chẵn
    }

    return 0;
}
