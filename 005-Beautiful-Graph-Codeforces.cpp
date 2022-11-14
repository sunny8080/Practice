#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll               long long
#define int              long long
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



class Solution {

    int pwrMod(int a, int n, int md = mod) {
        int res = 1LL;
        while (n) {
            if ((n & 1)) res = (res * 1LL * a) % md;
            n /= 2;
            a = (a * 1LL * a) % md;
        }
        return res;
    }


    // METHOD - 1
    void dfs(int i, vi& vis, int& cnt0, int& cnt1, int parity, int& can, vvi& adj) {
        if (vis[i] != -1) {
            if (parity != vis[i]) {
                can = 0;
            }
            return;
        }

        vis[i] = parity;
        if (parity == 0) cnt0++;
        else cnt1++;

        for (auto nbr : adj[i]) {
            dfs(nbr, vis, cnt0, cnt1, 1 - parity, can, adj);
        }
    }


    // METHOD - 2
    // bipartite or colouring the balls algo used
    void dfs2(int node, vi& vis, int& cnt0, int& cnt1, int parity, int& can, vvi& adj) {
        vis[node] = parity;
        if (parity == 0) cnt0++;
        else cnt1++;

        for (auto nbr : adj[node]) {
            if (vis[nbr] == -1) {
                dfs2(nbr, vis, cnt0, cnt1, 1 - parity, can, adj);
                if (can == 0) return;
            } else if (parity == vis[nbr]) {
                can = 0;
                return;
            }
        }
    }


public:

    int solve(int n, vvi& adj) {
        vi vis(n + 1, -1);
        int md = 998244353;

        int cnt0, cnt1, can;
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == -1) {
                cnt0 = cnt1 = 0;
                can = 1;
                // dfs(i, vis, cnt0, cnt1, 0, can, adj);
                dfs2(i, vis, cnt0, cnt1, 0, can, adj);

                if (!can) return 0;

                cnt0 = pwrMod(2, cnt0, md);
                cnt1 = pwrMod(2, cnt1, md);
                ans = (ans * 1LL * (cnt0 + cnt1)) % md;
            }
        }

        return ans;
    }
};





int32_t main() {
    fastIO();
    Solution sol;
    wt(t) {
        int n, m; cin >> n >> m;
        vvi adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << sol.solve(n, adj) << nl;
    }

    return 0;
}

