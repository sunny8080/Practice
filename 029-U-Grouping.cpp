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
int dp[(1 << 16)];
int sums[(1 << 16)];
int score[17][17];

class Solution {
    bool isSet(int n, int i) {
        return (n & (1 << i));
    }

    int cal(int mask) {
        int ans = 0;
        for (int i = 0; i < 17; i++) {
            for (int j = i + 1; j < 17; j++) {
                if (isSet(mask, i) && isSet(mask, j)) {
                    ans += score[i][j];
                }
            }
        }
        return ans;
    }


public:
    void calSums() {
        for (int subset = 1; subset < (1 << n); subset++) dp[subset] = inf;

        for (int subset = 1; subset < (1 << n); subset++) {
            sums[subset] = cal(subset);
        }
    }


    // SC :- O(2^N)
    // TC : sum(16Ci * (2^i)) over all i // i is no of set bits in mask
    int solve(int mask) {
        // dp[s] : maximum score acheivable from set s
        if (mask == 0) return 0;
        if (dp[mask] != inf) return dp[mask];

        int ans = 0;
        for (int submask = mask; submask != 0; submask = (submask - 1) & mask) {
            ans = max(ans, sums[submask] + solve(mask ^ submask)); // mask^submask : mask - submask
        }

        return dp[mask] = ans;
    }

};



int32_t main() {
    fastIO();
    Solution sol;

    cin >> n;
    fr(i, 0, n - 1)
        fr(j, 0, n - 1)
        cin >> score[i][j];

    sol.calSums();
    cout << sol.solve((1 << n) - 1) << nl;




    return 0;
}

