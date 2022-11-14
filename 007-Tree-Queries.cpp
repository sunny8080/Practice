#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
// #define int              long long
#define ull              unsigned long long
#define ff               first
#define ss               second
#define pb               push_back
#define mp               make_pair
#define pii              pair<int,int>
#define vi               vector<int>
#define vll              vector<ll> 
#define vvi              vector< vector<int>>
#define vvll             vector< vector<ll>>
#define vpii             vector<pair<int,int>>
#define mii              map<int,int>
#define pqb              priority_queue<int>
#define pqs              priority_queue<int, vector<int>, greater<int>>
#define setbits(x)       __builtin_popcountll(x)
#define zrobits(x)       __builtin_ctzll(x)
#define mod              1000000007
#define inf              1e18
#define ps(x,y)          fixed<<setprecision(y)<<x
#define mk(arr, n, type) type *arr=new type[n];
#define wt(x)            int x; cin>>x; while( x-- )
#define rep(i,a,b)       for( int i=a; i<=b; i++ )
#define repi(i,a,b)      for( int i=a; i>=b; i-- )
#define sp               ' '
#define nl               char(10)
#define endl             char(10)
#define PRT(ar)          for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)       memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())
#define all(x)           x.begin(), x.end()

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


// QUE :- https://codeforces.com/problemset/problem/1328/E


class Solution {
    int n;
    vi par, inT, ouT, lvl;
    int tm = 0;
public:
    Solution(int n) {
        this->n = n;
        par.resize(n + 1, -1);
        inT.resize(n + 1);
        ouT.resize(n + 1);
        lvl.resize(n + 1);
    }

    void dfs(vvi& adj, int node = 1, int pr = 0, int lv = 0) {
        lvl[node] = lv;
        par[node] = pr;
        inT[node] = tm++;

        for (auto nbr : adj[node]) {
            if (nbr != pr) {
                dfs(adj, nbr, node, lv + 1);
            }
        }

        ouT[node] = tm++;
    }

    string solve(vvi& adj, vi& v) {
        int n = adj.size(), k = v.size();
        int farth, depth = -1;
        for (int i = 0; i < k; i++) {
            if (lvl[v[i]] > depth) {
                depth = lvl[v[i]], farth = v[i];
            }
            v[i] = par[v[i]];
        }

        string ans = "YES";
        for (int i = 0; i < k; i++) {
            // root may be root node (1, par=0)
            if (v[i] == 0) continue;

            if ((inT[v[i]] > inT[farth]) || (ouT[v[i]] < inT[farth])) {
                ans = "NO";
                break;
            }

            // if (!(inT[v[i]] < inT[farth] && ouT[v[i]] > ouT[farth])) {
            //     ans = "NO";
            //     break;
            // }
        }
        return ans;
    }
};



int32_t main() {
    fastIO();

    int n, m; cin >> n >> m;
    Solution sol(n);
    vvi adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sol.dfs(adj);

    while (m--) {
        int k; cin >> k;
        vi v(k);
        for (auto& x : v) cin >> x;
        auto ans = sol.solve(adj, v);
        cout << ans << nl;
    }

    // cout<<"ss";

    return 0;
}

