#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=1;i<=n-1;i++){
        while(arr[i-1]>arr[i] && i>0){
            //swao
            int temp =arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
            i--;


        }
    }
}
            
int main(){
    int arr[]={24,63,12,8,1};
    int n=5;

    insertion_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}