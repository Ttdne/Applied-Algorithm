/*Cho dãy số nguyên a: a1, a2, ... , an và một số nguyên dương k. Hãy tìm một đoạn con của a, có ít nhất k phần
tử và có trung bình cộng lớn nhất có thể.
Dữ liệu vào
• Dòng đầu chứa hai số nguyên dương: n k
• Dòng tiếp theo chứa dãy a: a1 a2 ... an
Kết quả
Ghi trung bình cộng lớn nhất tìm được, quy tròn đến số thập phân thứ năm (định dạng “%.5lf”)*/
#include<bits/stdc++.h>
#define MAX 100006
using namespace std;
int n, k;
int a[MAX];
int S[MAX];
int main(){
    cin>>n>>k;
    S[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        S[i] = S[i-1] + a[i];
    }
    double result = -1e9;
    for(int i=n; i>k; i--){
        double tinh = (double)(S[i] - S[i-k])/k;
        cout<<tinh<<"\n";
        result = max(result, tinh);
    }
    printf("%.5lf", result);
    return 0;
}
