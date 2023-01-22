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
#define mod                998244353
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

const ll N = 3 * 1e5 + 5;
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
    int fact[N + 1], ifact[N + 1];
    int modPwr(int a, int b) {
        int res = 1ll;
        while (b) {
            if ((b & 1)) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int inv(int a) {
        return modPwr(a, mod - 2);
    }



    void pre() {
        fact[0] = 1;
        for (int i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % mod;
        ifact[N] = inv(fact[N]);
        for (int i = N - 1; i > 0; i--) {
            ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
        }
        ifact[0] = 1;
    }

    int nCr(int n, int r) {
        if (r > n) return 0;
        int ans = fact[n];
        ans = (ans * ifact[r]) % mod;
        ans = (ans * ifact[n - r]) % mod;
        return ans;
    }

public:
    int solve(vi& l, vi& r, int n, int k) {
        pre();
        // sweep line techique
        sortv(l);
        sortv(r);

        int on = 0, cnt = 0, i = 0, j = 0;
        while (i < n && j < n) {
            if (l[i] <= r[j]) {
                if (on >= k - 1) cnt = (cnt + nCr(on, k - 1)) % mod;
                on++;
                i++;
            } else {
                on--;
                j++;
            }
        }

        return cnt;
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    drii(n, k);
    vi l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    cout << sol.solve(l, r, n, k) << nl;


    return 0;
}




