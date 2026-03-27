class Solution {
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        // Base case: Robot1 at (0,0), Robot2 at (0, m-1)
        if (0 == m - 1)
            dp[0][0] = grid[0][0];          // both on same cell
        else
            dp[0][m - 1] = grid[0][0] + grid[0][m - 1];
        
        // Directions each robot can move: -1, 0, +1
        vector<int> dirs = {-1, 0, 1};
        
        for (int i = 0; i < n - 1; i++) {
            vector<vector<int>> ndp(m, vector<int>(m, -1));
            
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    // Skip invalid states
                    if (dp[j1][j2] == -1) continue;
                    
                    // Try all 9 combinations of moves
                    for (int dj1 : dirs) {
                        for (int dj2 : dirs) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            
                            // Check boundaries
                            if (nj1 < 0 || nj1 >= m) continue;
                            if (nj2 < 0 || nj2 >= m) continue;
                            
                            // Collect chocolates (avoid double counting)
                            int collected = (nj1 == nj2)
                                ? grid[i + 1][nj1]
                                : grid[i + 1][nj1] + grid[i + 1][nj2];
                            
                            int newVal = dp[j1][j2] + collected;
                            ndp[nj1][nj2] = max(ndp[nj1][nj2], newVal);
                        }
                    }
                }
            }
            dp = ndp;
        }
        
        // Find maximum across all final states
        int ans = 0;
        for (int j1 = 0; j1 < m; j1++)
            for (int j2 = 0; j2 < m; j2++)
                if (dp[j1][j2] != -1)
                    ans = max(ans, dp[j1][j2]);
        
        return ans;
    }
};
