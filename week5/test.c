#include <stdio.h>

int main() {
    // Khởi tạo mảng A và B
    int A[] = {1, 2, 4, 5, 6, 7, 8, 9};
    int B[] = {2, 3, 5, 6, 7, 8, 5, 8};

    // Khởi tạo các giá trị chỉ số f, g
    int f = 3;
    int g = 7;

    // Tính toán địa chỉ tương ứng trong mảng A và B
    int value_A_f = A[f];            // Lấy giá trị A[f]
    int value_A_f_plus_2 = A[f + 2];  // Lấy giá trị A[f + 2]
    int result_A = value_A_f + value_A_f_plus_2;  // Cộng A[f] và A[f + 2]

    int value_B_g = B[g];  // Lấy giá trị B[g]

    // In kết quả
    printf("A[f] = %d\n", value_A_f);
    printf("A[f + 2] = %d\n", value_A_f_plus_2);
    printf("Result (A[f] + A[f + 2]) = %d\n", result_A);
    printf("B[g] = %d\n", value_B_g);

    return 0;
}
