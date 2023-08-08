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



class Solution {

public:
    int solve1(int n, int k, vi& a, vi& b) {
        int sum = 0;
        vi dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum += (b[i] == 1 ? a[i] : 0);
            dp[i + 1] = dp[i] + (b[i] == 0 ? a[i] : 0);
        }

        // PRT(dp);
        int maxi = 0;
        for (int i = 0; i <= n - k; i++) {
            maxi = max(maxi, dp[i + k] - dp[i]);
        }
        return sum + maxi;
    }


    int solve2(int n, int k, vi& a, vi& b) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) sum += a[i], a[i] = 0;
            if (i - 1 >= 0)a[i] += a[i - 1];
        }
        int maxi = 0;
        for (int i = 0; i <= n - k; i++) {
            maxi = max(maxi, (a[i + k - 1] - (i - 1 >= 0 ? a[i - 1] : 0)));
        }
        return sum + maxi;
    }


};



int32_t main() {
    fastIO();
    Solution sol;

    drii(n, k);
    drvi(a, n);
    drvi(b, n);


    // cout << sol.solve1(n, k, a, b) << nl;
    cout << sol.solve2(n, k, a, b) << nl;


    return 0;
}




