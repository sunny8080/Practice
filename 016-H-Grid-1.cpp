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


int grid[1005][1005];
int r, c;


class Solution {

public:

    int solve1() {
        if (grid[1][1] == -1 || grid[r][c] == -1) return 0;
        int dp[r + 1][c + 1] = { 0 }; // path from (r,c) to (i,j)
        dp[r][c] = 1;

        for (int i = r; i >= 1; i--) {
            for (int j = c; j >= 1; j--) {
                if (i == r && j == c) continue;
                if (grid[i][j] == -1) dp[i][j] = 0;
                else {
                    int op1 = (i == r) ? 0 : dp[i + 1][j];
                    int op2 = (j == c) ? 0 : dp[i][j + 1];
                    dp[i][j] = (op1 + op2) % mod;
                }
            }
        }
        return dp[1][1];
    }

    // Bottom up
    int solve2() {
        if (grid[1][1] == -1 or grid[r][c] == -1) return 0;

        for (int i = 1; i <= r && grid[i][1] != -1; i++) grid[i][1] = 1;
        for (int j = 1; j <= c && grid[1][j] != -1; j++) grid[1][j] = 1;

        for (int i = 2; i <= r; i++) {
            for (int j = 2; j <= c; j++) {
                if (grid[i][j] == -1) continue;
                int val = 0;
                val += (grid[i][j - 1] == -1) ? 0 : grid[i][j - 1];
                val += (grid[i - 1][j] == -1) ? 0 : grid[i - 1][j];
                grid[i][j] = val % mod;
            }
        }

        return grid[r][c];
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    mems(grid, -1);
    cin >> r >> c;

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            char ch; cin >> ch;
            if (ch == '#') grid[i][j] = -1;
            else grid[i][j] = 0;
        }

    cout << sol.solve1() << nl;
    // cout << sol.solve2() << nl;

    // for (int i = 1; i <= r; i++) {
    //     for (int j = 1; j <= c; j++) {
    //         cout << grid[i][j] << sp;
    //     }
    //     cout << nl;
    // }


    return 0;
}

