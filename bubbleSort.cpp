#include<bits/stdc++.h>

using namespace std;

/*void bubbleSort(int a[],int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < n - i - 1;j++){
            if(a[j] > a[j + 1]){
                swap(a[j],a[j + 1]);
            }
        }
    }
}*/

void bubbleSort(int a[],int n){
    int i,j;
    for(int i = 0;i < n - 1;i++)
        for(j = n - 1;j > i;j--){
            if(a[j] < a[j - 1]){
                swap(a[j],a[j-1]);
            }
        }
}


int main(){
    int a[10];
    for(int i = 0;i < 10;i++){
        cin >> a[i];
    }
    bubbleSort(a,10);
    for(int i = 0;i < 10;i++){
        cout << a[i] << " ";
    }
    return 0;
}