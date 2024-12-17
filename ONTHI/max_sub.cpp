#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[503][503];

int calculate(vector<int>& heights) {
    stack<int> st;
    int max_Area = 0;

    heights.push_back(0); // Đánh dấu kết thúc để xử lý toàn bộ stack
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : (i - st.top() - 1);
            max_Area = max(max_Area, h * w);
        }
        st.push(i);
    }
    heights.pop_back(); // Xóa phần tử cuối cùng sau khi xử lý
    return max_Area;
}

int maxHeigh(int m, int n) {
    vector<int> heights(m, 0); // Chiều cao của mỗi cột
    int maxArea = 0;

    for (int i = 0; i < n; i++) { // Duyệt qua từng hàng
        for (int j = 0; j < m; j++) {
            // Tăng chiều cao nếu ô là 1, reset nếu ô là 0
            if (a[i][j] == 1)
                heights[j]++;
            else
                heights[j] = 0;
        }
        maxArea = max(maxArea, calculate(heights));
    }
    return maxArea;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << maxHeigh(m, n);
    return 0;
}
