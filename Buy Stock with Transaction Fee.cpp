class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int hold = -arr[0];  // bought on day 0
        int cash = 0;        // haven't bought anything yet

        for (int i = 1; i < arr.size(); i++) {
            int prev_hold = hold;
            int prev_cash = cash;

            hold = max(prev_hold, prev_cash - arr[i]); // buy today
            cash = max(prev_cash, prev_hold + arr[i] - k); // sell today
        }

        return cash; // best profit with no stock in hand
    }
};
