#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int k = 5;

    unordered_map<int, int> mpp;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    // precompute maximum frequency for each number
    for(int i = n - 1; i >= 0; i--){
        int total_ops = 0;
        int count = 1;

        for(int j = i - 1; j >= 0; j--){
            total_ops += arr[i] - arr[j];
            if(total_ops <= k) count++;
            else break;
        }

        if (mpp.find(arr[i]) == mpp.end())
            mpp[arr[i]] = count;
        else
            mpp[arr[i]] = max(mpp[arr[i]], count);
    }

    for(auto it : mpp){
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}
