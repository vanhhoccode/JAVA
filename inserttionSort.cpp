#include<bits/stdc++.h>

using namespace std;

void insertionSort(int a[],int n){
    for(int i = 1;i < n;i++){
        //lay ra phan tu o chi so i
        int x = a[i],pos = i - 1;
        while(pos >= 0 && x < a[pos]){
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = x;
    }
}

int main(){
    return 0;
}