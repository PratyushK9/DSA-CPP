class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int total = 0;
        for (int x : arr) total += x;

        if ((total + diff) % 2 != 0 || diff > total) return 0;

        int target = (total + diff) / 2;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] > target) continue;
            for (int j = target; j >= arr[i]; j--) {
                dp[j] += dp[j - arr[i]];
            }
        }

        return dp[target];
    }
};
