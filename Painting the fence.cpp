class Solution {
  public:
    int countWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        
        // For 2 posts:
        // same = k ways (both same color)
        // diff = k*(k-1) ways (different colors)
        long long same = k;
        long long diff = (long long)k * (k - 1);
        
        for (int i = 3; i <= n; i++) {
            long long newSame = diff;           // only prev diff state can become same
            long long newDiff = (same + diff) * (k - 1); // any total * (k-1) colors
            same = newSame;
            diff = newDiff;
        }
        
        return (int)(same + diff);
    }
};
