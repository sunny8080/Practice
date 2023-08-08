#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
// #define int                long long
#define ull                unsigned long long
#define ff                 first
#define ss                 second
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<int,int>
#define vi                 vector<int>
#define vll                vector<ll> 
#define vvi                vector< vector<int>>
#define vvll               vector< vector<ll>>
#define vpii               vector<pair<int,int>>
#define mii                map<int,int>
#define pqb                priority_queue<int>
#define pqs                priority_queue<int, vector<int>, greater<int>>
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x,y)            fixed<<setprecision(y)<<x
#define mk(arr, n, type)   type *arr=new type[n];
#define wt(x)              int x; cin>>x; while( x-- )
#define sp                 ' '
#define nl                 char(10)
#define PRT(ar)            for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)         memset(x,ch,sizeof(x))
#define sortv(x)           sort(x.begin(),x.end())
#define sortvr(x)          sort(x.rbegin(),x.rend())
#define all(x)             x.begin(), x.end()
#define fr(t,a,b)          for( int t=(a); t<=(b); t++)
#define frr(t,a,b)         for( int t=(a); t>=(b); t--)
#define cn(x)              int x; cin>>x;
#define ri(x)              cin >> x
#define rii(x, y)          cin >> x >> y
#define riii(x, y, z)      cin >> x >> y >> z
#define riiii(x, y, z, w)  cin >> x >> y >> z >> w
#define rvi(nums)          for (auto& x : nums) cin >> x;
#define dri(x)             int x; cin >> x
#define drs(s)             string s; cin >> s
#define drii(x, y)         int x, y; cin >> x >> y
#define driii(x, y, z)     int x, y, z; cin >> x >> y >> z
#define driiii(x, y, z, w) int x, y, z, w; cin >> x >> y >> z >> w
#define drvi(nums, n)      vector<int> nums(n); for (auto& x : nums) cin >> x;
#define iff(x, y)  if(x) y

const ll N = 1e5 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}



int n, m;
vvi adj(405);
vvi adjRev(405);

void dfs1(int node, vi& vis, stack<int>& stk) {
    vis[node] = 1;
    for (auto nbr : adj[node])
        if (!vis[nbr])  dfs1(nbr, vis, stk);
    stk.push(node);
}

void dfs2(int node, vi& vis) {
    vis[node] = 1;
    for (auto nbr : adjRev[node])
        if (!vis[nbr])  dfs2(nbr, vis);
}



int solve() {
    vi vis(n, 0);
    stack<int> stk;

    // sort the vertices
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs1(i, vis, stk);

    // reverse the graph
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        for (auto nbr : adj[i]) {
            adjRev[nbr].push_back(i);
        }
    }

    int scc = 0;
    while (stk.size()) {
        int i = stk.top();
        stk.pop();
        if (!vis[i]) {
            dfs2(i, vis);
            scc++;
        }
    }
    // cout << scc << nl;
    puts(scc == 1 ? "YES" : "NO");
}



int32_t main() {
    fastIO();
    rii(n, m);
    string a, b; cin >> a >> b;

    /*
    {
        int node = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                int u = j + i * m, v = j + i * m + 1; // >
                if (a[i] == '<') swap(u, v); // <
                adj[u].push_back(v);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j + m < m * n; j += m) {
                int u = j + i, v = j + m + i; // v
                if (b[i] == '^') swap(u, v);
                adj[u].push_back(v);
            }
        }
        n = n * m;

        // for (int i = 0; i < n; i++) {
        //     cout << i << sp;
        //     PRT(adj[i]);
        // }

        solve();
    }
    */


    string ans = { a.front(), a.back(), b.front(), b.back() };
    cout << (ans == "<>v^" || ans == "><^v" ? "YES" : "NO") << nl;



    return 0;
}




