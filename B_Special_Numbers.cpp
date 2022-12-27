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
    int modPower(int a, int n) {
        int res = 1ll;
        while (n) {
            if ((n & 1)) res = (res * a) % mod;
            a = (a * a) % mod;
            n >>= 1;
        }
        return res;
    }
public:
    int solve(int n, int k) {
        if (k <= 0) return 0;
        int t = (int)log2(k + 1) - 1;
        int cnt = (1ll << (t + 1)) - 1;

        if (cnt == k) {
            int ans = ((modPower(n, t + 1) - 1 + mod) % mod * modPower(n - 1, mod - 2)) % mod;
            return ans;
        }

        int ans = (modPower(n, t + 1) + solve(n, k - cnt - 1)) % mod;
        return ans;
    }


    int solve2(int n, int k) {
        if (!k) return 0;
        int t = (ll)log2(k);
        k = (k & ~(1ll << t));
        return (modPower(n, t) + solve2(n, k)) % mod;
    }

    int solve3(int n, int k) {
        int p = 1;
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            if ((k & (1 << i))) ans = (ans+p)%mod;
            p = (p*n)%mod;
        }
        return ans;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    wt(t) {
        int n, k; cin >> n >> k;
        // cout << sol.solve(n, k) << nl;
        cout << sol.solve2(n, k) << nl;
        // cout << sol.solve3(n, k) << nl;
    }


    return 0;
}




