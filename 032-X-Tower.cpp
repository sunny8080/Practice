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
#define fr(t,a,b)        for( int t=(a); t<=(b); t++)

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


struct box {
    int sn;
    int wt;
    int val;
};

int n;
vector<box> v;
int dp[1005][10005];


bool comp(box& a, box& b) {
    return (a.sn + a.wt) > (b.sn + b.wt);
}

class Solution {

public:
    int solve() {
        // dp[i][j] : maximum possible value such that subset [1...i] can stock the boxes such that tower 
        // can withstand with a wt atleast j on top of it
        // ANS :- dp[n-1][0] // 0-based indexing


        sort(all(v), comp);
        for (int j = 0; j <= 10000; j++) {
            if (v[0].sn >= j) dp[0][j] = v[0].val;
            else dp[0][j] = 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 10000; j++) {
                int op1 = dp[i - 1][j];
                int op2 = (v[i].sn >= j) ? (v[i].val + ((j + v[i].wt <= 10000) ? dp[i - 1][j + v[i].wt] : 0)) : 0;
                dp[i][j] = max(op1, op2);
            }
        }
        return dp[n - 1][0];
    }


};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, -1);

    cin >> n;
    v.resize(n);
    fr(i, 0, n - 1) cin >> v[i].wt >> v[i].sn >> v[i].val;
    cout << sol.solve() << nl;

    return 0;
}

