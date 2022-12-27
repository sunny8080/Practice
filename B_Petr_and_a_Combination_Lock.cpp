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


int dp[16][(1 << 16)];
int n;
vi nums;

class Solution {

public:
    void solve1_help(int ind, int subset) {
        if (ind == n) return;

        int take = subset | (1 << ind);
        int notTake = subset & (~(1 << ind));

        // sum : [0 ... (ind-1)]
        int preSum = (ind > 0 ? dp[ind - 1][subset] : 0);

        dp[ind][take] = preSum + nums[ind];
        dp[ind][notTake] = preSum - nums[ind];

        solve1_help(ind + 1, take);
        solve1_help(ind + 1, notTake);
    }


    // dp
    void solve1() {
        solve1_help(0, 0);
        int i = 0;
        for (; i < (1 << n); i++) {
            // cout << dp[n - 1][i] << nl;
            if (dp[n - 1][i] % 360 == 0) { cout << "YES" << nl; break; }
        }
        if (i == (1 << n)) cout << "NO" << nl;
    }


    // power set // bit manipulation
    void solve2() {
        int cntSubset = (1 << n) - 1;
        for (int i = 0; i <= cntSubset; i++) {
            int sum = 0;
            for (int bit = 0; bit < n; bit++) {
                if ((i & (1 << bit))) sum += nums[bit];
                else sum -= nums[bit];
            }
            if (sum % 360 == 0) { cout << "YES" << nl; return; }
        }
        cout << "NO" << nl;
    }

};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, -1);

    cin >> n;
    nums.resize(n);
    for (auto& x : nums) cin >> x;
    // sol.solve1();
    sol.solve2();

    return 0;
}




