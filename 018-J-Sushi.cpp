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


double dp[305][305][305];
int n;

class Solution {

public:
    double solve(int x, int y, int z) {
        if (x < 0 || y < 0 || z < 0) return 0;
        if (!x && !y && !z) return 0;
        if (dp[x][y][z] > -0.9) return dp[x][y][z];

        double exp = n + x * solve(x - 1, y, z) + y * solve(x + 1, y - 1, z) + z * solve(x, y + 1, z - 1);
        return dp[x][y][z] = (double)exp / (x + y + z);
    }
};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, -1);

    cin >> n;
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) one++;
        else if (x == 2) two++;
        else three++;
    }

    double ans = sol.solve(one, two, three);
    cout << fixed << setprecision(10) << ans << nl;



    return 0;
}

