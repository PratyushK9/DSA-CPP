class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        //Creating prefix sum matrix
        vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i-1][j-1] 
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];
            }
        }
        
        int count = 0;
        
        //Tried all square sizes
        for(int size = 1; size <= min(n, m); size++) {
            for(int i = 0; i + size - 1 < n; i++) {
                for(int j = 0; j + size - 1 < m; j++) {
                    
                    int r1 = i;
                    int c1 = j;
                    int r2 = i + size - 1;
                    int c2 = j + size - 1;
                    
                    int sum = prefix[r2+1][c2+1]
                            - prefix[r1][c2+1]
                            - prefix[r2+1][c1]
                            + prefix[r1][c1];
                    
                    if(sum == x)
                        count++;
                }
            }
        }
        
        return count;
    }
};
