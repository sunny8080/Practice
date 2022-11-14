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

int n;
string s;
int dp[3005][3005];

class Solution {

public:
    void solve() {
        // dp[i][g] : Number of ways to fill position [i ... N] such that, we have g number greater thatn number at 
        // (i-1)th place
        // total = n-i+1 // g + sm // (greater + smaller)
        // so, sm = total - g 


        dp[n][0] = (s[n - 2] == '>') ? 1 : 0;
        dp[n][1] = (s[n - 2] == '<') ? 1 : 0;

        for (int i = n - 1; i >= 2; i--) {
            int total = n - i + 1;

            for (int g = 0; g <= total; g++) {
                int sm = total - g;

                if (g == 0) {
                    dp[i][g] = 0;
                    if (s[i - 2] == '<') continue;

                    for (int j = 1; j <= sm; j++) {
                        dp[i][g] = (dp[i][g] + dp[i + 1][sm - j]) % mod;
                    }
                } else {
                    if (s[i - 2] == '>')
                        dp[i][g] = (mod + dp[i][g - 1] - dp[i + 1][g - 1]) % mod;
                    else
                        dp[i][g] = (dp[i][g - 1] + dp[i + 1][g - 1]) % mod;
                }
            }
        }
    }

};



int32_t main() {
    fastIO();
    Solution sol;
    mems(dp, 0);

    cin >> n;
    cin >> s;

    sol.solve();

    int ans = 0;
    for (int gr = n - 1; gr >= 0; gr--)
        ans = (ans + dp[2][gr]) % mod;
    cout<<ans<<nl;

    return 0;
}

