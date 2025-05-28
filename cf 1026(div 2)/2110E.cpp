// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define int long long

// const int INF = 2e18;
// const int M = 1000000007;

// #define yes cout << "YES\n"
// #define no cout << "NO\n"
// #define pb push_back
// #define pii pair<int, int>
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define vii vector<pair<int, int>>
// #define ff first
// #define ss second
// #define setbits(n)  __builtin_popcountll(n)
// #define f(i, n) for (int i = 0; i < n; i++)
// #define fo(i, a, b) for (int i = a; i < b; i++)
// #define ia(a, n) \
//     int a[n];    \
//     f(i, n) cin >> a[i]
// #define iv(v, n)      \
//     vector<int> v(n); \
//     f(i, n) cin >> v[i]
// #define vout(v)                \
//     for (auto i : v)           \
//     {                          \
//         std::cout << i << " "; \
//     }
// #define INF INT64_MAX
// #define fastIO                   \
//     ios::sync_with_stdio(false); \
//     cin.tie(NULL);               \
//     cout.tie(NULL);              \
//     cout.precision(numeric_limits<double>::max_digits10);
// #define srt(v) sort(v.begin(), v.end())
// #define rsrt(v) sort(v.rbegin(), v.rend())
// #define newline cout << endl
// #define all(v) (v).begin(), (v).end()

// int gcd(int a, int b)
// {
//     if (b == 0)
//     {
//         return a;
//     }
//     return gcd(b, a % b);
// }
// int lcm(int a, int b)
// {
//     return a * b / gcd(a, b);
// }
// int fact(int n)
// {
//     if (n == 0)
//         return 1;
//     long res = 1;
//     for (int i = 2; i <= n; i++)
//         res = res * i;
//     return res;
// }
// int nCr(int n, int r)
// {
//     return fact(n) / (fact(r) * fact(n - r));
// }

// // Main
// bool beautiful(vector<int> &vol, vector<int> &pitch,int N)
// {
//     for(int i=1;i<=N-1;i++){
//         if((vol[i]==vol[i+1])&&(pitch[i]==pitch[i+1])){
//             return false;
//         }
//         else if ((vol[i] != vol[i + 1]) && (pitch[i] != pitch[i + 1])){
//             return false;
//         }
//     }
//     return true;
// }

// bool nonboring(vector<int> &vol, vector<int> &pitch,int N)
// {
//     for (int i = 1; i <= N-2; i++)
//     {
//         if ((vol[i] == vol[i + 1] == vol[i + 2]))
//         {
//             return false;
//         }
//         if (pitch[i] == pitch[i + 1] == pitch[i+2])
//         {
//             return false;
//         }
//     }
//     return true;
// }
// void solve()
// {
//     int n;
//     cin >> n;
//     vi vol(n+1),pitch(n+1);
//     for(int i=1;i<=n;i++){
//         cin>>vol[i]>>pitch[i];
//     }
//     if(beautiful(vol,pitch,n)&&nonboring(vol,pitch,n)){
//         cout<<"n: "<<n<<endl;
//         yes;
//         return;
//     }
// }

// int32_t main()
// {
// #ifdef ONLINE_JUDGE
//     auto begin = chrono::high_resolution_clock::now();
//     fastIO;
// #endif

