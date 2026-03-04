class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int curXor=0;
        
        for(int i=0; i<k ;i++){
            curXor= curXor ^ arr[i]; //calculated the first k xor
            
        }
        
        int maxXor = curXor;
        
        for(int i=k; i<arr.size(); i++){
            curXor = curXor ^ arr[i-k] ^ arr[i]; //removing the first adding the new
            maxXor = max(curXor, maxXor); //updating the xorr each time
        }
        
        
        return maxXor;
        
        
    }
};
