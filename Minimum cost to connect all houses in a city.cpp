class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
    if (n == 0) return 0;

    vector<int> minDist(n, INT_MAX);  
    vector<bool> inMST(n, false);    
    minDist[0] = 0;                  
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        //unvisited node with minimum distance
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!inMST[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }

        inMST[u] = true;
        totalCost += minDist[u];

        // uppdati;ng distances of neighbors of u
        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int dist = abs(houses[u][0] - houses[v][0]) +
                           abs(houses[u][1] - houses[v][1]);
                minDist[v] = min(minDist[v], dist);
            }
        }
    }

    return totalCost;
        
    }
};

