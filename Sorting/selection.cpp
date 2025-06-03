#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min_index]) min_index=j;
        }

        ///swap
        int temp=arr[i]; //preev choosen value 
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
}

void bubble_sort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                //swap
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
    }

    
   
    }

int main(){
    int arr[]={23,43,1,12,5};
    int n=5;

    bubble_sort(arr,n);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}