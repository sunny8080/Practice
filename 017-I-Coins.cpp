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


int n;
double coin[3005];
double dp[3005][3005];

class Solution {

public:
    double solve(int ind, int head) {
        if (ind == 0 and head == 0) return 1;
        if (head == 0) return 1;
        if (ind == 0) return 0;
        // if (dp[ind][head] != -1) return dp[ind][head];
        // if (dp[ind][head] != -1.0) return dp[ind][head];
        if (dp[ind][head] > -0.9) return dp[ind][head];

        return dp[ind][head] = coin[ind] * solve(ind - 1, head - 1) + (1 - coin[ind]) * solve(ind - 1, head);
    }
};



int32_t main() {
    fastIO();
    Solution sol;
    // for (int i = 0; i < 3005; i++)
    //     for (int j = 0; j < 3005; j++)
    //         dp[i][j] = -1.0;

    for (int i = 0; i < 3005; i++)
        for (int j = 0; j < 3005; j++)
            dp[i][j] = -0.9;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> coin[i];
    cout << ps(sol.solve(n, n / 2 + 1), 10) << nl;



    return 0;
}

