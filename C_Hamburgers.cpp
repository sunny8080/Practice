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
#define sp               ' '
#define nl               char(10)
#define PRT(ar)          for( auto i : ar ) cout<<i<<sp; cout<<nl;
#define mems(x,ch)       memset(x,ch,sizeof(x))
#define sortv(x)         sort(x.begin(),x.end())
#define sortvr(x)        sort(x.rbegin(),x.rend())
#define all(x)           x.begin(), x.end()
#define fr(t,a,b)        for( int t=(a); t<=(b); t++)
#define frr(t,a,b)       for( int t=(a); t>=(b); t--)
#define cn(x)            int x; cin>>x;

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
    // return 1 => t<=coin
    // else return 0;
    int query(vi& req, vi& store, vi& p, int n, int coin) {
        int t = 0;
        for (int i = 0; i < 3; i++)
            t += ((req[i] * n - store[i]) > 0 ? ((req[i] * n - store[i]) * p[i]) : 0);
        return t<=coin;
    }

public:
    int solve(string str, vi& store, vi& p, int coin) {
        int b, s, c;
        map<char, int> mpp;
        for (auto ch : str) mpp[ch]++;
        tie(b, s, c) = make_tuple(mpp['B'], mpp['S'], mpp['C']);
        vi req = { b, s, c };

        int l = 0, r = 1e13;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (query(req, store, p, mid, coin)) { l = mid + 1; ans = mid; } else r = mid - 1;
        }

        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    string s;cin >> s;
    vi store(3);
    vi price(3);
    for (auto& x : store) cin >> x;
    for (auto& x : price) cin >> x;
    int coin; cin >> coin;

    cout << sol.solve(s, store, price, coin) << nl;

    return 0;
}




