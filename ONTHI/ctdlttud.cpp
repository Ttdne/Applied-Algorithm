#include<bits/stdc++.h>
using namespace std;

int N;
int check = 0;
int kiemtra[13]; // Mảng kiểm tra xem chữ số đã được sử dụng chưa
int f[6]; // Mảng lưu trữ các chữ số cho C, T, D, L, G, U

void solution() {
    // Tính giá trị của CTDLGT
    int first = f[1] + f[4]*10 + f[3]*100 + f[2]*1000 + f[1]*10000 + f[0]*100000;
    // Tính số thứ hai (C T D L G U)
    int sec = f[2] + f[5]*10 + f[1]*100 + f[1]*1000;
    int sum = first + sec;

    // Nếu tổng đúng bằng N, thì tăng biến check
    if(sum == N){
        for(int i=0; i<=5; i++) cout<<f[i]<<" ";
        cout<<endl;
        check++;
}
}

void Try(int i) {
    if(i == 6) {
        solution(); // Đã gán đủ chữ số cho C, T, D, L, G, U, kiểm tra nghiệm
    }

    for(int j = 0; j <= 9; j++) {
        // Nếu chưa gán chữ số này
        if(kiemtra[j] == 0) {
            // Điều kiện C và T không được là 0
            if((i == 0 || i == 1) && j == 0) continue;

            kiemtra[j] = 1; // Đánh dấu đã sử dụng
            f[i] = j; // Gán giá trị cho chữ cái
            Try(i + 1); // Thử chữ cái tiếp theo
            kiemtra[j] = 0; // Đánh dấu lại là chưa sử dụng
        }
    }
}

int main() {
    cin >> N; // Nhập giá trị N
    memset(kiemtra, 0, sizeof kiemtra); // Khởi tạo mảng kiemtra
    Try(0); // Bắt đầu thử nghiệm từ chữ cái đầu tiên

    cout << check << endl; // In ra số cách gán tìm được
    return 0;
}
