#include<bits/stdc++.h>

using namespace std;

void quicksort(int a[],int left,int right){
    int pivot,l,r;
    pivot = a[(left + right)/2];
    l = left;
    r = right;
    do{
        while(a[l] < pivot) l++;
        while(a[r] > pivot) r--;
        if(l <= r){
            swap(a[l],a[r]);
            l++;
            r--;
        }
    }while(l <= r);
    if(left < r){
        quicksort(a,left,r);
    }
    if(l < right){
        quicksort(a,l,right);
    }
}

int main(){
    int a[10];
    for(int  i = 0;i < 10;i++){
        cin >> a[i];
    }
    quicksort(a,0,9);
    cout << "Day sau khi sap xep";
    for(int  i = 0;i < 10;i++){
        cout << a[i] << " ";
    }
    return 0;
}