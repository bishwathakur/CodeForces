#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <functional>
#include <cassert>
using namespace std;

const int MAXN = 405;
const int MAXQ = 300005;
const int INF = 1e9 + 7;

struct Edge
{
    int u, v, w;
};

vector<Edge> edges;
vector<pair<int, int>> adj[MAXN];
vector<int> weights[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int segtree[4 * MAXN];
int cur_pos;
int t, n, m, q;

void dfs(int v)
{
    int size = 1;
    int max_c_size = 0;
    for (auto &[u, w] : adj[v])
    {
        if (u != parent[v])
        {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            weights[u].push_back(w);
            int c_size = dfs(u);
            size += c_size;
            if (c_size > max_c_size)
            {
                max_c_size = c_size;
                heavy[v] = u;
            }
        }
    }
    return size;
}

void decompose(int v, int h)
{
    head[v] = h;
    pos[v] = cur_pos++;
    if (heavy[v] != -1)
    {
        decompose(heavy[v], h);
    }
    for (auto &[u, w] : adj[v])
    {
        if (u != parent[v] && u != heavy[v])
        {
            decompose(u, u);
        }
    }
}

void build_segtree(int node, int start, int end)
{
    if (start == end)
    {
        segtree[node] = weights[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build_segtree(2 * node, start, mid);
        build_segtree(2 * node + 1, mid + 1, end);
        segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
    }
}

int query_segtree(int node, int start, int end, int l, int r)
{
    if (r < start || end < l)
    {
        return -INF;
    }
    if (l <= start && end <= r)
    {
        return segtree[node];
    }
    int mid = (start + end) / 2;
    int left_query = query_segtree(2 * node, start, mid, l, r);
    int right_query = query_segtree(2 * node + 1, mid + 1, end, l, r);
    return max(left_query, right_query);
}

int query(int a, int b)
{
    int res = -INF;
    while (head[a] != head[b])
    {
        if (depth[head[a]] > depth[head[b]])
        {
            swap(a, b);
        }
        int cur_heavy_path_max = query_segtree(1, 0, n - 1, pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
        b = parent[head[b]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = query_segtree(1, 0, n - 1, pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        cin >> n >> m >> q;

        edges.clear();
        for (int i = 0; i < n; i++)
            adj[i].clear();

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
            edges.push_back({u, v, w});
        }

        fill(heavy, heavy + n, -1);
        parent[0] = -1;
        depth[0] = 0;
        cur_pos = 0;

        dfs(0);
        decompose(0, 0);

        build_segtree(1, 0, n - 1);

        while (q--)
        {
            int a, b, k;
            cin >> a >> b >> k;
            a--, b--;
            int max_weight = query(a, b);
            cout << max_weight << "\n";
        }
    }

    return 0;
}