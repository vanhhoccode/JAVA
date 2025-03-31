#include<bits/stdc++.h>

using namespace std;

void selectionSort(int a[],int n){
    for(int i = 0;i < n - 1;i++){
        //dung 1 bien de luu chi so cua phan tu nho nhat
        int min_pos = i;
        //duyet tat ca cac phan tu dung sau phan tu hien tai va cap nhat vi tri phan tu nho nhat
        for(int j = i + 1;j < n;j++){
            if(a[j] < a[min_pos]){
                min_pos = j;
            }
            swap(a[i],a[min_pos]);
        }
    }
}

int main(){
    return 0;
}


