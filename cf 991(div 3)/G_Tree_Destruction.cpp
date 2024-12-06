#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[200005];
bool visited[200005];

int dfs(int node, int dist) {
    visited[node] = true;
    int max_dist = dist, farthest_node = node;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            int res = dfs(neighbor, dist + 1);
            if (res > max_dist) {
                max_dist = res;
                farthest_node = neighbor;
            }
        }
    }
    return max_dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        // Reset adjacency list and visited array for each test case
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
        }

        // Read the edges
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Find the farthest node from any starting node (let's say node 1)
        dfs(1, 0);

        // Now do a DFS from the farthest node found to get the diameter
        int max_distance = dfs(1, 0);

        // The maximum number of connected components after removal is diameter + 1
        cout << max_distance + 1 << endl;
    }
    
    return 0;
}
