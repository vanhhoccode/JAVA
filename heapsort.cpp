#include <bits/stdc++.h>

using namespace std;

void Shift(int a[], int L, int R) {
    int i = L;
    int j = 2 * i;
    int KEY = a[i];

    while (j <= R) {
        if (j < R && a[j] < a[j + 1]) {  
            j = j + 1;  // Chọn con lớn hơn
        }
        if (KEY >= a[j]) {  
            break;  // Nếu KEY đã đúng vị trí thì thoát
        }
        a[i] = a[j];  
        i = j;
        j = 2 * i;
    }
    a[i] = KEY;  // Đặt KEY vào vị trí đúng
}

void heap_sort(int a[], int n) {
    // Xây dựng max heap
    for (int i = n / 2; i >= 1; i--) {
        Shift(a, i, n);
    }

    // Sắp xếp
    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]);  // Đưa phần tử lớn nhất về cuối mảng
        Shift(a, 1, i - 1);  // Cập nhật heap
    }
}

int main() {
    int a[10];  // Dùng chỉ số từ 1 -> 9

    for (int i = 1; i <= 9; i++) {
        cin >> a[i];
    }

    heap_sort(a, 9);

    for (int i = 1; i <= 9; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
