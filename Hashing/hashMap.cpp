#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        arr[i]=num;
    }

    //precompute
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;

    }


    int q;
    cin>>q;
    
    int number;
    
    int highest=0;
    int element ;

    while(q--){
        cin>>number;
        if(mpp[number]>highest) {
            highest=mpp[number];
            element=number;
        }

        cout<<number<<"->"<<mpp[number]<<endl;


    }
    cout<<"The highest frequency element is:"<<element<<"nd the number of times it appear is:"<<highest;

}