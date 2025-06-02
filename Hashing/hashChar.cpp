#include <bits/stdc++.h>
using namespace std;

int main(){
    string ch;
    cin>>ch;

    //precompute
    int hash[256]={0};
    for(int i=0;i<ch.size();i++){
        hash[ch[i]]++;
    }


    int q;
    cin>>q;
    while(q--){
        char strCh;
        cin>>strCh;

        cout<<hash[strCh]<<" ";

    }

    return 0;
}