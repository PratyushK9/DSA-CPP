class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        
        unordered_set<long long> st;
        int n = arr.size();
        
        for(int x : arr)
            st.insert(1LL * x * x);
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                long long sum = 1LL * arr[i] * arr[i] + 1LL * arr[j] * arr[j];
                
                if(st.count(sum))
                    return true;
            }
        }
        
        return false;
    }
};
