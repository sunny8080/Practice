#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll                 long long
#define int                long long
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
vector<vpii> adj(1e5 + 5);

//class Solution {
//
//public:
//
//};

void solve() {
    priority_queue<pii, vector<pii>, greater<pii>>  pq;
    vector<int> dist(n, 1e18);
    vector<int> par(n, -1);

    dist[0] = 0;
    par[0] = -1;
    pq.push({ 0, 0 });

    while (pq.size()) {
        int nodeWt = pq.top().first, node = pq.top().second;
        pq.pop();
        for (auto it : adj[node]) {
            if (it.second + nodeWt < dist[it.first]) {
                dist[it.first] = it.second + nodeWt;
                pq.push({ dist[it.first], it.first });
                par[it.first] = node;
            }
        }
    }
    if (dist[n - 1] == 1e18) cout << -1 << nl;
    else {
        vector<int> ans;
        int node = n - 1;
        // cout << dist[node] << nl;
        while (node != -1) {
            ans.push_back(node + 1);
            node = par[node];
        }
        reverse(ans.begin(), ans.end());
        PRT(ans);
    }
}


int32_t main() {
    fastIO();
    // Solution sol;

    rii(n, m);
    while (m--) {
        driii(u, v, w);
        u--, v--;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    solve();


    return 0;
}




