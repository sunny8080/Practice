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

int n;
int a[N], b[N], c[N];
int dp[N][5];


class Solution {

public:
    // Top down
    int solve1(int day, int wrk) {
        if (day == n + 1) return 0;
        if (dp[day][wrk] != -1) return dp[day][wrk];

        int val = 0;
        if (wrk == 1) val += a[day];
        else if (wrk == 2) val += b[day];
        else if (wrk == 3) val += c[day];

        int mx = INT_MIN;
        for (int i = 1; i <= 3; i++) {
            if (wrk != i){
                mx = max(mx, solve1(day+1, i));
            }
        }

        val += mx;
        return dp[day][wrk] = val;
    }


    // bottom up
    int solve2(){
        dp[1][1] = a[1];
        dp[1][2] = b[1];
        dp[1][3] = c[1];

        for( int i=2; i<=n; i++){   
            dp[i][1] = a[i] + max( dp[i-1][2], dp[i-1][3]);
            dp[i][2] = b[i] + max( dp[i-1][1], dp[i-1][3]);
            dp[i][3] = c[i] + max( dp[i-1][1], dp[i-1][2]);
        }

        return max({dp[n][1], dp[n][2], dp[n][3]});
    }
};



int32_t main() {
    fastIO();
    Solution sol;

    mems(dp, -1);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    // int op1 = sol.solve1(1, 1);
    // int op2 = sol.solve1(1, 2);
    // int op3 = sol.solve1(1, 3);
    // cout<<max({op1, op2, op3})<<nl;

    cout<<sol.solve2()<<nl;

    return 0;
}

