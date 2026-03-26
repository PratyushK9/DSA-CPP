class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        vector<vector<pair<int,int>>> adj(n);
        
        for (auto &it : roads) {
            int u = it[0], v = it[1], t = it[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue;

            for (auto &[adjNode, wt] : adj[node]) {
                long long newTime = time + wt;

                // 
                if (newTime < dist[adjNode]) {
                    dist[adjNode] = newTime;
                    ways[adjNode] = ways[node];
                    pq.push({newTime, adjNode});
                }
                // 
                else if (newTime == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};
