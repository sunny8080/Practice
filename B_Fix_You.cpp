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


int n, m;
vector<string> grid;
int dp[105][105];

class Solution {

public:
    // METHOD - 1
    int solve1(int i, int j, int& cnt) {
        if (i == n - 1 && j == m - 1) return dp[i][j] = 1;
        if (i == n || j == m) return -1;

        if (dp[i][j] != -1) return dp[i][j];

        // METHOD -1
        int right = solve1(i, j + 1, cnt);
        int down = solve1(i + 1, j, cnt);
        if (grid[i][j] == 'R' && right == -1) cnt++, grid[i][j] = 'D';
        if (grid[i][j] == 'D' && down == -1) cnt++, grid[i][j] = 'R';

        // METHOD -2
        // if (grid[i][j] == 'R') {
        //     if (solve1(i, j + 1, cnt) == -1) cnt++, grid[i][j] = 'D';
        //     solve1(i + 1, j, cnt);
        // } else {
        //     if (solve1(i + 1, j, cnt) == -1) cnt++, grid[i][j] = 'R';
        //     solve1(i, j + 1, cnt);
        // }

        return dp[i][j] = 1;
    }

    int solve2() {
        int cnt = 0;
        for (int j = 0; j < m; j++) if (grid[n - 1][j] == 'D') cnt++; // bottom most row
        for (int i = 0; i < n; i++) if (grid[i][m - 1] == 'R') cnt++; // right most column
        return cnt;
    }
};



int32_t main() {
    fastIO();
    Solution sol;
    
    wt(t) {
        mems(dp, -1);
        cin >> n >> m;
        grid.resize(n);
        for (auto& x : grid) cin >> x;
        // int cnt = 0;
        // sol.solve1(0, 0, cnt);
        // cout << cnt << nl;

        cout<<sol.solve2()<<nl;
    }



    return 0;
}




