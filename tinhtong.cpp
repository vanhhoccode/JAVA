#include<iostream>

using namespace std;


double tinhTongPhanSo(int n){
    if(n == 1){
        return (double)n / (n + 1);
    }
    return (double)n / (n + 1) + tinhTongPhanSo(n - 1);
}

int main(){
    cout << tinhTongPhanSo(5);
}