//     int t;
//     cin >> t;
//     // t = 1;
//     while (t--)
//     {
//         solve();
//     }
// #ifdef ONLINE_JUDGE
//     auto end = chrono::high_resolution_clock::now();
//     cerr << fixed << setprecision(4);
//     cerr << "Execution time: "
//          << chrono::duration_cast<chrono::duration<double>>(end - begin).count()
//          << " seconds" << endl;
// #endif

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Hierholzer’s algorithm to find an Eulerian trail in an undirected graph
// with edges labeled 1..m.  Returns the sequence of edge IDs in trail order,
// or an empty vector if no Eulerian trail exists covering all edges.
vector<int> euler_trail(int N, vector<array<int, 3>> &edges)
{
    // edges: {u, v, id}, 1-based ids
    vector<vector<pair<int, int>>> adj(N);
    vector<int> deg(N, 0);
    for (auto &e : edges)
    {
        int u = e[0], v = e[1], id = e[2];
        adj[u].push_back({v, id});
        adj[v].push_back({u, id});
        deg[u]++;
        deg[v]++;
    }
    // find vertices of odd degree
    vector<int> odd;
    for (int i = 0; i < N; i++)
    {
        if (deg[i] % 2)
            odd.push_back(i);
    }
    if (odd.size() != 0 && odd.size() != 2)
        return {}; // no trail

    // find a start vertex: odd[0] if exists, else any with deg>0
    int start = (odd.empty() ? -1 : odd[0]);
    if (start < 0)
    {
        // pick any vertex incident to an edge
        for (int i = 0; i < N; i++)
        {
            if (deg[i] > 0)
            {
                start = i;
                break;
            }
        }
        if (start < 0)
            return {}; // no edges at all
    }

    vector<char> used_edge(edges.size() + 1, 0);
    vector<int> ptr(N, 0);
    vector<pair<int, int>> st; // (vertex, incoming_edge_id)
    vector<int> trail;
    st.reserve(edges.size() + 1);
    trail.reserve(edges.size());

    st.push_back({start, -1});
    while (!st.empty())
    {
        auto x = st.back();
        int v = x.first;
        int in_e = x.second;
        // skip used edges
        while (ptr[v] < (int)adj[v].size() && used_edge[adj[v][ptr[v]].second])
            ptr[v]++;
        if (ptr[v] == (int)adj[v].size())
        {
            // no more edges out: backtrack
            st.pop_back();
            if (in_e != -1)
                trail.push_back(in_e);
        }
        else
        {
            auto x = adj[v][ptr[v]++];
            int u = x.first;
            int eid = x.second;
            used_edge[eid] = 1;
            st.push_back({u, eid});
        }
    }
    if ((int)trail.size() != (int)edges.size())
        return {}; // didn’t use all edges
    reverse(trail.begin(), trail.end());
    return trail;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> sounds(n);
        for (int i = 0; i < n; i++)
        {
            cin >> sounds[i].first >> sounds[i].second;
        }

        // 1) coordinate‐compress volumes and pitches
        vector<ll> vs(n), ps(n);
        for (int i = 0; i < n; i++)
        {
            vs[i] = sounds[i].first;
            ps[i] = sounds[i].second;
        }
        sort(vs.begin(), vs.end());
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        sort(ps.begin(), ps.end());
        ps.erase(unique(ps.begin(), ps.end()), ps.end());
        int V = vs.size(), P = ps.size();

        // 2) build edge list for bipartite graph
        //    volumes: 0..V-1, pitches: V..V+P-1
        vector<array<int, 3>> edges;
        edges.reserve(n);
        for (int i = 0; i < n; i++)
        {
            int vi = lower_bound(vs.begin(), vs.end(), sounds[i].first) - vs.begin();
            int pi = lower_bound(ps.begin(), ps.end(), sounds[i].second) - ps.begin() + V;
            edges.push_back({vi, pi, i + 1}); // edge ID = i+1
        }

        // 3) check connectivity on the subgraph induced by edges
        vector<vector<int>> g(V + P);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<char> seen(V + P, 0);
        queue<int> q;
        if (!edges.empty())
        {
            q.push(edges[0][0]);
            seen[edges[0][0]] = 1;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int w : g[u])
            {
                if (!seen[w])
                {
                    seen[w] = 1;
                    q.push(w);
                }
            }
        }
        bool conn_ok = true;
        for (auto &e : edges)
        {
            if (!seen[e[0]] || !seen[e[1]])
            {
                conn_ok = false;
                break;
            }
        }
        if (!conn_ok)
        {
            cout << "NO\n";
            continue;
        }

        // 4) find Eulerian trail on the bipartite graph
        auto trail = euler_trail(V + P, edges);
        if (trail.empty())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            // `trail` is the sequence of sound‐IDs in order:
            for (int id : trail)
            {
                cout << id << ' ';
            }
            cout << "\n";
        }
    }
    return 0;
}
