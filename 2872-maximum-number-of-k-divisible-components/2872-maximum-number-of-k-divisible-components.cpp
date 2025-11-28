class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
    }
};class Solution {
public:
    long long ans = 0;
    int k;

    long long dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values) {
        long long sum = values[node];

        for (int child : adj[node]) {
            if (child == parent) continue;
            sum += dfs(child, node, adj, values);
        }

        if (sum % k == 0) {
            ans++;          // this subtree forms a valid component
            return 0;       // detach this component
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, adj, values);
        return ans;
    }
};
