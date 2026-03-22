class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (mat[r][c] == 2) q.push({r, c});
                else if (mat[r][c] == 1) fresh++;
            }
        }

        // Edge case: no fresh oranges to rot
        if (fresh == 0) return 0;

        
        
        int time = 0;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!q.empty()) {
            int levelSize = q.size();   
            bool rotted_any = false;

            for (int i = 0; i < levelSize; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    
                    if (nr < 0 || nr >= rows) continue;
                    if (nc < 0 || nc >= cols) continue;
                    if (mat[nr][nc] != 1)     continue;

                    mat[nr][nc] = 2;    
                    fresh--;            
                    q.push({nr, nc});   
                    rotted_any = true;
                }
            }

            if (rotted_any) time++;
        }

        return fresh == 0 ? time : -1;
    }
};
