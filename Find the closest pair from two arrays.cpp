class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        
        int n = arr1.size();
        int m = arr2.size();
        
        int i = 0;
        int j = m - 1;
        
        int minDiff = INT_MAX;
        vector<int> result(2);
        
        while (i < n && j >= 0) {
            
            int sum = arr1[i] + arr2[j];
            int diff = abs(sum - x);
            
            // Update minimum difference
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = arr1[i];
                result[1] = arr2[j];
            }
            
            // Move pointers
            if (sum > x) {
                j--;
            } 
            else if (sum < x) {
                i++;
            } 
            else {
                // Exact match found
                return {arr1[i], arr2[j]};
            }
        }
        
        return result;
    }
};
