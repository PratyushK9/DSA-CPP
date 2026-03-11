class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
    
        vector<int> pse(n), nse(n);
        stack<int> st;
    
        // Previous Smaller Element
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
    
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
    
            st.push(i);
        }
    
        while(!st.empty()) st.pop();
    
        // Next Smaller Element
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
    
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
    
            st.push(i);
        }
    
        long long sum = 0;
    
        for(int i = 0; i < n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
    
            sum += arr[i] * left * right;
        }
    
        return sum;
        
    }
};
