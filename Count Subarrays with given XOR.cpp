class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> freq;
    
         int prefixXor = 0;
         int count = 0;

    // Important: handles subarrays starting from index 0
        freq[0] = 1;

        for (int i = 0; i < arr.size(); i++) {
            prefixXor ^= arr[i];

            int needed = prefixXor ^ k;

            if (freq.find(needed) != freq.end()) {
                count += freq[needed];
        }

        freq[prefixXor]++;
        }
    
        return count;
    }
};
